//
// Created by pospelov on 08.02.2021.
//

#include "MenuState.hpp"
#include "graphics/gui/views/Button.hpp"
#include "graphics/gui/views/TextView.hpp"
#include <game/Game.hpp>

bool MenuState::update(sf::Time dt) {
  gui.update(dt);
  return false;
}

bool MenuState::handleEvent(const sf::Event &event) {
  switch (event.type) {
    case sf::Event::EventType::Closed:
      requestStackClear();
      break;
    default:
      break;
  }

  gui.handleEvent(event);
  return false;
}

void MenuState::render() {
  gui.render();
}

MenuState::MenuState(StateStack &stack, const Context &context) : State(stack, context), gui(context.window) {
  auto title = std::make_shared<TextView>(context, "Game!", 250, 50, 120, Resources::Colors::Indigo300, Resources::Font::Tower);
  auto buttonPlay = std::make_shared<Button>(context, "Play", sf::FloatRect(200, 200, 300, 80), Resources::Colors::Cyan500, sf::Color::White, 60,Resources::Font::Bit);
  auto buttonExit = std::make_shared<Button>(context, "Exit", sf::FloatRect(200, 300, 300, 80), Resources::Colors::Cyan500, sf::Color::White, 60,Resources::Font::Bit);

  gui.addObject(title);
  gui.addObject(buttonPlay);
  gui.addObject(buttonExit);

  buttonExit->setOnClickListener([&stack] (Clickable *view) {
    stack.popState();
  });
}
