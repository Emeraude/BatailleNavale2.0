#include <iostream>
#include <cmath>
#include <vector>

#include "battleship.hpp"
#include "joueur.hpp"

Joueur::Joueur(Case map[][LARGEUR],int pos_port_x, int pos_port_y, int type, int vie, int argent, int petrole)
{
    _port.pos.x=pos_port_x;
    _port.pos.y=pos_port_y;
    map[_port.pos.x][_port.pos.y]=PORT;
    _type=type;
    _port.vie=vie;
    _argent=argent;
    _petrole=petrole;
}

Joueur::~Joueur() {
  while (!_bateaux.empty()) {
    delete _bateaux.back();
    _bateaux.pop_back();
  }
}

int Joueur::getArgent()
{
    return _argent;
}

int Joueur::getPetrole()
{
    return _petrole;
}

int Joueur::getVie()
{
    return _port.vie;
}

Boat const& Joueur::getBateau(int x)
{
  return *_bateaux[x];
}

void Joueur::recupererPetrole(Case map[][LARGEUR],int quantite)
{
    int i,prix(0);
    Position position;

    if((unsigned)quantite > _plateformes.size()+1) std::cout << "Vous n'avez pas suffisamment de plateformes petrolieres." << std::endl;
    else
    {
        position=trouverPetrole(map,_port.pos.x,_port.pos.y);
        prix+=500*distance(position.x,position.y,_port.pos.x,_port.pos.y);

        for(i=0;i<quantite;i++)
        {
            position=trouverPetrole(map,_plateformes[i].pos.x,_plateformes[i].pos.y);
            prix+=distance(position.x,position.y,_plateformes[i].pos.x,_plateformes[i].pos.y);
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

void Joueur::vendrePetrole(int quantite)
{
    if(quantite>_petrole)
    {
      std::cout << "Vous n'avez que " << _petrole << " barils de pétrole et ne pouvez en vendre " << quantite << "." << std::endl;
    }
    else
    {
        _petrole-=quantite;
        _argent+=quantite*5000;
	std::cout << "Vous avez vendu " << quantite << " barils de pétrole pour la somme de " << quantite*5000 << " $." << std::endl << "Il vous reste " << _petrole << " barils." << std::endl;
    }
}

void Joueur::acheterNavire(Case map[][LARGEUR], int taille, int pos_x, int pos_y, int direction)
{
    int i;
    bool e = false;

    if(map[pos_x][pos_y]!=CASE_LIBRE)
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
                if(map[pos_x-i][pos_y]!=CASE_LIBRE)
                {
		  std::cout << "La case aux coordonnees " << pos_x-i << "|" << pos_y << " n'est pas libre." << std::endl;
		  e=true;
                }
            }
            else if(direction==HORIZONTAL&&pos_y-i>=0)
            {
                if(map[pos_x][pos_y-i]!=CASE_LIBRE)
                {
		  std::cout << "La case aux coordonnees " << pos_x << "|" << pos_y-1 << " n'est pas libre." << std::endl;
		  e=true;
                }
            }
        }
        if(_petrole<coutPetrole(_port,pos_x,pos_y))
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
	      _petrole -= coutPetrole(_port, pos_x, pos_y);
                for(i=0;i<taille;i++)
                {
		    if(direction==VERTICAL)
		      map[pos_x-i][pos_y]=BATEAU;
                    else if(direction==HORIZONTAL)
		      map[pos_x][pos_y-i]=BATEAU;
                }
            }
            else
	      std::cout << "Ce bateau coute " << pow(2,taille-1) << "$ et vous ne disposez que de " << _argent << "$." << std::endl;
        }
    }
}
void Joueur::acheterPlateforme(Case map[][LARGEUR], int pos_x, int pos_y)
{
    bool e=false;
    if(map[pos_x][pos_y]!=CASE_LIBRE)
    {
      std::cout << "La case aux coordonnées " << pos_x << "|" << pos_y << " n'est pas libre." << std::endl;
      e=true;
    }
    if(_petrole<coutPetrole(_port,pos_x,pos_y))
    {
      std::cout << "Vous n'avez pas assez de petrole pour placer un bateau ici." << std::endl;
      e=true;
    }
    if(_argent<5000)
    {
      std::cout << "Une plateforme petroliere coute 5000$ et vous ne disposez que de " << _argent << "$." << std::endl;
      e=true;
    }
    if (!e)
    {
        _argent-=5000;
        _petrole-=coutPetrole(_port,pos_x,pos_y);
        map[pos_x][pos_y]=PLATEFORME;
        _plateformes.push_back(Plateforme());
        _plateformes.back().pos.x=pos_x;
        _plateformes.back().pos.y=pos_y;
    }
}
void Joueur::taperPort(Case map[][LARGEUR], int degats)
{
    map[_port.pos.x][_port.pos.y]=CASE_DETRUITE;
    _port.vie-=degats;
}

void Joueur::taperPlateforme(Case map[][LARGEUR], int x)
{
    map[_plateformes[x].pos.x][_plateformes[x].pos.y]=CASE_DETRUITE;
}

void Joueur::taperBateau(Case map[][LARGEUR], int x)
{
    _bateaux[x]->takeDamage(1);
    if (_bateaux[x]->getLife() <= 0) {
      for (int i = 0; i < _bateaux[x]->getSize(); ++i) {
	if (_bateaux[x]->getDirection() == VERTICAL)
	  map[_bateaux[x]->getX() - i][_bateaux[x]->getY()]=CASE_DETRUITE;
	else if (_bateaux[x]->getDirection() == HORIZONTAL)
	  map[_bateaux[x]->getX()][_bateaux[x]->getY() - i]=CASE_DETRUITE;
      }
      delete _bateaux[x];
    }
}
