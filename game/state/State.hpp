//
// Created by pospelov on 08.02.2021.
//

#ifndef GUI_BUILDER_GAME_STATE_HPP_
#define GUI_BUILDER_GAME_STATE_HPP_

#include <SFML/Graphics.hpp>
#include <memory>

#include "game/context/Context.hpp"

#include "states/StatesIdentifiers.hpp"

class StateStack;

class State {
 public:
  typedef std::shared_ptr<State> Ptr;

 private:
  StateStack &stack;
  Context context;

 public:
  State(StateStack &stack, Context context) : stack(stack), context(context) {};

  /*
   *  returns false if another states don't need to update,
   *  otherwise returns true
   */
  virtual bool update(sf::Time dt) = 0;
  /*
   *  returns false if another states don't need to handle event,
   *  otherwise returns true
   */
  virtual bool handleEvent(const sf::Event &event) = 0;
  virtual void render() = 0;

 protected:
  void requestStackPush(States::ID stateID);
  void requestStackClear();
  void requestStackPop();
  Context getContext();;
};

#endif//GUI_BUILDER_GAME_STATE_HPP_
