#include <Character.hpp>
#include <Entity.hpp>
#include <Player.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <iostream>

int main() {
  sf::RenderWindow window(sf::VideoMode(1280, 720), "GAME", sf::Style::Default);
  Player player;
  player.addKeyBinding(sf::Keyboard::D, Action::moveRight);
  player.addKeyBinding(sf::Keyboard::A, Action::moveLeft);

  Character *character = new Character();
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
    player.handleEvents();
    auto callbacks = player.getCallbacks();
    for (auto &c : callbacks) {
      c.second(*character);
    }
    player.clearCallbacks();
    character->update(sf::seconds(0.1));
    window.clear();
    window.draw(*character);
    window.display();
  }

  Entity e1;
  Entity e2;
  std::cout << e1 << std::endl << e2 << std::endl;
  std::cout << (*character) << std::endl;
  delete character;
}
