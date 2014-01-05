#ifndef FUNCTIONS
#define FUNCTIONS

#include "joueur.hpp"

int		distance(int x_a, int y_a, int x_b, int y_b); // retourne la distance entre les points de coordonnées x_a|y_a et x_b|y_b
int		coutPetrole(Port port, int x, int y); // retourne le coût en pétrole d'une case de coordonnées x|y en fonction de sa distance avec le port
Position	trouverPetroleLePlusProche(Case map[][LARGEUR], int x, int y); // retourne la case de petrole la plus proche de la case de coordonnées x|y
Position	trouverPetrole(Case map[][LARGEUR], int x, int y); // alias de trouverPetroleLePlusProche
bool		listeCases(Case map[][LARGEUR], std::vector<Position> a, Bateau bateau); // remplis le tableau vide a des cases du bateau bateau ; renvoie true si le tableau a bien été rempli, false sinon
Bateau		infoBateau(Case map[][LARGEUR], int x, int y, Joueur &joueur); // donne des infos sur le bateau aux coordonnées x|y
bool		bateauExiste(Bateau bateau);

#endif
