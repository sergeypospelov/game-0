//
// Created by pospelov on 04.02.2021.
//

#ifndef GUI_BUILDER_GRAPHICS_GUI_GUI_HPP_
#define GUI_BUILDER_GRAPHICS_GUI_GUI_HPP_

#include <SFML/Graphics.hpp>

#include <memory>

#include "Clickable.hpp"
#include "Hoverable.hpp"
#include "View.hpp"

class Gui : sf::NonCopyable {
 private:
  sf::RenderWindow &window;

  sf::View wView;

  std::vector<std::shared_ptr<View>> views;
  std::vector<std::shared_ptr<Hoverable>> hoverableViews;
  std::shared_ptr<Hoverable> hoverOnView = nullptr;
  std::vector<std::shared_ptr<Focusable>> focusableViews;
  std::vector<std::shared_ptr<Clickable>> clickableViews;

  void updateHover();
  void mouseButtonPressed(sf::Event::MouseButtonEvent event);
  void mouseButtonMoved(sf::Event::MouseMoveEvent event);

 public:
  Gui(sf::RenderWindow &window);

  void addObject(const std::shared_ptr<View>& view);

  void render();
  void processEvent(sf::Event event);
  void update(const sf::Time &time);
};

#endif//GUI_BUILDER_GRAPHICS_GUI_GUI_HPP_
