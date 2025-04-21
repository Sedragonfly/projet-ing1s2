

#ifndef GENERALE_H
#define GENERALE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro.h>

#define GROUND_Y      550



typedef struct {
    int x;
    int y;
    float vy;
    int vx;
}t_joueur;
int main();
void initialisation_allegro();
void deplacement(t_joueur*joueur);
void arriere_plan(t_joueur* joueur, BITMAP *image[], BITMAP *buffer);
#endif //GENERALE_H
