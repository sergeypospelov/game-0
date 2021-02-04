//
// Created by pospelov on 04.02.2021.
//

#ifndef GUI_BUILDER__GAME_HPP_
#define GUI_BUILDER__GAME_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <vector>
#include <queue>
#include <functional>


#include "engine/Engine.hpp"
#include "graphics/Graphics.hpp"
#include "Settings.hpp"



class Game : sf::NonCopyable {
 private:
  Engine engine;
  Graphics graphics;
  Settings settings;

  bool isRunning = false;



  std::queue<std::function<void(Game &)>> gameEventsQ;
  Game(const Settings &s);

  static Game *instance;

 public:

  static Game &initInstance(const Settings &s);

  static Game &getInstance();

  static void destroy(); // deletes instance

  void addEvent(const std::function<void(Game &)> &f) {
    gameEventsQ.push(f);
  }

  void processGameEvents();

  void stop();

  void run();
};

#endif//GUI_BUILDER__GAME_HPP_
