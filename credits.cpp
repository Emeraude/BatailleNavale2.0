#include <iostream>
#include <cstdlib>
#include <string>

#include "constantes.hpp"

#include "credits.hpp"

using namespace std;

void credits()
{
    string choix;

    CLEAR;
    cout << "===== Bataille navale 2.0 =====" << endl << "version " << OS << endl << endl << endl;
    cout << "Idee originale : Antoine Cormerais - Emeraude" << endl;
    cout << "Developpement : Emeraude" << endl;
    cout << "Tests : Emeraude" << endl << endl << endl;
    cout << "===== Site web =====" << endl << endl << URL << endl;
    cout << "Developpement web : Emeraude" << endl << endl << endl << endl;

    while(choix!="m"&&choix!="M")
    {
        cout << "M pour revenir au menu, W pour visiter le site web" << endl;
        cin >> choix;
        if(choix=="w"||choix=="W")
        {
            SITE_WEB;
        }
    }
}
