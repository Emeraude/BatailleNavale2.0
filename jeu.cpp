#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#include "player.hpp"
#include "battleship.hpp"

void jeu()
{
    Case map[HAUTEUR][LARGEUR];
    int nb_petrole=rand()%(PETROLE_MAX-PETROLE_MIN+1)+15;
    int i = 0,x,y;
    bool partie_finie = false;
    std::string choix;
    std::vector<Player *> players;

    for(x=0;x<HAUTEUR;x++)
    {
        for(y=0;y<LARGEUR;y++)
        {
            map[x][y]=EMPTY;
        }
    }

    players.push_back(new Player(map,HAUTEUR/2,0,HUMAN,1));
    players.push_back(new Player(map,HAUTEUR/2,LARGEUR-1,AI,2));

    std::cout << nb_petrole << std::endl;

    while (i < nb_petrole)
    {
        x=rand()%HAUTEUR;
        y=rand()%LARGEUR;
        if(map[x][y]==EMPTY)
        {
            i++;
            map[x][y]=OIL;
        }
    }

    while(partie_finie==false)
    {
        for(x=0;x<HAUTEUR;x++)
        {
            for(y=0;y<LARGEUR;y++)
            {
	      if (map[x][y]==EMPTY) std::cout << " ";
	      else if (map[x][y]==OIL) std::cout << "p";
	      else if (map[x][y]==PORT) std::cout << "z";
	      std::cout << " ";
            }
	    std::cout << std::endl;
        }
	std::cout << "Q pour quitter, C pour continuer" << std::endl;
	std::cin >> choix;
	partie_finie = choix == "Q" || choix == "q";
    }
}
