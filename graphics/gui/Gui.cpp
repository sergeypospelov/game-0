//
// Created by pospelov on 04.02.2021.
//

#include "Gui.hpp"

Gui::Gui(sf::RenderWindow &window) : window(window), view(window.getDefaultView()) {
}

void Gui::render() {
  window.setView(view);
  sf::RectangleShape rect(view.getSize());
  rect.setOutlineThickness(-10);
  rect.setOutlineColor(sf::Color::Cyan);
  rect.setFillColor(sf::Color(255, 255, 255, 0));

  window.draw(rect);
}
