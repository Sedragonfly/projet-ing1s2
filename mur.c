#include "generale.h"


void solle(t_joueur *joueur, t_decore *decore, BITMAP *buffer, BITMAP *buffer2, int rayon);
void mur(t_joueur *joueur, t_decore *decore, BITMAP *buffer, BITMAP *buffer2, int rayon);
void plafon(t_joueur *joueur, t_decore *decore, BITMAP *buffer, BITMAP *buffer2, int rayon);


void interaction(t_joueur *joueur, t_decore *decore, BITMAP *buffer, BITMAP *buffer2) {
    decore->x = decore->x - decore->vx;
    int rayon = 30;

    masked_blit(joueur->animations[12], buffer2, 0, 0, decore->x, 0, joueur->animations[12]->w, joueur->animations[12]->h);



    // Dessiner le cercle rouge sur buffer2
    circlefill(buffer2, joueur->x , joueur->y , rayon, makecol(255, 0, 0));
    mur(joueur, decore, buffer, buffer2, rayon);
    solle(joueur, decore, buffer, buffer2, rayon);
    plafon(joueur, decore, buffer, buffer2, rayon);
}

void mur(t_joueur *joueur, t_decore *decore, BITMAP *buffer, BITMAP *buffer2, int rayon) {




    // Copier les zones bleues en noir sur buffer
    for (int i = 0; i < buffer2->w; i++) {
        for (int j = 0; j < buffer2->h; j++) {
            int couleur = getpixel(buffer2, i, j);
            if (getr(couleur) == 0 && getg(couleur) == 0 && getb(couleur) == 255) {
                putpixel(buffer, i, j, makecol(0, 0, 0));
            }
        }
    }

    // Parcourir la zone autour du cercle
    for (int i = -rayon; i <= rayon; i++) {
        for (int j = -rayon; j <= rayon; j++) {
            int px = joueur->x + i ;
            int py = joueur->y + j ;

            // Vérifier que le point est dans l'image
            if (px >= 0 && px < buffer2->w && py >= 0 && py < buffer2->h) {
                int couleur = getpixel(buffer2, px, py);

                // Si la couleur est bleue (0,0,255), déplacer à gauche (corrigé)
                if (getr(couleur) == 0 && getg(couleur) == 0 && getb(couleur) == 255) {
                    joueur->x -= 5; // Déplacement à gauche
                }
            }
        }
    }
}

void solle(t_joueur *joueur, t_decore *decore, BITMAP *buffer, BITMAP *buffer2, int rayon) {


    // Copier le vert en noir sur buffer
    for (int i = 0; i < buffer2->w; i++) {
        for (int j = 0; j < buffer2->h; j++) {
            int color = getpixel(buffer2, i, j);
            if (getg(color) == 255 && getr(color) == 0 && getb(color) == 0) {
                putpixel(buffer, i, j, makecol(0, 0, 0));
            }
        }
    }

    // Détection de collision avec le sol
    for (int i = -rayon; i <= rayon; i++) {
        for (int j = -rayon; j <= rayon; j++) {
            int px = joueur->x + i;
            int py = joueur->y + j;

            if (px >= 0 && px < buffer2->w && py >= 0 && py < buffer2->h) {
                int couleur = getpixel(buffer2, px, py);

                // Vérifier la collision avec la couleur verte (le sol)
                if (getg(couleur) == 255 && getr(couleur) == 0 && getb(couleur) == 0) {
                    // Arrêter la chute
                    joueur->vy = -1; // Bloquer la vitesse verticale


                    joueur->y += joueur->vy ; // Positionner juste au-dessus du sol
                    return;
                }
            }
        }
    }
}
void plafon(t_joueur *joueur, t_decore *decore, BITMAP *buffer, BITMAP *buffer2, int rayon) {
    // Copier la couleur (R=0, G=255, B=225) en noir sur buffer
    for (int i = 0; i < buffer2->w; i++) {
        for (int j = 0; j < buffer2->h; j++) {
            int color = getpixel(buffer2, i, j);
            if (getr(color) == 0 && getg(color) == 255 && getb(color) == 255) {
                putpixel(buffer, i, j, makecol(0, 0, 0)); // Remplacer par noir
            }
        }
    }

    // Détection de collision avec la couleur (R=0, G=255, B=225) du plafond
    for (int i = -rayon; i <= rayon; i++) {
        for (int j = -rayon; j <= rayon; j++) {
            int px = joueur->x + i;
            int py = joueur->y + j;

            // Vérifier que le pixel est dans les limites de buffer2
            if (px >= 0 && px < buffer2->w && py >= 0 && py < buffer2->h) {
                int couleur = getpixel(buffer2, px, py);

                // Vérifier la collision avec la couleur du plafond
                if (getr(couleur) == 0 && getg(couleur) == 255 && getb(couleur) == 255) {
                    // Si collision avec le plafond, arrêter la montée
                    joueur->vy = 4;  // Bloquer la vitesse verticale
                    joueur->y = py + rayon;  // Positionner juste en dessous du plafond
                    return;
                }
            }
        }
    }
}