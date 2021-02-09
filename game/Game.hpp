//
// Created by pospelov on 04.02.2021.
//

#ifndef GUI_BUILDER__GAME_HPP_
#define GUI_BUILDER__GAME_HPP_

#include <SFML/Graphics.hpp>

#include <functional>
#include <iostream>
#include <memory>
#include <queue>
#include <vector>

#include "state/StateStack.hpp"
#include "settings/Settings.hpp"
#include "world/World.hpp"

class Game : sf::NonCopyable {
 private:
  Settings settings;
  Resources resources;
  sf::RenderWindow window;

  /*
   * Variable for common values.
   */
  Context context;

  StateStack stateStack;

  std::queue<std::function<void(Game &)>> gameEventsQ;

 private:

  void registerStates();

  void setGameIcon();

 public:

  explicit Game(Settings s);

  void addEvent(const std::function<void(Game &)> &f);

  void processGameEvents();

  void stop();

  void run();

};

#endif//GUI_BUILDER__GAME_HPP_
