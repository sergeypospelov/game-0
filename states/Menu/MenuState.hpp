//
// Created by pospelov on 08.02.2021.
//

#ifndef GUI_BUILDER_STATES_MENU_MENUSTATE_HPP_
#define GUI_BUILDER_STATES_MENU_MENUSTATE_HPP_

#include "game/state/State.hpp"
#include "graphics/gui/Gui.hpp"

class MenuState : public State {
 private:
  Gui gui;
 public:
  MenuState(StateStack &stack, const Context &context);
  bool update(sf::Time dt) override;
  bool handleEvent(const sf::Event &event) override;
  void render() override;


};

#endif//GUI_BUILDER_STATES_MENU_MENUSTATE_HPP_
