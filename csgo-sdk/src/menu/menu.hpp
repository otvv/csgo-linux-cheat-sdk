//
// csgo sdk
//

#pragma once

// includes
#include <unordered_map>

// fgui library
#define FGUI_IMPLEMENTATION
#include <FGUI/FGUI.hpp>

namespace Widgets
{
  std::shared_ptr<FGUI::CContainer> Container;
  std::shared_ptr<FGUI::CContainer> GroupBox1;
  std::shared_ptr<FGUI::CContainer> GroupBox2;
  std::shared_ptr<FGUI::CComboBox> ComboBox;
  std::shared_ptr<FGUI::CCheckBox> CheckBox;
  std::shared_ptr<FGUI::CCheckBox> CheckBox2;
  std::shared_ptr<FGUI::CColorPicker> ColorPicker;
  std::shared_ptr<FGUI::CTabPanel> TabPanel;
} // namespace Widgets

struct window_t
{
  window_t()
  {
    FGUI::CBuilder builder;

    Widgets::Container = std::make_shared<FGUI::CContainer>();
    builder.Widget(Widgets::Container).Title("Container 1").Position(200, 200).Flag(FGUI::WIDGET_FLAG::LIMIT).Size(735, 435).Key(74).Font("Tahoma Bold", 11, true);
    {
      Widgets::TabPanel = std::make_shared<FGUI::CTabPanel>();
      builder.Widget(Widgets::TabPanel).Position(0, 16).Font("Tahoma Bold", 11, true).Tabs({"Tab 1", "Tab 2", "Tab 3", "Tab 4", "Tab 5"}).SpawnIn(Widgets::Container, false);
      {
        Widgets::GroupBox1 = std::make_shared<FGUI::CContainer>();
        builder.Widget(Widgets::GroupBox1).Title("GroupBox 1").Position(15, 65).Size(290, 165).Font("Tahoma Bold", 11, true).Medium(Widgets::TabPanel, 0).SpawnIn(Widgets::Container, false);
        {
          Widgets::CheckBox = std::make_shared<FGUI::CCheckBox>();
          builder.Widget(Widgets::CheckBox).Title("CheckBox 1").Position(15, 15).Font("Tahoma", 12).SpawnIn(Widgets::GroupBox1);

          Widgets::ColorPicker = std::make_shared<FGUI::CColorPicker>();
          builder.Widget(Widgets::ColorPicker).Title("ColorPicker 1").Position(255, 15).Color({255, 11, 124}).SpawnIn(Widgets::GroupBox1);

          Widgets::ComboBox = std::make_shared<FGUI::CComboBox>();
          builder.Widget(Widgets::ComboBox).Title("ComboBox 1").Position(15, (15 + 25)).Entries({"Entry 1", "Entry 2", "Entry 3", "Entry 4", "Entry 5", "Entry 6", "Entry 7", "Entry 8", "Entry 9", "Entry 10", "Entry 11", "Entry 12", "Entry 13", "Entry 14", "Entry 15"}).Font("Tahoma", 12).SpawnIn(Widgets::GroupBox1);
        }

        Widgets::GroupBox2 = std::make_shared<FGUI::CContainer>();
        builder.Widget(Widgets::GroupBox2).Title("GroupBox 2").Position(315, 65).Size(290, 165).Font("Tahoma Bold", 11, true).Medium(Widgets::TabPanel, 0).SpawnIn(Widgets::Container, false);
        {
          Widgets::CheckBox2 = std::make_shared<FGUI::CCheckBox>();
          builder.Widget(Widgets::CheckBox2).Title("CheckBox 2").Position(15, 15).Font("Tahoma", 12).SpawnIn(Widgets::GroupBox2, false);
        }
      }
    }
  }
};
extern window_t window;