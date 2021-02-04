//
// Created by pospelov on 04.02.2021.
//

#ifndef GUI_BUILDER_GRAPHICS_GRAPHICS_HPP_
#define GUI_BUILDER_GRAPHICS_GRAPHICS_HPP_

#include "SFML/Graphics.hpp"

#include "renderer/Renderer.hpp"
#include "gui/Gui.hpp"

class Graphics : sf::NonCopyable {
 private:
  sf::RenderWindow window;

  Gui gui;
  Renderer renderer;

  sf::Event ev_;

 public:
  Graphics(const sf::VideoMode &videoMode, int windowStyle);

  void render();
  void update(const sf::Time &time);
  void processEvents();
  void stop();
};

#endif //GUI_BUILDER_GRAPHICS_GRAPHICS_HPP_
