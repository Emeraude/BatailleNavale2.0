#ifndef CLASS_JOUEUR
#define CLASS_JOUEUR

#include <vector>
#include "battleship.hpp"
#include "boat.hpp"

class Joueur
{
private:
    Port _port;
    std::vector<Plateforme> _plateformes;
    std::vector<Boat *> _bateaux;
    int _argent;
    int _petrole;
    int _type;

public:
    Joueur(Case map[][LARGEUR],int pos_port_x, int pos_port_y, int type, int vie = 20, int argent = 100000, int petrole = 5);
    ~Joueur();

    int getArgent();
    int getPetrole();
    int getVie();
    Boat const& getBateau(int x);
    int getNombreBateaux();

    void recupererPetrole(Case map[][LARGEUR],int quantite); // r�colte du p�trole;
    void vendrePetrole(int quantite); // vend quantite de p�trole;
    void acheterNavire(Case map[][LARGEUR], int taille, int pos_x, int pos_y, int direction); // param�tres : map ; taille du bateau ; coordonn�es d'une extr�mit� du bateau ; direction du bateau (utiliser constantes);
    void acheterPlateforme(Case map[][LARGEUR], int pos_x, int pos_y); // param�tres : map ; coordonn�es de la plateforme;
    void taperPort(Case map[][LARGEUR], int degats);
    void taperPlateforme(Case map[][LARGEUR],int x); // x=position dans le tableau dynamique
    void taperBateau(Case map[][LARGEUR], int x);// x=position dans le tableau dynamique
};

#endif
