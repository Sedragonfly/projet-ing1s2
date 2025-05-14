#include  "generale.h"

void charger_images(t_joueur* joueur) {
    //1 a 10
    char filename[32];
    for (int i = 0; i < 11; i++) {
        sprintf(filename, "animation_volle_%d.bmp", i + 1);
        joueur->animations[i] = load_bitmap(filename, NULL);
        if (!joueur->animations[i]) {
            allegro_message("Erreur chargement %s", filename);
            exit(EXIT_FAILURE);
        }
    }

    //11
    joueur->animations[11] = load_bitmap("personage.bmp", NULL);
    if (!joueur->animations[11]) {
        allegro_message("Erreur chargement personage.bmp");
        exit(EXIT_FAILURE);
    }

    joueur->animations[12] = load_bitmap("niveau_1.bmp", NULL);
    if (!joueur->animations[12]) {
        allegro_message("Erreur chargement personage.bmp");
        exit(EXIT_FAILURE);
    }
}





