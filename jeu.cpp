#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#include "constantes.hpp"
#include "structures.hpp"
#include "joueur.hpp"
#include "battleship.hpp"

using namespace std;

void jeu()
{
    Case map[HAUTEUR][LARGEUR];
    int nb_petrole=rand()%(PETROLE_MAX-PETROLE_MIN+1)+15;
    int i(0),x,y;
    bool partie_finie(false);
    string choix;
    vector<Joueur> players;

    for(x=0;x<HAUTEUR;x++)
    {
        for(y=0;y<LARGEUR;y++)
        {
            map[x][y].type=CASE_LIBRE;
        }
    }

    players.push_back(Joueur(map,HAUTEUR/2,0,HUMAIN,1));
    players.push_back(Joueur(map,HAUTEUR/2,LARGEUR-1,IA,2));

    cout << nb_petrole << endl;

    CLEAR;

    while(i<nb_petrole)
    {
        x=rand()%HAUTEUR;
        y=rand()%LARGEUR;
        if(map[x][y].type==CASE_LIBRE)
        {
            i++;
            map[x][y].type=PETROLE;
        }
    }

    while(partie_finie==false)
    {
        for(x=0;x<HAUTEUR;x++)
        {
            for(y=0;y<LARGEUR;y++)
            {
                if(map[x][y].type==CASE_LIBRE) cout << " ";
                else if(map[x][y].type==PETROLE) cout << "p";
                else if(map[x][y].type==PORT) cout << "z";
                cout << " ";
            }
            cout << endl;
        }
        cout << "Q pour quitter, C pour continuer" << endl;
        cin >> choix;
        if(choix=="Q"||choix=="q") partie_finie=true;
        else partie_finie=false;
    }

    /** enregistrement des scores **/

    while(choix!="M"&&choix!="m")
    {
        cout << "M pour revenir au menu" << endl;
        cin >> choix;
    }
}
