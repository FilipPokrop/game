#pragma once

#include <Entity.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>

class Character : public Entity, public sf::Drawable, public sf::Transformable {
public:
  Character();

  void update(const sf::Time dt);
  void moveLeft();
  void moveRight();

private:
  virtual void draw(sf::RenderTarget &targeet, sf::RenderStates states) const;

private:
  sf::Vector2f position;
  sf::Vector2f velocity;
  sf::Vector2f acceleration;

  sf::Vector2f walk_velocity;
};
