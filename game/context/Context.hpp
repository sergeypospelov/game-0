//
// Created by pospelov on 08.02.2021.
//

#ifndef GUI_BUILDER_GAME_CONTEXT_CONTEXT_HPP_
#define GUI_BUILDER_GAME_CONTEXT_CONTEXT_HPP_

#include <SFML/Graphics.hpp>

#include "game/settings/Settings.hpp"

struct Context {
  sf::RenderWindow &window;

  std::vector<sf::Font> &fonts;
  std::vector<sf::Texture> &texture;

  Settings &settings;

  Context(sf::RenderWindow &window, std::vector<sf::Font> &fonts, std::vector<sf::Texture> &texture, Settings &settings);
};

#endif//GUI_BUILDER_GAME_CONTEXT_CONTEXT_HPP_
