//
// Created by pospelov on 04.02.2021.
//

#ifndef GUI_BUILDER_ENGINE_ENGINE_HPP_
#define GUI_BUILDER_ENGINE_ENGINE_HPP_

#include <SFML/System/Time.hpp>
class Engine {
 public:
  void update(const sf::Time time);
  void stop();
};

#endif//GUI_BUILDER_ENGINE_ENGINE_HPP_
