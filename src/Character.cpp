#include <Character.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>

Character::Character()
    : position(), velocity(), acceleration(), walk_velocity() {}
void Character::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  states.transform *= getTransform();
  target.draw(sf::RectangleShape(sf::Vector2f(100, 20)), states);
}

void Character::update(const sf::Time dt) {
  float sec = dt.asSeconds();
  position += ((acceleration * sec) * 0.5f + velocity + walk_velocity) * sec;
  velocity += acceleration * sec;

  walk_velocity = {0.f, 0.f};
  setPosition(position);
}

void Character::moveLeft() { walk_velocity += {-10.f, 0.f}; }

void Character::moveRight() { walk_velocity += {10.f, 0.f}; }
