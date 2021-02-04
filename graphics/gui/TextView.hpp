//
// Created by pospelov on 04.02.2021.
//

#ifndef GUI_BUILDER_GRAPHICS_GUI_TEXTVIEW_HPP_
#define GUI_BUILDER_GRAPHICS_GUI_TEXTVIEW_HPP_

#include <string>

#include "View.hpp"

class TextView : virtual public View {

  sf::Font font;
  std::string text;

  int fontSize;
  int x, y;

  sf::Text textHolder;

 public:
  TextView(const std::string &text, float x, float y, const sf::Color &color, int font_size);
//  TextView(const std::string &text, int font_size, int x, int y);

 public:

  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif//GUI_BUILDER_GRAPHICS_GUI_TEXTVIEW_HPP_
