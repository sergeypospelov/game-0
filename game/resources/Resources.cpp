//
// Created by pospelov on 08.02.2021.
//

#include "Resources.hpp"


const sf::Color Resources::Colors::Orange200 = sf::Color(0xFFCC80FF);
const sf::Color Resources::Colors::Indigo300 = sf::Color(0x7986CBFF);
const sf::Color Resources::Colors::LightGreen50 = sf::Color(0xF1F8E900);
const sf::Color Resources::Colors::Cyan50 = sf::Color(0xE0F7FAFF);
const sf::Color Resources::Colors::Cyan500 = sf::Color(0x00BCD4FF);

Resources::Resources() {
  load_fonts();
  load_textures();
}
const sf::Font &Resources::getFont(Font font) const {
  return fonts[font];
}
const sf::Texture &Resources::getTextures(Texture texture) const {
  return textures[texture];
}
void Resources::load_fonts() {
  const static std::vector<std::string> fileNames = {
    "8bit.ttf",
    "Cartoon.ttf",
    "Courier.ttf",
    "Libre.ttf",
    "Tower.ttf"
  };
  fonts.resize(fileNames.size());
  for (int i = 0; i < fonts.size(); i++) {
    fonts[i].loadFromFile("./resources/fonts/" + fileNames[i]);
  }
}
void Resources::load_textures() {
  const static std::vector<std::string> fileNames = {
    "screens/title.jpg",
  };
  textures.resize(fileNames.size());
  for (int i = 0; i < textures.size(); i++) {
    textures[i].loadFromFile("./resources/textures/" + fileNames[i]);
  }
}
