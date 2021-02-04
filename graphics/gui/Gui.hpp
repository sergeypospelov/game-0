//
// Created by pospelov on 04.02.2021.
//

#ifndef GUI_BUILDER_GRAPHICS_GUI_GUI_HPP_
#define GUI_BUILDER_GRAPHICS_GUI_GUI_HPP_

#include <SFML/Graphics.hpp>

class Gui : sf::NonCopyable {
 private:
  sf::RenderWindow &window;

  sf::View view;

 public:
  Gui(sf::RenderWindow &window);

  void render();
};

#endif//GUI_BUILDER_GRAPHICS_GUI_GUI_HPP_
