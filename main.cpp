#include <ctime>
#include <cstdlib>
#include "game.hpp"

int main(void) {
  Game game;

  srand(time(NULL));
  game.run();
  return 0;
}
