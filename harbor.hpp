#ifndef HARBOR_HPP_
# define HARBOR_HPP_

class Harbor {
private:
  int _x;
  int _y;
  int _life;

public:
  Harbor(int x, int y, int life = 20);
  ~Harbor();

  int getX() const;
  int getY() const;
  int getLife() const;

  int getDamage(int dmg);
};

#endif
