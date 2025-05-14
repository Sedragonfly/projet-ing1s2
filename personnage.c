#include "generale.h"


void deplacement(t_joueur* joueur, BITMAP* buffer) {

    masked_blit(joueur->animations[11], buffer, 0, 0, joueur->x - joueur->animations[11]->w / 2,
                joueur->y - 50, joueur->animations[11]->w, joueur->animations[11]->h);

    float g = 0.3;
    gravite(joueur , g);
    if (key[KEY_W]) {
        joueur->vy -= 3 * g;
        animationvolle(joueur, buffer);
    } else {
        animationchute(joueur, buffer);
    }

    joueur->y += joueur->vy;
    printf("x: %f\n", joueur->vy);
}


void gravite(t_joueur* joueur, float g) {
    joueur->vy += g;
}