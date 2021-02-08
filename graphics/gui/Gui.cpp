//
// Created by pospelov on 04.02.2021.
//

#include "Gui.hpp"
#include "Clickable.hpp"
#include "views/TextView.hpp"
#include <graphics/gui/views/Button.hpp>
#include <iostream>

Gui::Gui(sf::RenderWindow &window) : window(window), wView(window.getDefaultView()) {
}

void Gui::render() {
  window.setView(wView);

  for (auto &v : views) {
    window.draw(*v);
  }
}

void Gui::addObject(const std::shared_ptr<View> &view) {
  views.push_back(view);
  if (view->isClickable()) {
    clickableViews.push_back(std::dynamic_pointer_cast<Clickable>(view));
  }
  if (view->isHoverable()) {
    hoverableViews.push_back(std::dynamic_pointer_cast<Hoverable>(view));
  }
}

void Gui::handleEvent(sf::Event event) {
  switch (event.type) {
    case sf::Event::MouseButtonPressed:
      mouseButtonPressed(event.mouseButton);
      break;
    case sf::Event::MouseMoved:
      mouseButtonMoved(event.mouseMove);
      break;
    default:
      break;
  }
}

void Gui::mouseButtonPressed(sf::Event::MouseButtonEvent event) {
  for (auto &o : clickableViews) {
    if (o->contains(event.x, event.y)) {
      o->onClick();
    }
  }
}

void Gui::mouseButtonMoved(sf::Event::MouseMoveEvent event) {

}

inline void Gui::updateHover() {
  sf::Vector2i mPos(sf::Mouse::getPosition(window));

  if (hoverOnView) {
    if (hoverOnView->contains(mPos.x, mPos.y)) {
      return;
    } else {
      hoverOnView->onHover(false);
      hoverOnView = nullptr;
    }
  }

  for (auto &o : hoverableViews) {
    bool contains = o->contains(mPos.x, mPos.y);
    if (contains) {
      o->onHover(contains);
      hoverOnView = o;
      return;
    }
  }
}

void Gui::update(const sf::Time &time) {
  updateHover();
}