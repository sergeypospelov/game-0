//
// Created by pospelov on 04.02.2021.
//

#ifndef GUI_BUILDER_GRAPHICS_GUI_HOVERABLE_HPP_
#define GUI_BUILDER_GRAPHICS_GUI_HOVERABLE_HPP_

#include "View.hpp"

class Hoverable : public virtual View {
  std::function<void(Hoverable *, bool)> onHoverChangeListener;

 public:
  void setOnHoverChangeListener(const std::function<void(Hoverable *, bool)> &on_hover_change_listener);

 public:
  bool isHoverable() const final;

  void onHover(bool hover);
};

#endif//GUI_BUILDER_GRAPHICS_GUI_HOVERABLE_HPP_
