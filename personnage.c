#include "generale.h"



void deplacement(t_joueur* joueur, BITMAP* buffer, BITMAP* animations[]){
    BITMAP *image_personage;
    image_personage=load_bitmap("personage.bmp",NULL);
    masked_blit(image_personage, buffer, 0, 0, joueur->x+10-image_personage->w/2, joueur->y-160, image_personage->w, image_personage->h);


    float g = 0.1;
    gravite(joueur , g);
    if (key[KEY_W] ) {
        joueur->vy -= 3*g;
        animationvolle(joueur, buffer, animations);
    }else {
        animationchute(joueur, buffer, animations);
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