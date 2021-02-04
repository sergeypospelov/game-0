//
// Created by pospelov on 03.02.2021.
//



#include "View.hpp"

bool View::isFocusable() const {
  return false;
}
bool View::isVisible() const {
  return visible;
}
void View::setVisible(bool visible) {
  View::visible = visible;
}
bool View::isClickable() const {
  return false;
}
bool View::isHoverable() const {
  return false;
}