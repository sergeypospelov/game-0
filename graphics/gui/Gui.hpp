//
// Created by pospelov on 04.02.2021.
//

#ifndef GUI_BUILDER_GRAPHICS_GUI_GUI_HPP_
#define GUI_BUILDER_GRAPHICS_GUI_GUI_HPP_

#include <SFML/Graphics.hpp>

#include <memory>

#include "View.hpp"

class Gui : sf::NonCopyable {
 private:
  sf::RenderWindow &window;

  sf::View wView;

  std::vector<std::shared_ptr<View>> views;
  std::vector<std::shared_ptr<View>> hoverableViews;
  std::vector<std::shared_ptr<View>> focusableViews;
  std::vector<std::shared_ptr<View>> clickableViews;

 public:
  Gui(sf::RenderWindow &window);

  void addObject(const std::shared_ptr<View>& view);

  void render();
};

#endif//GUI_BUILDER_GRAPHICS_GUI_GUI_HPP_
