/*
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Clickable {
 public:
  virtual void onClick(const sf::Vector2i &mouse_pos) = 0;
};

class Box : public sf::Drawable, public Clickable {
  sf::RectangleShape box;

 public:
  Box(int x, int y, int w, int h, sf::Color fillColor = sf::Color::Black, sf::Color outlineColor = sf::Color::White) {
    box.setPosition(x, y);
    box.setSize(sf::Vector2f(w, h));
    box.setFillColor(fillColor);
    box.setOutlineColor(outlineColor);
    box.setOutlineThickness(20);
  }

  void onClick(const sf::Vector2i &mouse_pos) override {
  }

  bool contains(const sf::Vector2f &mouse_pos) {
    return box.getGlobalBounds().contains(mouse_pos);
  }

  void onFocus() {
    box.setOutlineColor(sf::Color(0xFFE082FF));
  }

  void onFocusLost() {
    box.setOutlineColor(sf::Color::White);
  }

  void move(const sf::Vector2i &delta) {
    box.move((sf::Vector2f)delta);
  }

 protected:
  void draw(sf::RenderTarget &target, sf::RenderStates states) const override {
    target.draw(box, states);
  }
};

class Gui : public sf::Drawable {
  vector<shared_ptr<Box>> objects;
  vector<shared_ptr<Box>> clickableObjects;
  shared_ptr<Box> objectWithFocus = nullptr;
  shared_ptr<Box> objectDrag = nullptr;
  sf::Vector2i deltaMouse;

  sf::RenderWindow &window;

 public:
  Gui(sf::RenderWindow &window) : window(window) {}

 public:
  void addObject(const shared_ptr<Box> &object, bool isClickable = false) {
    objects.emplace_back(object);
    if (isClickable) {
      clickableObjects.emplace_back(object);
    }
  }

  void mousePressed(const sf::Vector2i &mouse_pos) {
    deltaMouse = mouse_pos;
    if (objectWithFocus) {
      objectWithFocus->onFocusLost();
    }
    sf::Vector2f mouse_pos_coord = window.mapPixelToCoords(mouse_pos);
    for (auto &object : clickableObjects) {
      if (object->contains(mouse_pos_coord)) {
        object->onClick(mouse_pos);
        objectWithFocus = object;
        objectWithFocus->onFocus();

        objectDrag = object;

        break;
      }
    }
  }

  void mouseReleased(const sf::Vector2i &mouse_pos) {
    objectDrag = nullptr;
  }

  void mouseMoved(const sf::Vector2i &mouse_pos) {
    sf::View view = window.getView();
    static sf::Vector2f offset;
    if (mouse_pos.x > window.getSize().x * 0.9) {
      offset.x += 0.2;
    } else if (mouse_pos.x < window.getSize().x * 0.1) {
      offset.x += -0.2;
    } else {
      offset.x = 0;
    }
    if (offset.x > 10) {
      offset.x = 10;
    }
    if (offset.x < -10) {
      offset.x = -10;
    }
    if (mouse_pos.y > window.getSize().y * 0.9) {
      offset.y += 0.2;
    } else if (mouse_pos.y < window.getSize().y * 0.1) {
      offset.y += -0.2;
    } else {
      offset.y = 0;
    }
    if (offset.y > 10) {
      offset.y = 10;
    }
    if (offset.y < -10) {
      offset.y = -10;
    }

    view.move(offset);
    window.setView(view);

    if (objectDrag != nullptr) {
      objectDrag->move(mouse_pos - deltaMouse);
      deltaMouse = mouse_pos;
    }
  }

  void processEvents() {
    sf::Event event{};
    while (window.pollEvent(event)) {
      switch (event.type) {
        case sf::Event::Closed:
          window.close();
          break;
        case sf::Event::MouseButtonPressed:
          mousePressed(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
          break;
        case sf::Event::MouseButtonReleased:
          mouseReleased(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
          break;
        case sf::Event::MouseMoved:
//          mouseMoved(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));
          break;
        default:
          break;
      }
    }
  }

  void update(sf::Time time) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    mouseMoved(mousePos);
  }

 protected:
  void draw(sf::RenderTarget &target, sf::RenderStates states) const override {
    for (auto &i : objects) {
      target.draw(*i, states);
    }
  }

};

int main() {


  sf::RenderWindow window(sf::VideoMode(1600, 900), "Builder");



  sf::View view1;
  view1.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
  view1.setCenter(800, 450);
  view1.setSize(1600, 900);

  sf::CircleShape circle1;
  circle1.setRadius(30);
  circle1.setPosition(50, 200);
  circle1.setFillColor(sf::Color::Green);

  sf::CircleShape circle2;
  circle2.setRadius(100);
  circle2.setPosition(300, 300);
  circle2.setFillColor(sf::Color::Blue);

  sf::View view2;
  view2.setViewport(sf::FloatRect(0.02f, 0.02f, 0.2f, 0.2f));
  view2.setCenter(800, 450);
  view2.setSize(1600, 900);

  sf::RectangleShape border;
  border.setSize(sf::Vector2(1600.f, 900.f));
  border.setFillColor(sf::Color(255, 255, 255, 128.0));
  border.setOutlineColor(sf::Color::Cyan);
  border.setOutlineThickness(-20.f);

  sf::RectangleShape areaView;
  areaView.setSize(view1.getSize());
  areaView.setPosition(view1.getCenter() - sf::Vector2(areaView.getSize().x / 2, areaView.getSize().y / 2));
  areaView.setFillColor(sf::Color(0, 0, 0, 0));
  areaView.setOutlineColor(sf::Color::Red);
  areaView.setOutlineThickness(-20.f);

  while (window.isOpen()) {
    sf::Event ev{};
    while (window.pollEvent(ev)) {
      if (ev.type == sf::Event::Closed) {
        window.close();
      }
      if (ev.type == sf::Event::MouseButtonPressed) {
        sf::Vector2i mPos(ev.mouseButton.x, ev.mouseButton.y);
        sf::Vector2f p2 = window.mapPixelToCoords(mPos, view2);
        if (sf::RectangleShape(view2.getSize()).getGlobalBounds().contains(p2)) {
          view1.setCenter(p2);
          areaView.setPosition(view1.getCenter() - sf::Vector2(areaView.getSize().x / 2, areaView.getSize().y / 2));
        }
      }
      if (ev.type == sf::Event::MouseWheelScrolled) {
        float factor = 1 - 0.05 * ev.mouseWheelScroll.delta;
        view1.setSize(view1.getSize().x * factor, view1.getSize().y * factor);
        areaView.setSize(view1.getSize());
        areaView.setPosition(view1.getCenter() - sf::Vector2(areaView.getSize().x / 2, areaView.getSize().y / 2));
        cout << factor << "\n";
      }
    }
    window.clear();

    window.setView(view1);
    window.draw(circle1);
    window.draw(circle2);

    window.setView(view2);
    window.draw(border);
    window.draw(circle1);
    window.draw(circle2);
    window.draw(areaView);



    window.display();
  }


*/
/*  window.setView(view1);

  sf::View view2;
  view2.setViewport(sf::FloatRect(0.5f, 0.f, 0.5f, 1.f));
  view2.setCenter(0, 0);
  view2.setSize(800, 900);


  Gui gui(window);
  gui.addObject(make_shared<Box>(500, 100, 400, 200), true);
  gui.addObject(make_shared<Box>(20, 100, 400, 200), true);

  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;

  const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f);

  while (window.isOpen()) {
    timeSinceLastUpdate += clock.restart();
    while (timeSinceLastUpdate > TIME_PER_FRAME) {
      timeSinceLastUpdate -= TIME_PER_FRAME;
      gui.processEvents();
      gui.update(TIME_PER_FRAME);
    }

    window.clear(sf::Color::Transparent);
    window.setView(view2);

    window.draw(gui);
    window.setView(view1);

    window.draw(gui);

    window.display();
  }*//*


  return 0;
}
*/

#include <iostream>

#include "game/Game.hpp"

int main() {
  Game::initInstance(Settings(sf::VideoMode::getDesktopMode(), sf::Style::Default));
  Game::getInstance().run();
  Game::destroy();
}