# cmake minimum version
cmake_minimum_required(VERSION 3.0)

# enable c++17
set(CMAKE_CXX_STANDARD 17)

# project name
project(malua)

# include directories (including fgui library includes)
include_directories(${CMAKE_SOURCE_DIR}/src)

# gcc flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# source files
add_library(malua SHARED

    #
    src/FGUI/widgets/button.cpp
    src/FGUI/widgets/checkbox.cpp
    src/FGUI/widgets/colorpicker.cpp
    src/FGUI/widgets/combobox.cpp
    src/FGUI/widgets/container.cpp
    src/FGUI/widgets/itemselector.cpp
    src/FGUI/widgets/keybinder.cpp
    src/FGUI/widgets/label.cpp
    src/FGUI/widgets/listbox.cpp
    src/FGUI/widgets/multibox.cpp
    src/FGUI/widgets/slider.cpp
    src/FGUI/widgets/tabpanel.cpp
    src/FGUI/widgets/textbox.cpp
    src/FGUI/widgets/widgets.cpp

    #
    src/main.cpp
)
