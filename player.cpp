#include <iostream>
#include <cmath>
#include <vector>

#include "battleship.hpp"
#include "player.hpp"

Player::Player(Case **map,int pos_port_x, int pos_port_y, Type type, int vie, int argent, int petrole) :
  _harbor(pos_port_x, pos_port_y, vie) {
  map[_harbor.getX()][_harbor.getY()] = PORT;
  _type = type;
  _argent = argent;
  _petrole = petrole;
}

Player::~Player() {
  while (!_bateaux.empty()) {
    delete _bateaux.back();
    _bateaux.pop_back();
  }
}

int Player::getArgent()
{
    return _argent;
}

int Player::getPetrole()
{
    return _petrole;
}

Boat const& Player::getBateau(int x)
{
  return *_bateaux[x];
}

void Player::recupererPetrole(Case **map,int quantite)
{
    int i,prix(0);
    Position position;

    if((unsigned)quantite > _platforms.size()+1) std::cout << "Vous n'avez pas suffisamment de plateformes petrolieres." << std::endl;
    else
    {
        position=trouverPetroleLePlusProche(map,_harbor.getX(),_harbor.getY());
        prix += COST_GET_OIL * distance(position.x,position.y,_harbor.getX(),_harbor.getY());

        for(i=0;i<quantite;i++)
        {
	  position = trouverPetroleLePlusProche(map, _platforms[i]->getX(), _platforms[i]->getY());
	  prix += COST_GET_OIL * distance(position.x, position.y, _platforms[i]->getX(), _platforms[i]->getY());
        }
        if(prix>=_argent)
        {
            _argent-=prix;
            _petrole+=1+i;
        }
        else
        {
	  std::cout << "Vous n'avez pas suffisamment d'argent" << std::endl;
        }
    }
}

void Player::vendrePetrole(int nb) {
  if (nb > _petrole)
    std::cout << "Vous n'avez que " << _petrole << " barils de pétrole et ne pouvez en vendre " << nb << "." << std::endl;
  else {
    _petrole -= nb;
    _argent += nb * COST_SELL_OIL;
    std::cout << "Vous avez vendu " << nb << " barils de pétrole pour la somme de " << nb*COST_SELL_OIL << " $." << std::endl << "Il vous reste " << _petrole << " barils." << std::endl;
  }
}

void Player::acheterNavire(Case **map, int taille, int pos_x, int pos_y, Direction direction)
{
    int i;
    bool e = false;

    if(map[pos_x][pos_y]!=EMPTY)
    {
      std::cout << "La case aux coordonnées " << pos_x << "|" << pos_y << " n'est pas libre." << std::endl;
      e=true;
    }
    else
    {
        for(i=1;i<taille;i++)
        {
            if(direction==VERTICAL&&pos_x-i>=0)
            {
                if(map[pos_x-i][pos_y]!=EMPTY)
                {
		  std::cout << "La case aux coordonnees " << pos_x-i << "|" << pos_y << " n'est pas libre." << std::endl;
		  e=true;
                }
            }
            else if(direction==HORIZONTAL&&pos_y-i>=0)
            {
                if(map[pos_x][pos_y-i]!=EMPTY)
                {
		  std::cout << "La case aux coordonnees " << pos_x << "|" << pos_y-1 << " n'est pas libre." << std::endl;
		  e=true;
                }
            }
        }
        if(_petrole<coutPetrole(_harbor,pos_x,pos_y))
        {
	  std::cout << "Vous n'avez pas assez de petrole pour placer un bateau ici." << std::endl;
	  e=true;
        }
        if(!e)
        {
            if(_argent>=1000*pow(2,taille-1))
            {
	      _bateaux.push_back(new Boat(taille, pos_x, pos_y, direction));
	      _argent -= 1000 * pow(2, taille - 1);
	      _petrole -= coutPetrole(_harbor, pos_x, pos_y);
                for(i=0;i<taille;i++)
                {
		    if(direction==VERTICAL)
		      map[pos_x-i][pos_y] = BOAT;
                    else
		      map[pos_x][pos_y-i] = BOAT;
                }
            }
            else
	      std::cout << "Ce bateau coute " << pow(2,taille-1) << "$ et vous ne disposez que de " << _argent << "$." << std::endl;
        }
    }
}

void Player::acheterPlateforme(Case **map, int pos_x, int pos_y) {
  if (map[pos_x][pos_y] != EMPTY)
    std::cout << "La case aux coordonnées " << pos_x << "|" << pos_y << " n'est pas libre." << std::endl;
  else if (_petrole < coutPetrole(_harbor, pos_x, pos_y))
    std::cout << "Vous n'avez pas assez de petrole pour placer une plateform ici." << std::endl;
  else if (_argent < COST_PLATFORM)
    std::cout << "Une plateforme petroliere coute " << COST_PLATFORM << "$ et vous ne disposez que de " << _argent << "$." << std::endl;
  else {
    _argent -= COST_PLATFORM;
    _petrole -= coutPetrole(_harbor, pos_x, pos_y);
    map[pos_x][pos_y] = PLATFORM;
    _platforms.push_back(new Platform(pos_x, pos_y));
  }
}

void Player::taperPort(Case **map, int dmg) {
  if (_harbor.getDamage(dmg) <= 0)
    map[_harbor.getX()][_harbor.getY()] = DESTROYED;
}

void Player::taperPlateforme(Case **map, int x) {
  map[_platforms[x]->getX()][_platforms[x]->getY()] = DESTROYED;
  delete _platforms[x];
}

void Player::taperBateau(Case **map, int x) {
    _bateaux[x]->takeDamage(1);
    if (_bateaux[x]->getLife() <= 0) {
      for (int i = 0; i < _bateaux[x]->getSize(); ++i) {
	if (_bateaux[x]->getDirection() == VERTICAL)
	  map[_bateaux[x]->getX() - i][_bateaux[x]->getY()]=DESTROYED;
	else
	  map[_bateaux[x]->getX()][_bateaux[x]->getY() - i]=DESTROYED;
      }
      delete _bateaux[x];
    }
}
