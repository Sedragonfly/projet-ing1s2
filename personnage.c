#include "generale.h"



void deplacement(t_joueur* joueur, BITMAP* buffer, BITMAP* animations[]) {



    float g = 0.1;
    gravite(joueur , g);
    if (key[KEY_W] && joueur->vy>-5) {
        joueur->vy -= 3*g;
        animationvolle(joueur, buffer, animations);
    }else {

    }
    if (key[KEY_A]) {
        joueur->x += 5;
    }
    if (key[KEY_D]) {
        joueur->x -= 5;
    }
    joueur->y += joueur->vy;
    printf("x: %f\n", joueur->vy);
}

void gravite(t_joueur* joueur, float g) {
    joueur->vy += g;
}