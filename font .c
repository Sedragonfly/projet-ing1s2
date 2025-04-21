#include  "generale.h"
void arriere_plan(t_joueur* joueur, BITMAP *image[],BITMAP *buffer) {
    if (!image[1]) return;
    blit(image[1],buffer, 0, 0, joueur->x-400, 0, 800, 600);
    blit(image[0], buffer, 0, 0, joueur->x+400, 0, 800, 600);
}