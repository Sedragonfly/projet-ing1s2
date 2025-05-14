#include "generale.h"

#define LARGEUR_ECRAN 800
#define HAUTEUR_ECRAN 600

void dessiner_rectangle_arrondi(BITMAP *buffer, int x1, int y1, int x2, int y2, int rayon, int couleur) {
    // Dessiner les cercles aux coins
    circlefill(buffer, x1 + rayon, y1 + rayon, rayon, couleur); // Haut gauche
    circlefill(buffer, x2 - rayon, y1 + rayon, rayon, couleur); // Haut droite
    circlefill(buffer, x1 + rayon, y2 - rayon, rayon, couleur); // Bas gauche
    circlefill(buffer, x2 - rayon, y2 - rayon, rayon, couleur); // Bas droite

    // Dessiner les rectangles pour relier les cercles
    rectfill(buffer, x1 + rayon, y1, x2 - rayon, y2, couleur); // Centre horizontal
    rectfill(buffer, x1, y1 + rayon, x2, y2 - rayon, couleur); // Centre vertical
}

void afficher_selection_niveau(BITMAP *buffer) {
    // Charger l'image de fond
    BITMAP *background = load_bitmap("background.bmp", NULL);
    if (background) {
        blit(background, buffer, 0, 0, 0, 0, LARGEUR_ECRAN, HAUTEUR_ECRAN);
    }

    dessiner_rectangle_arrondi(buffer, 80, 250, 187, 350, 20, makecol(255, 165, 0));  // Niveau 1
    dessiner_rectangle_arrondi(buffer, 347, 250, 453, 350, 20, makecol(255, 165, 0)); // Niveau 2
    dessiner_rectangle_arrondi(buffer, 613, 250, 720, 350, 20, makecol(255, 165, 0)); // Niveau 3

    // Créer une surface temporaire transparente pour les chiffres
    BITMAP *temp = create_bitmap(20, 20);
    clear_to_color(temp, makecol(255, 0, 255)); // Couleur de transparence

    // Activer la transparence pour la couleur de fond (255, 0, 255)
    set_trans_blender(0, 0, 0, 0);

    // Dessiner les chiffres en blanc, centrés verticalement
    textout_centre_ex(temp, font, "1", 12, 12, makecol(255, 255, 255), makecol(255, 0, 255));
    stretch_sprite(buffer, temp, 80, 230, 100, 100); // Niveau 1 (rectangle)

    clear_to_color(temp, makecol(255, 0, 255));
    textout_centre_ex(temp, font, "2", 12, 12, makecol(255, 255, 255), makecol(255, 0, 255));
    stretch_sprite(buffer, temp, 350, 230, 100, 100); // Niveau 2 (rectangle)

    clear_to_color(temp, makecol(255, 0, 255));
    textout_centre_ex(temp, font, "3", 12, 12, makecol(255, 255, 255), makecol(255, 0, 255));
    stretch_sprite(buffer, temp, 625, 230, 100, 100); // Niveau 3 (rectangle)

    destroy_bitmap(temp);
}

int gerer_selection_niveau() {
    if (mouse_b & 1) { // Si clic gauche
        if (mouse_x >= 50 && mouse_x <= 250 && mouse_y >= 220 && mouse_y <= 360)
            return 1;
        else if (mouse_x >= 300 && mouse_x <= 500 && mouse_y >= 220 && mouse_y <= 360)
            return 2;
        else if (mouse_x >= 550 && mouse_x <= 750 && mouse_y >= 220 && mouse_y <= 360)
            return 3;
    }
    return 0;
}