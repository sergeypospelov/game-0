//
// Created by pospelov on 08.02.2021.
//

#include "Context.hpp"
Context::Context(sf::RenderWindow &window, std::vector<sf::Font> &fonts, std::vector<sf::Texture> &texture, Settings &settings) : window(window), fonts(fonts), texture(texture), settings(settings) {}
