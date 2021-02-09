//
// Created by pospelov on 08.02.2021.
//

#ifndef GUI_BUILDER_STATES_TITLE_TITLESTATE_HPP_
#define GUI_BUILDER_STATES_TITLE_TITLESTATE_HPP_

#include "game/state/State.hpp"
#include "graphics/gui/views/TextView.hpp"

class TitleState : public State {
 private:
  const std::string text = "press any key to continue...";
  sf::Time curTime;
  const sf::Time fullTime = sf::seconds(2);

  sf::Sprite background;

  TextView textView = TextView(getContext(), text, 400, 200, 80);
 public:
  TitleState(StateStack &stack, const Context &context);

  bool update(sf::Time dt) override;
  bool handleEvent(const sf::Event &event) override;
  void render() override;
};

#endif//GUI_BUILDER_STATES_TITLE_TITLESTATE_HPP_
