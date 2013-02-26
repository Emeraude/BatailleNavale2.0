#include <iostream>
#include <cstdlib>
#include <string>

#include "constantes.hpp"

#include "credits.hpp"

using namespace std;

void credits()
{
    string choix;

    while(choix!="m"&&choix!="M")
    {
        CLEAR;
        cout << "===== Bataille navale 2.0 =====" << endl << "version " << OS << endl << endl << endl;
        cout << "Idee originale : Emeraude" << endl;
        cout << "Developpement : Emeraude" << endl;
        cout << "Tests : Emeraude" << endl << endl << endl;
        cout << "===== Site web =====" << endl << endl << URL << endl;
        cout << "Developpement web : Emeraude" << endl << endl << endl << endl;
        cout << "M -> Revenir au menu" << endl << "W -> Visiter le site web" << endl << "G -> Voir le projet sur GitHub" << endl;

        cin >> choix;
        if(choix=="w"||choix=="W")
        {
            SITE_WEB;
        }
        else if(choix=="g"||choix=="G")
        {
            GITHUB;
        }
    }
}
