//
// Created by pospelov on 04.02.2021.
//

#include "Clickable.hpp"

bool Clickable::isClickable() const {
  return true;
}
void Clickable::setOnClickListener(const std::function<void(Clickable *)> &on_click_listener) {
  onClickListener = on_click_listener;
}
void Clickable::onClick() {
  if (onClickListener) {
    onClickListener(this);
  }
}
