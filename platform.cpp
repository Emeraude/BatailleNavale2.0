#include "platform.hpp"

Platform::Platform(int x, int y) {
  _x = x;
  _y = y;
}

Platform::~Platform() {}

int Platform::getX() const {
  return _x;
}

int Platform::getY() const {
  return _y;
}
