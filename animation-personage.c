#include "generale.h"

void animationvolle(t_joueur* joueur,BITMAP *buffer,BITMAP *animations[8]) {

    if (joueur->t>=0 && joueur->t<3) {

        masked_blit(animations[0], buffer, 0, 0, 420-animations[0]->w/2, joueur->y-160, animations[0]->w, animations[0]->h);
    }
    if (joueur->t>=3 && joueur->t<6) {

        masked_blit(animations[1], buffer, 0, 0, 418-animations[1]->w/2, joueur->y-145, animations[1]->w, animations[1]->h);
    }
    if (joueur->t>=6 && joueur->t<9) {

        masked_blit(animations[2], buffer, 0, 0, 417-animations[2]->w/2, joueur->y-140, animations[2]->w, animations[2]->h);
    }
    if (joueur->t>=9 && joueur->t<12) {

        masked_blit(animations[3], buffer, 0, 0, 418-animations[3]->w/2, joueur->y-145, animations[3]->w, animations[3]->h);
    }
    if (joueur->t>=12 && joueur->t<15) {

        masked_blit(animations[4], buffer, 0, 0, 420-animations[4]->w/2, joueur->y-160, animations[4]->w, animations[4]->h);
    }
    if (joueur->t>=15 && joueur->t<18) {

        masked_blit(animations[5], buffer, 0, 0, 422-animations[5]->w/2, joueur->y-165, animations[5]->w, animations[5]->h);
    }
    if (joueur->t>=18 && joueur->t<21) {

        masked_blit(animations[6], buffer, 0, 0, 424-animations[6]->w/2, joueur->y-167, animations[6]->w, animations[6]->h);
    }
    if (joueur->t>=21 && joueur->t<24) {

        masked_blit(animations[7], buffer, 0, 0, 422-animations[7]->w/2, joueur->y-165, animations[7]->w, animations[7]->h);
    }
    joueur->t = (joueur->t + 1) % 24;
}

void animationchute(t_joueur* joueur,BITMAP *buffer,BITMAP *animations[8]) {
    
}