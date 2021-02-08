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
  explicit Button(Context context, const std::string &text = "",
         sf::FloatRect rect = sf::FloatRect(0, 0, 200, 100),
         sf::Color bColor = sf::Color(128, 128, 128, 128),
         sf::Color tColor = sf::Color::White,
         int fontSize = 40,
         Resources::Font fontType = Resources::Font::Bit);

  bool contains(float x, float y) const override;

  void setBoxColor(sf::Color color);

  sf::Color getBoxColor() const;

  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif//GUI_BUILDER_GRAPHICS_GUI_VIEWS_BUTTON_HPP_
