//
// Created by pospelov on 04.02.2021.
//

#include "Game.hpp"

#include "states/Title/TitleState.hpp"
#include "states/Menu/MenuState.hpp"

Game *Game::instance = nullptr;

Game::Game(Settings s) : settings(s),
                         window(settings.videoMode, "Game", s.windowStyle),
                         resources(),
                         context(window, resources, settings),
                         stateStack(context) {
  registerStates();
}

void Game::run() {
  const sf::Time TIME_PER_FRAME = settings.TIME_PER_FRAME;

  stateStack.pushState(States::Title);
  stateStack.update(sf::seconds(0));

  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;

  sf::Event event{};

  while (!stateStack.isEmpty()) {
    timeSinceLastUpdate += clock.restart();
    while (timeSinceLastUpdate > TIME_PER_FRAME) {
      timeSinceLastUpdate -= TIME_PER_FRAME;

      while (window.pollEvent(event)) {
        stateStack.handleEvent(event);
      }
      stateStack.update(TIME_PER_FRAME);
      processGameEvents();
    }

    window.clear();
    stateStack.render();
    window.display();
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
  stateStack.clearStates();
}

void Game::destroy() {
  instance->stop();
  delete instance;
}

Game &Game::getInstance() {// returns instance
  return *instance;
}

Game &Game::initInstance(Settings s) {// creates instance
  instance = new Game(s);
  return *instance;
}

void Game::addEvent(const std::function<void(Game &)> &f) {
  gameEventsQ.push(f);
}

void Game::registerStates() {
  stateStack.registerState<MenuState>(States::Menu);
  stateStack.registerState<TitleState>(States::Title);
}
