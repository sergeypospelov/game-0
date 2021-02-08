//
// Created by pospelov on 08.02.2021.
//

#ifndef GUI_BUILDER_GAME_STATE_STATESTACK_HPP_
#define GUI_BUILDER_GAME_STATE_STATESTACK_HPP_

#include <SFML/Graphics.hpp>

#include <map>
#include <vector>
#include <cassert>

#include "State.hpp"
#include "StatesIdentifiers.hpp"

class StateStack : sf::NonCopyable, public sf::Drawable {
 public:
  enum Action {
    Push,
    Pop,
    Clear
  };

 public:

  explicit StateStack(Context context);

  template <typename T>
  void registerState(States::ID stateID);

  void update(sf::Time dt);

  void handleEvent(const sf::Event &event);

  void pushState(States::ID stateID);
  void popState();;

  void clearStates();

  bool isEmpty() const;

  Context getContext() const;

 private:

  State::Ptr createState(States::ID stateID);

  void applyPendingChanges();

 private:
  struct PendingChange {
    Action action;
    States::ID stateID;
  };

 private:
  Context context;

  std::vector<State::Ptr> stack;
  std::vector<PendingChange> pendingList;
  std::map<States::ID, std::function<State::Ptr()>> factories;
};

#endif//GUI_BUILDER_GAME_STATE_STATESTACK_HPP_
