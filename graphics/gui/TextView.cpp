//
// Created by pospelov on 04.02.2021.
//

#include <iostream>

#include "TextView.hpp"

TextView::TextView(const std::string &text, float x, float y, const sf::Color &color, int fontSize) : text(text), x(x), y(y), fontSize(fontSize) {

  if (!font.loadFromFile("./resources/fonts/8bit.ttf")) {
    std::cerr << "Bad font!";
  }
/*
  textHolder.setStyle(textHolder.Italic);
*/
/*
  textHolder.setOutlineThickness(2.f);
  textHolder.setOutlineColor(sf::Color::Green);
*/
  textHolder.setFont(font);
  textHolder.setString(text);
  textHolder.setPosition(x, y);
  textHolder.setFillColor(color);
  textHolder.setCharacterSize(fontSize);
}

/*
TextView::TextView(const std::string &text, int x, int y, sf::Color color, int font_size) : TextView(DEFAULT_FONT, text, color, x, y, font_size) {
}
*/

void TextView::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(textHolder, states);
}
