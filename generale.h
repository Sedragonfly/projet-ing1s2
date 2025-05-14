

#ifndef GENERALE_H
#define GENERALE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro.h>
#include <math.h>


//font 1
#define NB_TUYEAUX 4
#define LARGEUR_TUYAU 60
#define ECART_TUYAU 180
#define NB_LUCIOLES 20
#define NB_OISEAUX 5
#define NB_ARBRES 10
#define SCROLL_SPEED 1
#define MAX_PSEUDO 20

typedef struct {
    int x, direction;
    int largeur;
    int hauteur;
} Arbre;

typedef struct {
    int x, y;
    int dx, dy;
} Luciole;

typedef struct {
    int x, y;
    int dx;
} Oiseau;

Luciole lucioles[NB_LUCIOLES];
Oiseau oiseaux[NB_OISEAUX];
Arbre arbres[NB_ARBRES];



//personage
#define MAX_ANIMATIONS 100

typedef struct {
    int x;
    int y;
    float vy;
    int vx;
    int t;
    int t2;
    char etat_anim[10];  // "volle" ou "chute"
    BITMAP* animations[MAX_ANIMATIONS];  // Tableau d'images
}t_joueur;
typedef struct {
    int x;
    int vx;
}t_decore;




void charger_images(t_joueur* joueur);
void interaction(t_joueur * joueur, t_decore * decore, BITMAP * bitmap, BITMAP * buffer2);
void initialisation_allegro();
void deplacement(t_joueur* joueur, BITMAP* buffer);
void gravite(t_joueur * joueur, float x);
void animationvolle(t_joueur* joueur,BITMAP *buffer);
void animationchute(t_joueur* joueur,BITMAP *buffer);
void arriere_plan_de_depar();
void arriere_plan(BITMAP* buffer);

void initialisation_allegro();
void afficher_ecran_jouer();
void demander_pseudo(char *pseudo);
int pseudo_existe(const char *pseudo);
void menu_principal();

void afficher_selection_niveau(BITMAP *buffer);
int gerer_selection_niveau();

#endif //GENERALE_H
