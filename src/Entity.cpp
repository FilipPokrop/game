#include <Entity.hpp>
#include <cstddef>

void Entity::resetID() { current_id = 0; }

size_t Entity::current_id = 0;

Entity::Entity() : ID(++current_id) {}

std::ostream &operator<<(std::ostream &os, const Entity &e) {
  return os << "Entity: " << e.ID;
}
