#pragma once

#include <cstddef>
#include <ostream>
class Entity {
public:
  Entity();

protected:
  size_t ID;

private:
  static void resetID();
  static size_t current_id;

public:
  friend std::ostream &operator<<(std::ostream &os, const Entity &e);
};

std::ostream &operator<<(std::ostream &os, const Entity &e);
