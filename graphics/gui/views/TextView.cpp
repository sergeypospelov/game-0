//
// Created by pospelov on 04.02.2021.
//

#include <iostream>

#include "TextView.hpp"

const std::string TextView::fontFile[] = {
  "8bit.ttf",
  "Cartoon.ttf",
  "Courier.ttf",
  "Libre.ttf",
  "Tower.ttf"
};

TextView::TextView(const std::string &text, float x, float y, int fontSize, const sf::Color &color, const Font fontType) : x(x), y(y) {
  if (!font.loadFromFile("./resources/fonts/" + fontFile[fontType])) {
    std::cerr << "Can't load font!";
  }

  textHolder.setFont(font);
  textHolder.setString(text);
  setCenter(x, y);
  textHolder.setFillColor(color);
  textHolder.setCharacterSize(fontSize);
}

void TextView::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(textHolder, states);
}
bool TextView::contains(float posX, float posY) const {
  return textHolder.getGlobalBounds().contains(posX, posY);
}
std::string TextView::getText() const {
  return textHolder.getString();
}
void TextView::setText(const std::string &text) {
  textHolder.setString(text);
  setCenter(x, y);
}
void TextView::setFontSize(int size) {
  textHolder.setCharacterSize(size);
}
void TextView::setCenter(float x_, float y_) {
  x = x_;
  y = y_;
  const sf::FloatRect &kRect = textHolder.getLocalBounds();
  textHolder.setPosition(x - kRect.width / 2 - kRect.left, y - kRect.height / 2 - kRect.top);
}
void TextView::setColor(const sf::Color &color) {
  textHolder.setFillColor(color);
}
