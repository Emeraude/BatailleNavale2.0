#ifndef BOAT_HPP_
# define BOAT_HPP_

# include "battleship.hpp"

class Boat {
private:
  int _size;
  int _life;
  bool _bonus_range;
  bool _bonus_power;
  int _x;
  int _y;
  int _direction;

public:
  Boat(int size = 1, int x = 0, int y = 0, int direction = VERTICAL);
  ~Boat();

  void takeDamage(int dmg);
  int getLife() const;
  int getSize() const;
  int getX() const;
  int getY() const;
  int getDirection() const;
};

#endif
