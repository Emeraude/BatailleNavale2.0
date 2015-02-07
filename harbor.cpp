#include "harbor.hpp"

Harbor::Harbor(int x, int y, int life) {
  _x = x;
  _y = y;
  _life = life;
}

Harbor::~Harbor() {}

int Harbor::getX() const {
  return _x;
}

int Harbor::getY() const {
  return _y;
}

int Harbor::getLife() const {
  return _life;
}

int Harbor::getDamage(int dmg) {
  return (_life -= dmg);
}
