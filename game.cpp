#include <iostream>
#include <string>
#include <cstdlib>
#include "game.hpp"

Game::Game(std::size_t height, std::size_t width) {
  _height = height;
  _width = width;
  _map = new Case*[_height + 1];
  for (std::size_t i = 0; i < _height; ++i) {
    _map[i] = new Case[_width + 1];
    for (std::size_t j = 0; j < _width; ++j)
      _map[i][j] = EMPTY;
    _map[i][_width] = BORDER;
  }
  _map[_height] = NULL;
  _players.push_back(new Player(_map, _height / 2, 0, HUMAN));
  _players.push_back(new Player(_map, _height / 2, _width - 1));
  _nb_oil = rand() % (OIL_MAX - OIL_MIN + 1) + OIL_MIN;
  for (std::size_t i = 0; i < _nb_oil; ++i) {
    int x = rand() % _height;
    int y = rand() % _width;
    if (_map[x][y] == EMPTY)
      _map[x][y] = OIL;
  }
}

Game::~Game() {
  while (!_players.empty()) {
    delete _players.back();
    _players.pop_back();
  }
  // TODO : delete _map
}

void Game::display() const {
  for (std::size_t i = 0; i < _height; ++i) {
    for (std::size_t j = 0; j < _width; ++j) {
      if (_map[i][j] == OIL)
	std::cout << "O";
      else if (_map[i][j] == PORT)
	std::cout << "P";
      else
	std::cout << " ";
    }
    std::cout << std::endl;
  }
}

void Game::run() const {
  std::string choice;

  while (1) {
    this->display();
    std::cout << "Q -> Quit" << std::endl << "C -> Continue" << std::endl;
    std::cin >> choice;
    if (choice == "Q" || choice == "q")
      break ;
  }
}
