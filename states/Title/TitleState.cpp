//
// Created by pospelov on 08.02.2021.
//

#include "TitleState.hpp"
bool TitleState::update(sf::Time dt) {
  curTime += dt;
  if (curTime >= fullTime) {
    curTime = sf::Time::Zero;
  }
  sf::Color color = textView.getColor();
  color.a = (int)(255 * std::abs(1 - curTime.asSeconds()));
  textView.setColor(color);
  return true;
}
bool TitleState::handleEvent(const sf::Event &event) {
  switch (event.type) {
    case sf::Event::EventType::KeyPressed:
      requestStackPop();
      requestStackPush(States::Menu);
      break;
    case sf::Event::Closed:
      requestStackClear();
      break;
    default:
      break;
  }
  return true;
}
void TitleState::render() {
  getContext().window.draw(textView);
}
TitleState::TitleState(StateStack &stack, const Context &context) : State(stack, context) {}
