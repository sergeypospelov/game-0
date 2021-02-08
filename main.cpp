#include <iostream>

#include "game/Game.hpp"

int main() {
  Settings s(sf::VideoMode::getDesktopMode(), sf::Style::Default);
  Game::initInstance(s);
  Game::getInstance().run();
  Game::destroy();
}