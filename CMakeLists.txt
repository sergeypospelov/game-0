cmake_minimum_required(VERSION 3.17)
project(gui_builder)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5 COMPONENTS system graphics audio REQUIRED)

add_executable(gui_builder main.cpp engine/Engine.cpp game/Game.cpp game/Settings.cpp graphics/Graphics.cpp graphics/gui/View.cpp graphics/gui/Gui.cpp graphics/renderer/Renderer.cpp graphics/gui/TextView.cpp graphics/gui/Hoverable.cpp graphics/gui/Hoverable.hpp graphics/gui/Focusable.cpp graphics/gui/Focusable.hpp graphics/gui/Clickable.cpp graphics/gui/Clickable.hpp)

target_include_directories(gui_builder PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(gui_builder sfml-system sfml-graphics sfml-audio)

