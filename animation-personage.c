#include "generale.h"

void animationvolle(t_joueur* joueur, BITMAP *buffer) {
    if (strcmp(joueur->etat_anim, "volle") != 0) {
        joueur->t = 0;
        strcpy(joueur->etat_anim, "volle");
    }

    if (joueur->t < 1) {
        masked_blit(joueur->animations[0], buffer, 0, 0, joueur->x-10 - joueur->animations[0]->w/2, joueur->y - 50, joueur->animations[0]->w, joueur->animations[0]->h);
    } else if (joueur->t < 2) {
        masked_blit(joueur->animations[1], buffer, 0, 0, joueur->x-12 - joueur->animations[1]->w/2, joueur->y - 35, joueur->animations[1]->w, joueur->animations[1]->h);
    } else if (joueur->t < 3) {
        masked_blit(joueur->animations[2], buffer, 0, 0, joueur->x-13 - joueur->animations[2]->w/2, joueur->y - 30, joueur->animations[2]->w, joueur->animations[2]->h);
    } else if (joueur->t < 4) {
        masked_blit(joueur->animations[3], buffer, 0, 0, joueur->x-12 - joueur->animations[3]->w/2, joueur->y - 35, joueur->animations[3]->w, joueur->animations[3]->h);
    } else if (joueur->t < 5) {
        masked_blit(joueur->animations[4], buffer, 0, 0, joueur->x -10 - joueur->animations[4]->w/2, joueur->y - 50, joueur->animations[4]->w, joueur->animations[4]->h);
    } else if (joueur->t < 6) {
        masked_blit(joueur->animations[5], buffer, 0, 0, joueur->x-8 - joueur->animations[5]->w/2, joueur->y - 55, joueur->animations[5]->w, joueur->animations[5]->h);
    } else if (joueur->t < 7) {
        masked_blit(joueur->animations[6], buffer, 0, 0, joueur->x-6 - joueur->animations[6]->w/2, joueur->y - 57, joueur->animations[6]->w, joueur->animations[6]->h);
    }else if ( joueur->t < 8) {
        masked_blit(joueur->animations[7], buffer, 0, 0, joueur->x-8-joueur->animations[7]->w/2, joueur->y-55, joueur->animations[7]->w, joueur->animations[7]->h);
    }
    joueur->t = (joueur->t + 1) % 8;
}




void animationchute(t_joueur* joueur, BITMAP *buffer) {
    if (strcmp(joueur->etat_anim, "chute") != 0) {
        joueur->t2 = 0;
        strcpy(joueur->etat_anim, "chute");
    }

    int chute_sequence[] = {8, 9, 10};
    int max_chute = 3;

    int frame_index = joueur->t2;
    int frame = chute_sequence[frame_index];

    int x_affiche, y_affiche;

    // Position personnalisée pour chaque frame
    if (frame == 8) {
        x_affiche = joueur->x - joueur->animations[frame]->w / 2;
        y_affiche = joueur->y - 50;
    } else if (frame == 9) {
        x_affiche = joueur->x -10 - joueur->animations[frame]->w / 2;
        y_affiche = joueur->y - 64;
    } else if (frame == 10) {
        x_affiche = joueur->x+5 - joueur->animations[frame]->w / 2;
        y_affiche = joueur->y - 70;
    }

    masked_blit(joueur->animations[frame], buffer, 0, 0,
                x_affiche, y_affiche,
                joueur->animations[frame]->w, joueur->animations[frame]->h);

    static int frame_delay = 0;
    frame_delay++;
    if (frame_delay >= 5) {
        joueur->t2++;
        frame_delay = 0;
        if (joueur->t2 >= max_chute) {
            joueur->t2 = max_chute - 1; // rester sur la dernière image
        }
    }
}