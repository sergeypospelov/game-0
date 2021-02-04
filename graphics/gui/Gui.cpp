//
// Created by pospelov on 04.02.2021.
//

#include "Gui.hpp"
#include "TextView.hpp"

Gui::Gui(sf::RenderWindow &window) : window(window), wView(window.getDefaultView()) {

  addObject(std::make_shared<TextView>("Hello world!", 100, 100, sf::Color(255, 255, 255, 128), 120));
}

void Gui::render() {
  window.setView(wView);

  for (auto &v : views) {
    window.draw(*v);
  }
}


void Gui::addObject(const std::shared_ptr<View>& view) {
  views.push_back(view);
  if (view->isClickable()) {
    clickableViews.push_back(view);
  }
  if (view->isHoverable()) {
    hoverableViews.push_back(view);
  }
  if (view->isFocusable()) {
    focusableViews.push_back(view);
  }
}
