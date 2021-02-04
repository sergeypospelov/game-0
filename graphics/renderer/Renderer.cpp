//
// Created by pospelov on 04.02.2021.
//

#include "Renderer.hpp"
Renderer::Renderer(sf::RenderWindow &window) : window(window), view(window.getDefaultView()) {
}

void Renderer::render() {
  window.setView(view);
  sf::RectangleShape rect(sf::Vector2f(200, 200));
  rect.setPosition(200, 200);
  rect.setOutlineThickness(10);
  rect.setOutlineColor(sf::Color::Yellow);
  rect.setFillColor(sf::Color(255, 255, 255, 128));

  window.draw(rect);
}
