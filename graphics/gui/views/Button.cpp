//
// Created by pospelov on 04.02.2021.
//

#include "Button.hpp"
Button::Button(const std::string &text, sf::FloatRect rect, sf::Color bColor, sf::Color tColor, int fontSize, TextView::Font fontType)
  : TextView(text, 0, 0, fontSize, tColor, fontType) {
  box.setPosition(rect.left, rect.top);
  box.setSize(sf::Vector2f(rect.width, rect.height));
  TextView::setCenter(box.getPosition().x + box.getSize().x / 2, box.getPosition().y + box.getSize().y / 2);
  box.setFillColor(bColor);

  setOnHoverChangeListener([this] (Hoverable *h, bool hover) {
    sf::Color color = this->getBoxColor();
    if (hover) {
      color.a = 64;
      this->setBoxColor(color);
    } else {
      color.a = 128;
      this->setBoxColor(color);
    }
  } );
}
bool Button::contains(float x, float y) const {
  return box.getGlobalBounds().contains(x, y);
}
void Button::setBoxColor(sf::Color color) {
  box.setFillColor(color);
}
sf::Color Button::getBoxColor() const {
  return box.getFillColor();
}
void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(box, states);
  TextView::draw(target, states);
}
