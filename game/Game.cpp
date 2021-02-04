//
// Created by pospelov on 04.02.2021.
//

#include "Game.hpp"
Game *Game::instance = nullptr;

Game::Game(const Settings &s) : settings(s), graphics(s.videoMode, s.windowStyle) {
}
void Game::run() {
  isRunning = 1;

  const sf::Time TIME_PER_FRAME = settings.TIME_PER_FRAME;

  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;

  while (isRunning) {
    timeSinceLastUpdate += clock.restart();
    while (timeSinceLastUpdate > TIME_PER_FRAME) {
      timeSinceLastUpdate -= TIME_PER_FRAME;
      graphics.processEvents();
      graphics.update(TIME_PER_FRAME);
      engine.update(TIME_PER_FRAME);
      processGameEvents();
    }

    graphics.render();
  }
}

void Game::processGameEvents() {
  while (!gameEventsQ.empty()) {
    std::function<void(Game &)> f = gameEventsQ.front();
    gameEventsQ.pop();
    f(*this);
  }
}

void Game::stop() {
  isRunning = false;
}
void Game::destroy() {
  instance->stop();
  delete instance;
}
Game &Game::getInstance() { // returns instance
  return *instance;
}
Game &Game::initInstance(const Settings &s) { // creates instance
  instance = new Game(s);
  return *instance;
}
