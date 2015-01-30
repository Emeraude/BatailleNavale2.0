#ifndef GAME_HPP_
# define GAME_HPP_

# include <vector>
# include "battleship.hpp"
# include "player.hpp"

# define OIL_MAX 20
# define OIL_MIN 15

# define RAND_TSUNAMI 36
# define POWER_TSUNAMI 1

class Game {
private:
  std::vector<Player *> _players;
  std::size_t _height;
  std::size_t _width;
  std::size_t _nb_oil;
  Case **_map;

public:
  Game(std::size_t height = 15, std::size_t width = 20);
  ~Game();

  void display() const;
  void run() const;
};

#endif
