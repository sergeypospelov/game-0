//
// Created by pospelov on 04.02.2021.
//

#ifndef GUI_BUILDER_GRAPHICS_GUI_VIEWS_BUTTON_HPP_
#define GUI_BUILDER_GRAPHICS_GUI_VIEWS_BUTTON_HPP_

#include "TextView.hpp"
#include "graphics/gui/Clickable.hpp"
#include "graphics/gui/Hoverable.hpp"

class Button : public TextView, public Clickable, public Hoverable {
  const float offset = 20;
  sf::RectangleShape box;

 public:
  Button(const std::string &text = "",
         sf::FloatRect rect = sf::FloatRect(0, 0, 200, 100),
         sf::Color bColor = sf::Color(255, 255, 255, 64),
         sf::Color tColor = sf::Color::White,
         int fontSize = 40,
         TextView::Font fontType = TextView::Font::Bit)
      : TextView(text, 0, 0, fontSize, tColor, fontType) {
    box.setPosition(rect.left, rect.top);
    box.setSize(sf::Vector2f(rect.width, rect.height));
    TextView::setCenter(box.getPosition().x + box.getSize().x / 2, box.getPosition().y + box.getSize().y / 2);
    box.setFillColor(bColor);
  }
  bool contains(float x, float y) const override {
    return box.getGlobalBounds().contains(x, y);
  }

  void setBoxColor(sf::Color color) {
    box.setFillColor(color);
  }

  void draw(sf::RenderTarget &target, sf::RenderStates states) const override {
    target.draw(box, states);
    TextView::draw(target, states);
  }
};

#endif//GUI_BUILDER_GRAPHICS_GUI_VIEWS_BUTTON_HPP_
