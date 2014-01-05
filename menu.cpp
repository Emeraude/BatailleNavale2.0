#include <iostream>
#include <string>
#include <cstdlib>

#include "constantes.hpp"
#include "battleship.hpp"

using namespace std;

void menu()
{
    string choix;
    bool continuer(true);

    while (1)
    {
        CLEAR;
        cout << "J -> Jouer" << endl << "C -> Credits" << endl << "Q -> Quitter" << endl << endl;
        cin >> choix;
        if(choix=="j"||choix=="J")
        {
            /** un menu demandant la taille de la map, le nombre de sources de pétrole, le nombre de joueurs et la probabilité d'un tsunami **/
            jeu();
        }
        else if (choix == "c" || choix == "C") credits();
        else if (choix == "q" || choix == "Q") return;
    }
}
