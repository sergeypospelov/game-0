//
// Created by pospelov on 04.02.2021.
//

#ifndef GUI_BUILDER_GRAPHICS_RENDERER_RENDERER_HPP_
#define GUI_BUILDER_GRAPHICS_RENDERER_RENDERER_HPP_

#include <SFML/Graphics.hpp>

class Renderer : sf::NonCopyable {
 private:
  sf::RenderWindow &window;

  sf::View view;

 public:
  Renderer(sf::RenderWindow &window);

  void render();
  void processEvent(sf::Event event);
  void update(const sf::Time &time);
};

#endif//GUI_BUILDER_GRAPHICS_RENDERER_RENDERER_HPP_
