//
// csgo sdk
//

#pragma once

#include <dlfcn.h>
#include <optional>
#include <string>
#include <vector>
#include <cstring>
#include <link.h>
#include <cstdint>

using create_interface_fn = void *(*)();
using find_hud_element_fn = unsigned long(*)(void*, const char*);

struct interface_registration_t
{
  create_interface_fn m_create;
  const char *m_interface_name;
  interface_registration_t *m_next;
};

struct module_info_t
{
	const char* m_module_name;
	std::uintptr_t m_address;
	std::size_t m_size;
}; std::vector<module_info_t> g_module_info;

inline bool compare( const unsigned char* _pdata, const unsigned char* _pmask, const char* _mask) {

  for (; *_mask; ++_mask, ++_pdata, ++_pmask)
  {
    if (*_mask == 'x' && *_pdata != *_pmask)
    {
      return false;
    }
  }

  return (*_mask) == 0;
}

inline bool get_library_info(const char *_module_name, std::uintptr_t *_address, std::size_t *_size)
{
  if (g_module_info.size() == 0)
  {
    dl_iterate_phdr([](struct dl_phdr_info *_info, std::size_t, void *) {

      module_info_t module_info;

      // module name
      module_info.m_module_name = _info->dlpi_name;

      // module address
      module_info.m_address = _info->dlpi_addr + _info->dlpi_phdr[0].p_vaddr;

      // module size
      module_info.m_size = _info->dlpi_phdr[0].p_memsz;

      g_module_info.push_back(module_info);

      return 0;
    },
                    nullptr);
  }

  for (const module_info_t &module : g_module_info)
  {
    // check if the module that we're trying to scan exists
    if (!strcasestr(module.m_module_name, _module_name))
    {
      continue;
    }

    // get the address of the module
    if (_address)
    {
      *_address = module.m_address;
    }

    // get module size
    if (_size)
    {
      *_size = module.m_size;
    }

    return true;
  }

  return false;
}

namespace memory
{
  template <unsigned int index, typename type, typename... arguments>
  inline static type vfunc(void *_thisptr, arguments... _argument_list)
  {
    using fn = type (*)(void *, decltype(_argument_list)...);
    return (*static_cast<fn **>(_thisptr))[index](_thisptr, _argument_list...);
  }

  inline void **&get_vtable(void *_instance, std::uintptr_t _offset = 0x0)
  {
    return *reinterpret_cast<void ***>(reinterpret_cast<std::uintptr_t>(_instance) + _offset);
  }

  inline std::uintptr_t get_absolute_address(std::uintptr_t _pointer, int _offset, std::size_t _size)
  {
    return _pointer + *reinterpret_cast<std::uint32_t *>(_pointer + _offset) + _size;
  }

  template <typename abstract_class>
  inline abstract_class *get_interface(const std::string &_interface_location)
  {
    std::string dll_path, delims = "->";
    std::vector<std::string> splitted_string;

    // split string (tokenize)
    std::string::size_type start = _interface_location.find_first_not_of(delims), end = 0;

    while ((end = _interface_location.find_first_of(delims, start)) != std::string::npos)
    {
      splitted_string.push_back(_interface_location.substr(start, end - start));
      start = _interface_location.find_first_not_of(delims, end);
    }

    if (start != std::string::npos)
    {
      splitted_string.push_back(_interface_location.substr(start));
    }

    // fetch dll path
    if (splitted_string.at(0).find("client_client.so") != std::string::npos)
    {
      dll_path.assign("./csgo/bin/linux64/");
    }
    else
    {
      dll_path.assign("./bin/linux64/");
    }

    // insert dll location
    splitted_string.at(0).insert(0, dll_path);

    // get module handle
    void *module = dlopen(splitted_string.at(0).c_str(), RTLD_NOLOAD | RTLD_NOW | RTLD_LOCAL);

    if (!module)
    {
      return {};
    }

    // get interface regs address
    void* interface_regs_addr = dlsym(module, "s_pInterfaceRegs");

    if (!interface_regs_addr)
    {
      dlclose(module);
      return {};
    }

    // close module handle
    dlclose(module);

    // grab the interface list
    interface_registration_t *interfaces_regs = *reinterpret_cast<interface_registration_t **>(interface_regs_addr);

    // iterate through the interface list and grab the correct interface
    for (interface_registration_t *current = interfaces_regs; current != nullptr; current = current->m_next)
    {
      if (std::string(current->m_interface_name).find(splitted_string.at(1)) != std::string::npos)
      {
        // found interface
        if (std::optional<abstract_class *> interface_found = reinterpret_cast<abstract_class *>(current->m_create()))
        {
          if (interface_found.has_value())
          {
            return interface_found.value();
          }
        }
      }
    }

    splitted_string.clear();

    return {};
  }

  inline std::uint8_t *get_ida_style_signature(const char *_module, const char *_signature)
  {
    static auto pattern_to_byte = [](const char *_pattern) {

		auto bytes = std::vector<int> { };
		auto start = const_cast<char*>(_pattern);
		auto end = const_cast<char*>(_pattern) + std::strlen(_pattern);

      for (auto current = start; current < end; ++current)
      {
        if (*current == '?')
        {
          ++current;

          if (*current == '?')
          {
            ++current;
          }

          bytes.push_back(-1);
        }
        else
        {
          bytes.push_back(std::strtoul(current, &current, 16));
        }
      }

      return bytes;
    };

    std::uintptr_t module_address = 0;
    std::size_t size_of_image = 0;

    // get module info
    get_library_info(_module, &module_address, &size_of_image);

    auto pattern_bytes = pattern_to_byte(_signature);
    auto scanned_bytes = reinterpret_cast<std::uint8_t *>(module_address);

    auto pattern_bytes_size = pattern_bytes.size();
    auto pattern_bytes_data = pattern_bytes.data();

    for (auto i = 0ul; i < (size_of_image - pattern_bytes_size); ++i)
    {
      bool found = true;

      for (auto j = 0ul; j < pattern_bytes_size; ++j)
      {
        if (scanned_bytes[i + j] != pattern_bytes_data[j] && pattern_bytes_data[j] != -1)
        {
          found = false;
          break;
        }
      }

      if (found)
      {
        return &scanned_bytes[i];
      }
    }

    return nullptr;
  }

} // namespace memory