//
// Created by pospelov on 04.02.2021.
//

#include "Graphics.hpp"

#include "game/Game.hpp"


Graphics::Graphics(const sf::VideoMode &videoMode, const int windowStyle) : window(videoMode, "Game", windowStyle), gui(window), renderer(window) {}

void Graphics::render() {
  window.clear();

  renderer.render();
  gui.render();

  window.display();
}

void Graphics::update(const sf::Time &time) {
  gui.update(time);
  renderer.update(time);
}

void Graphics::processEvents() {
  while (window.pollEvent(ev_)) {
    switch (ev_.type) {
      case sf::Event::EventType::Closed:
        Game::getInstance().addEvent([](Game &game) { game.stop(); });
        break;
      default:
        renderer.processEvent(ev_);
        gui.processEvent(ev_);
        break;
    }
  }
}
void Graphics::stop() {
  window.close();
}
