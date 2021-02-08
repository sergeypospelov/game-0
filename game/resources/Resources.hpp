//
// Created by pospelov on 08.02.2021.
//

#ifndef GUI_BUILDER_GAME_RESOURCES_RESOURCES_HPP_
#define GUI_BUILDER_GAME_RESOURCES_RESOURCES_HPP_

#include <vector>

#include <SFML/Graphics.hpp>

class Resources : sf::NonCopyable {
 public:
  enum Font {
    Bit = 0,
    Cartoon = 1,
    Courier = 2,
    Libre = 3,
    Tower = 4
  };
  enum Texture {

  };
  struct Colors {
    const static sf::Color Orange200;
    const static sf::Color Indigo300;
    const static sf::Color LightGreen50;
    const static sf::Color Cyan50;
  };

 private:
  std::vector<sf::Font> fonts;
  std::vector<sf::Texture> textures;


 public:

  Resources();

  const sf::Font &getFont(Font font) const;
  const sf::Texture &getTextures(Texture texture) const;


 private:
  void load_fonts();

  void load_textures();
};

#endif//GUI_BUILDER_GAME_RESOURCES_RESOURCES_HPP_
