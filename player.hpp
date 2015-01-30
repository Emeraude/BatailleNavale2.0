#ifndef PLAYER_HPP_
# define PLAYER_HPP_

# include <vector>
# include "battleship.hpp"
# include "boat.hpp"
# include "platform.hpp"

class Player
{
private:
    Port _port;
    std::vector<Platform *> _platforms;
    std::vector<Boat *> _bateaux;
    int _argent;
    int _petrole;
    Type _type;

public:
  Player(Case **map, int pos_port_x, int pos_port_y, Type type = HUMAN, int vie = 20, int argent = 100000, int petrole = 5);
  ~Player();

  int getArgent();
  int getPetrole();
  int getVie();
  Boat const& getBateau(int x);
  int getNombreBateaux();

  void recupererPetrole(Case **map,int quantite);
  void vendrePetrole(int quantite);
  void acheterNavire(Case **map, int taille, int pos_x, int pos_y, Direction direction);
  void acheterPlateforme(Case **map, int pos_x, int pos_y);
  void taperPort(Case **map, int degats);
  void taperPlateforme(Case **map,int x);
  void taperBateau(Case **map, int x);
};

#endif
