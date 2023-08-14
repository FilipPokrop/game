#include "Entity.hpp"
#include <Character.hpp>
#include <Player.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <assert.h>
#include <functional>
#include <utility>

Player::Player() {
  addActionBinding(Action::moveRight, &Character::moveRight);
  addActionBinding(Action::moveLeft, &Character::moveLeft);
}

bool Player::isRealtimeAction(const Action action) {
  switch (action) {
  case Action::moveLeft:
  case Action::moveRight:
    return true;
    break;
  default:
    return false;
  }
}

bool Player::addKeyBinding(const sf::Keyboard::Key key, const Action action) {
  auto found = keyBindings.find(key);
  if (found != keyBindings.end())
    return false;
  return keyBindings.insert(std::make_pair(key, action)).second;
}

bool Player::removeKeyBinding(const sf::Keyboard::Key key) {
  auto found = keyBindings.find(key);
  if (found == keyBindings.end())
    return false;
  keyBindings.erase(found);
  return true;
}

bool Player::addActionBinding(const Action action, callback fn) {
  auto found = actionBindings.find(action);
  if (found != actionBindings.end())
    return false;
  return actionBindings.insert(std::make_pair(action, fn)).second;
}

bool Player::removeActionBinding(const Action action) {
  auto found = actionBindings.find(action);
  if (found == actionBindings.end())
    return false;
  actionBindings.erase(found);
  return true;
}

void Player::handleEvents() {
  for (auto iter = keyBindings.begin(); iter != keyBindings.end(); iter++) {
    if (sf::Keyboard::isKeyPressed(iter->first) &&
        isRealtimeAction(iter->second)) {
      auto found = actionBindings.find(iter->second);
      assert(found != actionBindings.end());
      if (find_if(callbacks.begin(), callbacks.end(),
                  [found](std::pair<Action, callback> p) {
                    return p.first == found->first;
                  }) == callbacks.end())
        callbacks.push_back(*found);
    }
  }
}

const std::vector<std::pair<Action, Player::callback>> &Player::getCallbacks() {
  return callbacks;
}

void Player::clearCallbacks() { callbacks.clear(); }
