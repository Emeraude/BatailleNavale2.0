#ifndef CLASS_JOUEUR
#define CLASS_JOUEUR

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

    Joueur();
    Joueur(Case map[][LARGEUR],int pos_port_x, int pos_port_y, int type, int numero_joueur);
    Joueur(Case map[][LARGEUR],int pos_port_x, int pos_port_y, int type, int numero_joueur, int vie, int argent, int petrole);
    ~Joueur();

    /** Accesseurs **/

    int getArgent(); // retourne m_argent
    int getPetrole(); // retourne m_petrole;
    int getVie(); // retourne m_port.vie;
    Bateau getBateau(int x); // retourne m_bateaux[x];
    int getNombreBateaux(); // retourne m_nombre_bateaux;

    /** Méthodes **/

    void recupererPetrole(Case map[][LARGEUR],int quantite); // récolte du pétrole;
    void vendrePetrole(int quantite); // vend quantite de pétrole;
    void acheterNavire(Case map[][LARGEUR], int taille, int pos_x, int pos_y, int direction); // paramètres : map ; taille du bateau ; coordonnées d'une extrêmité du bateau ; direction du bateau (utiliser constantes);
    void acheterPlateforme(Case map[][LARGEUR], int pos_x, int pos_y); // paramètres : map ; coordonnées de la plateforme;
    void taperPort(Case map[][LARGEUR], int degats);
    void taperPlateforme(Case map[][LARGEUR],int x); // x=position dans le tableau dynamique
    void taperBateau(Case map[][LARGEUR],int degats, int x);// x=position dans le tableau dynamique
};

#endif
