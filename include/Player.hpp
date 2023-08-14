#pragma once

#include <Character.hpp>
#include <Entity.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <functional>
#include <map>
#include <vector>

enum class Action {
  moveLeft,
  moveRight,

};

class Player {
public:
  typedef std::function<void(Character &)> callback;
  Player();

  void handleEvents();

  bool addKeyBinding(const sf::Keyboard::Key key, const Action action);
  bool removeKeyBinding(const sf::Keyboard::Key key);

  bool addActionBinding(const Action action, callback fn);
  bool removeActionBinding(const Action action);

  const std::vector<std::pair<Action, callback>> &getCallbacks();
  void clearCallbacks();

private:
  bool isRealtimeAction(const Action action);

private:
  std::map<sf::Keyboard::Key, Action> keyBindings;
  std::map<Action, callback> actionBindings;
  std::vector<std::pair<Action, callback>> callbacks;
};
