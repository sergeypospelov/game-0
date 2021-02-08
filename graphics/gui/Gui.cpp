//
// Created by pospelov on 04.02.2021.
//

#include "Gui.hpp"
#include "Clickable.hpp"
#include "views/TextView.hpp"
#include <graphics/gui/views/Button.hpp>
#include <iostream>

Gui::Gui(sf::RenderWindow &window) : window(window), wView(window.getDefaultView()) {

  auto text = std::make_shared<TextView>("AFK Button is not pressed!");
  text->setCenter(300, 100);


  addObject(text);




  auto button = std::make_shared<Button>("Press me!", sf::FloatRect(0, 0, 300, 70));
  button->setOnClickListener([text](Clickable *) { text->setText("Pressed!"); });
  button->setOnHoverChangeListener([button](Hoverable *view, bool hover) {
    if (hover) {
      button->setBoxColor(sf::Color(255, 255, 255, 32));
    } else {
      button->setBoxColor(sf::Color(255, 255, 255, 64));
    }
  });

  addObject(button);
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
  if (view->isFocusable()) {
    focusableViews.push_back(std::dynamic_pointer_cast<Focusable>(view));
  }
}

void Gui::processEvent(sf::Event event) {
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