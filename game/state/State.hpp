//
// Created by pospelov on 08.02.2021.
//

#ifndef GUI_BUILDER_GAME_STATE_HPP_
#define GUI_BUILDER_GAME_STATE_HPP_

#include <SFML/Graphics.hpp>
#include <memory>

#include "game/context/Context.hpp"

#include "StatesIdentifiers.hpp"

class StateStack;

class State : sf::Drawable {
 public:
  typedef std::shared_ptr<State> Ptr;

 private:
  StateStack &stack;
  Context context;

 public:
  State(StateStack &stack, Context context) : stack(stack), context(context) {};

  virtual bool update(sf::Time dt) = 0;
  virtual bool handleEvent(const sf::Event &event) = 0;

 protected:
  void requestStackPush(States::ID stateID);
  void requestStackClear();
  void requestStackPop();
};

#endif//GUI_BUILDER_GAME_STATE_HPP_
