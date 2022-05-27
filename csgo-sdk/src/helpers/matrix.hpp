//
// csgo sdk
//

#pragma once

#include <array>

template <class t, std::size_t r, std::size_t c>
using matrix_t = std::array<std::array<t, c>, r>;