//
// Created by pospelov on 03.02.2021.
//

#ifndef GUI_BUILDER_GUI_FRAGMENT_HPP_
#define GUI_BUILDER_GUI_FRAGMENT_HPP_

#include <SFML/Graphics.hpp>

#include <memory>

/*
 * Simple wView class.
 */

class View : public sf::Drawable {
  bool visible = true;

 public:

  bool isVisible() const;
  void setVisible(bool visible);
  virtual bool isClickable() const;
  virtual bool isHoverable() const;
  virtual bool contains(float x, float y) const = 0;

 public:
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override = 0;
};

#endif//GUI_BUILDER_GUI_FRAGMENT_HPP_
