#ifndef CONSTANTES
#define CONSTANTES

/** CONSTANTES **/

#define HAUTEUR         15
#define LARGEUR         20

#define PROBA_TSUNAMI   36
#define DEGATS_TSUNAMI  1

#define PETROLE_MIN     15
#define PETROLE_MAX     20

#define NOMBRE_JOUEUR   2

#define PORT            101
#define PETROLE         102
#define PLATEFORME      103
#define BATEAU          104
#define CASE_LIBRE      105
#define CASE_DETRUITE   106

#define HAUT            201
#define BAS             202
#define DROITE          203
#define GAUCHE          204

#define IA              301
#define HUMAIN          302

#define PERSONNE        401

/** MACROS **/

#define URL "http://emeraude77.legtux.org/"

/** Linux **/

#ifdef __LINUX__
    #define CLEAR system("clear")
    #define OS "linux"
    #define PAUSE system("read -n1 -r -p "Press any key to continue..." key")
    #define SITE_WEB system("/etc/alternatives/x-www-browser http://emeraude77.legtux.org/")
#endif

/** Mac OS **/

#ifdef __APPLE__
    #define CLEAR system("clear")
    #define OS "mac os"
    #define PAUSE system("read -n1 -r -p "Press any key to continue..." key")
    #define SITE_WEB system("open http://emeraude77.legtux.org/")
#endif

/** Windows **/

#ifdef __WIN32__
    #define __WINDOWS__
#endif
#ifdef __WIN64__
    #define __WINDOWS__
#endif
#ifdef __WINDOWS__
    #define CLEAR system("cls")
    #define OS "windows"
    #define PAUSE system("pause")
    #define SITE_WEB system("start http://emeraude77.legtux.org/")
#endif

#define PAUSE system("pause")

#endif
