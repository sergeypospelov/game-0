//
// Created by pospelov on 08.02.2021.
//

#include "State.hpp"
#include "StateStack.hpp"

void State::requestStackPush(States::ID stateID) {
  stack.pushState(stateID);
}

void State::requestStackPop() {
  stack.popState();
}

void State::requestStackClear() {
  stack.clearStates();
}
