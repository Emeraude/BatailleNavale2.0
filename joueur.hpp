#ifndef CLASS_JOUEUR
#define CLASS_JOUEUR

#include "battleship.hpp"
#include <vector>

class Joueur
{
private:
    Port m_port;
    std::vector<Plateforme> m_plateformes;
    std::vector<Bateau> m_bateaux;
    int m_argent;
    int m_petrole;
    int m_nombre_plateformes;
    int m_nombre_bateaux;
    int m_score;
    int m_type;
    int m_numero_joueur;

public:
    Joueur(Case map[][LARGEUR],int pos_port_x, int pos_port_y, int type, int numero_joueur);
    Joueur(Case map[][LARGEUR],int pos_port_x, int pos_port_y, int type, int numero_joueur, int vie, int argent, int petrole);
    ~Joueur();

    int getArgent();
    int getPetrole();
    int getVie();
    Bateau getBateau(int x);
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
