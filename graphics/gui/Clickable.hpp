//
// Created by pospelov on 04.02.2021.
//

#ifndef GUI_BUILDER_GRAPHICS_GUI_CLICKABLE_HPP_
#define GUI_BUILDER_GRAPHICS_GUI_CLICKABLE_HPP_

#include "View.hpp"

class Clickable : virtual public View {
 private:
  std::function<void(Clickable *)> onClickListener;

 public:
  void setOnClickListener(const std::function<void(Clickable *)> &on_click_listener);

 public:
  bool isClickable() const final;

  void onClick() {
    if (onClickListener) {
      onClickListener(this);
    }
  }
};

#endif//GUI_BUILDER_GRAPHICS_GUI_CLICKABLE_HPP_
