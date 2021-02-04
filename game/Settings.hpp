//
// Created by pospelov on 04.02.2021.
//

#ifndef GUI_BUILDER_GAME_SETTINGS_HPP_
#define GUI_BUILDER_GAME_SETTINGS_HPP_

#include "SFML/Graphics.hpp"

class Settings {
 public:
  sf::VideoMode videoMode;
  sf::Time TIME_PER_FRAME;
  int windowStyle;

  Settings(const sf::VideoMode &video_mode, int windowStyle = sf::Style::Default, const sf::Time &time_per_frame = sf::seconds(1.f / 60.f));
};

#endif//GUI_BUILDER_GAME_SETTINGS_HPP_
