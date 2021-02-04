//
// Created by pospelov on 04.02.2021.
//

#include "Gui.hpp"
#include "Clickable.hpp"
#include "TextView.hpp"

Gui::Gui(sf::RenderWindow &window) : window(window), wView(window.getDefaultView()) {

  auto text = std::make_shared<TextView>("Button is not pressed!", 100, 100, sf::Color(255, 255, 255, 128), 120);

  addObject(text);

  class Button : public TextView, public Clickable {
   public:
    Button(const std::string& text, float x, float y, sf::Color color, int font_size) :
      TextView(text, x, y, color, font_size)
    {}
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override {
      sf::RectangleShape box;
      box.setSize(sf::Vector2f(textHolder.getGlobalBounds().width, textHolder.getGlobalBounds().height));
      box.setPosition(textHolder.getGlobalBounds().left, textHolder.getGlobalBounds().top);
      box.setFillColor(sf::Color(255, 255, 255, 64));

      target.draw(box, states);
      TextView::draw(target, states);
    }
  };
  auto button = std::make_shared<Button>("Press me!", 100, 300, sf::Color(0, 255, 0, 255), 100);
  button->setOnClickListener([text] (Clickable *) { text->setText("Pressed!"); });

  addObject(button);
}

void Gui::render() {
  window.setView(wView);

  for (auto &v : views) {
    window.draw(*v);
  }
}


void Gui::addObject(const std::shared_ptr<View>& view) {
  views.push_back(view);
  if (view->isClickable()) {
    clickableViews.push_back(std::dynamic_pointer_cast<Clickable>(view));
  }
  if (view->isHoverable()) {
    hoverableViews.push_back(std::dynamic_pointer_cast<Hoverable>(view));
  }
  if (view->isFocusable()) {
    focusableViews.push_back(std::dynamic_pointer_cast<Focusable>(view));
  }
}


void Gui::processEvent(sf::Event event) {
  switch (event.type) {
    case sf::Event::MouseButtonPressed:
      mouseButtonPressed(event.mouseButton);
      break;
    default:
      break;
  }
}
void Gui::mouseButtonPressed(sf::Event::MouseButtonEvent event) {
  for (auto &o : clickableViews) {
    if (o->contains(event.x, event.y)) {
      o->onClick();
    }
  }
}
