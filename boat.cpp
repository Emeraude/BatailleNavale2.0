#include "boat.hpp"

Boat::Boat(int size, int x, int y, Direction dir) {
  _size = size;
  _life = _size;
  _bonus_range = false;
  _bonus_power = false;
  _x = x;
  _y = y;
  _direction = dir;
}

Boat::~Boat() {}

void Boat::takeDamage(int dmg) {
  _life -= dmg;
}

int Boat::getLife() const {
  return _life;
}

int Boat::getSize() const {
  return _size;
}

int Boat::getX() const {
  return _x;
}

int Boat::getY() const {
  return _y;
}

int Boat::getDirection() const {
  return _direction;
}
