cmake_minimum_required(VERSION 3.17)
project(gui_builder)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5 COMPONENTS system graphics audio REQUIRED)

add_executable(gui_builder main.cpp world/World.cpp game/Game.cpp game/settings/Settings.cpp graphics/Graphics.cpp graphics/gui/View.cpp graphics/gui/Gui.cpp graphics/renderer/Renderer.cpp graphics/gui/views/TextView.cpp graphics/gui/Hoverable.cpp graphics/gui/Clickable.cpp graphics/gui/views/Button.cpp graphics/gui/views/Button.hpp game/state/State.cpp game/state/StateStack.cpp game/context/Context.cpp)

target_include_directories(gui_builder PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(gui_builder sfml-system sfml-graphics sfml-audio)

