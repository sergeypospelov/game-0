//
// Created by pospelov on 04.02.2021.
//

#include "Hoverable.hpp"
void Hoverable::setOnHoverChangeListener(const std::function<void(Hoverable *, bool)> &on_hover_change_listener) {
  onHoverChangeListener = on_hover_change_listener;
}
bool Hoverable::isHoverable() const { return true; }
void Hoverable::onHover(bool hover) {
  if (onHoverChangeListener) {
    onHoverChangeListener(this, hover);
  }
}
