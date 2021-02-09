#include <iostream>

#include "game/Game.hpp"

int main() {
  Settings s(sf::VideoMode::getDesktopMode(), sf::Style::Fullscreen);
  Game game(s);
  game.run();
}