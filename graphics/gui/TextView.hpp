//
// Created by pospelov on 04.02.2021.
//

#ifndef GUI_BUILDER_GRAPHICS_GUI_TEXTVIEW_HPP_
#define GUI_BUILDER_GRAPHICS_GUI_TEXTVIEW_HPP_

#include <string>

#include "View.hpp"

class TextView : virtual public View {

 protected:
  sf::Font font;

  float x, y;

  sf::Text textHolder;

 public:
  TextView(const std::string &text, float x, float y, const sf::Color &color, int font_size);
//  TextView(const std::string &text, int font_size, int x, int y);

 public:

  std::string getText() const {
    return textHolder.getString();
  }

  void setText(const std::string &text) {
    textHolder.setString(text);
  }

  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  bool contains(float posX, float posY) const override;
};

#endif//GUI_BUILDER_GRAPHICS_GUI_TEXTVIEW_HPP_
