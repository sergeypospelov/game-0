//
// Created by pospelov on 08.02.2021.
//

#include "StateStack.hpp"
State::Ptr StateStack::createState(States::ID stateID) {
  auto state = factories[stateID];
  assert(state); // state constructor in lambda
  return state();
}

void StateStack::update(sf::Time dt) {
  for (auto itr = stack.rbegin(); itr != stack.rend(); itr++) {
    if (!itr->get()->update(dt)) {
      break;
    }
  }
  applyPendingChanges();
}
void StateStack::handleEvent(const sf::Event &event) {
  for (auto itr = stack.rbegin(); itr != stack.rend(); itr++) {
    if (!itr->get()->handleEvent(event)) {
      break;
    }
  }
  applyPendingChanges();
}
void StateStack::clearStates() {
  pendingList.push_back( { Action::Clear });
}
void StateStack::pushState(States::ID stateID) {
  pendingList.push_back( {Action::Push, stateID });
}
void StateStack::popState() {
  pendingList.push_back( { Action::Pop });
}
bool StateStack::isEmpty() const {
  return stack.empty();
}
Context StateStack::getContext() const {
  return context;
}
void StateStack::applyPendingChanges() {
  for (auto &i : pendingList) {
    switch (i.action) {
      case Action::Push:
        stack.push_back(createState(i.stateID));
        break;
      case Action::Pop:
        stack.pop_back();
        break;
      case Action::Clear:
        stack.clear();
        break;
    }
  }
  pendingList.clear();
}
StateStack::StateStack(Context context) : context(context) {}

void StateStack::render() const {
  for (auto it : stack) {
    it->render();
  }
}
