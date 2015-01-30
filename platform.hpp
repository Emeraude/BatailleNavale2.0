#ifndef PLATFORM_HPP_
# define PLATFORM_HPP_

class Platform {
private:
  int _x;
  int _y;

public:
  Platform(int x, int y);
  ~Platform();

  int getX() const;
  int getY() const;
};

#endif
