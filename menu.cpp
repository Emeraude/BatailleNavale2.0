#include <iostream>
#include <string>
#include <cstdlib>

#include "constantes.hpp"

#include "menu.hpp"
#include "jeu.hpp"
#include "credits.hpp"
#include "halloffame.hpp"

using namespace std;

void menu()
{
    string choix;
    bool continuer(true);

    while(continuer)
    {
        CLEAR;
        cout << "J -> Jouer" << endl << "H -> Halloffame" << endl << "C -> Credits" << endl << "Q -> Quitter" << endl << endl;
        cin >> choix;
        if(choix=="j"||choix=="J")
        {
            /** un menu demandant la taille de la map, le nombre de source de petroles, le nombre de joueurs et la probabilité d'un tsunami **/
            jeu();
        }
        else if(choix=="h"||choix=="H") halloffame();
        else if(choix=="c"||choix=="C") credits();
        else if(choix=="q"||choix=="Q") continuer=false;
    }
}
