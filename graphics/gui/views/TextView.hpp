//
// Created by pospelov on 04.02.2021.
//

#ifndef GUI_BUILDER_GRAPHICS_GUI_TEXTVIEW_HPP_
#define GUI_BUILDER_GRAPHICS_GUI_TEXTVIEW_HPP_

#include <string>

#include "graphics/gui/View.hpp"

class TextView : virtual public View {
 protected:
  sf::Font font;
  float x, y;
  sf::Text textHolder;

 public:
  explicit TextView(Context context, const std::string &text = "", float x = 0, float y = 0, int font_size = 40, const sf::Color &color = sf::Color::White, Resources::Font font_type = Resources::Font::Bit);

  std::string getText() const;

  void setText(const std::string &text);

  void setFontSize(int size);

  void setColor(const sf::Color &color);

  sf::Color getColor() const;;

  void setCenter(float x_, float y_);

  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  bool contains(float posX, float posY) const override;
};

#endif//GUI_BUILDER_GRAPHICS_GUI_TEXTVIEW_HPP_
