#include  "generale.h"





void dessiner_fond(BITMAP* buffer) {
    // Fond plus clair, ambiance nuit douce
    rectfill(buffer, 0, 0, SCREEN_W, SCREEN_H, makecol(50, 70, 110));
}

void dessiner_arbre_courbe(BITMAP* buffer, Arbre* a) {
    int i;
    float courbe = (a->direction == 0) ? -0.5f : 0.5f;

    int px = a->x;
    int py = SCREEN_H;

    for (i = 0; i < a->hauteur; i++) {
        int nx = a->x + (int)(sin(i * 0.1f) * courbe * i / 8.0f);
        int ny = SCREEN_H - i;
        line(buffer, px, py, nx, ny, makecol(80, 50, 30));
        px = nx;
        py = ny;
    }

    // Feuillage doux et stylé au sommet
    circlefill(buffer, px, py - 5, 15 + rand() % 10, makecol(40, 130 + rand() % 80, 60 + rand() % 40));
}

void dessiner_lucioles(Luciole lucioles[], BITMAP* buffer) {
    int i;
    for (i = 0; i < NB_LUCIOLES; ++i) {
        lucioles[i].x += lucioles[i].dx;
        lucioles[i].y += lucioles[i].dy;

        if (lucioles[i].x < 0) lucioles[i].x = SCREEN_W;
        if (lucioles[i].x > SCREEN_W) lucioles[i].x = 0;
        if (lucioles[i].y < 0 || lucioles[i].y > SCREEN_H) lucioles[i].dy *= -1;

        int clignote = 200 + rand() % 55;
        circlefill(buffer, lucioles[i].x, lucioles[i].y, 2, makecol(clignote, clignote, 120));
    }
}

void dessiner_oiseaux(Oiseau oiseaux[], BITMAP* buffer) {
    int i;
    for (i = 0; i < NB_OISEAUX; ++i) {
        oiseaux[i].x += oiseaux[i].dx - SCROLL_SPEED;

        if (oiseaux[i].x > SCREEN_W) {
            oiseaux[i].x = -20;
            oiseaux[i].y = rand() % 150 + 20;
        }

        // Forme "V"
        line(buffer, oiseaux[i].x, oiseaux[i].y, oiseaux[i].x + 5, oiseaux[i].y - 5, makecol(230, 230, 230));
        line(buffer, oiseaux[i].x + 5, oiseaux[i].y - 5, oiseaux[i].x + 10, oiseaux[i].y, makecol(230, 230, 230));
    }
}


void arriere_plan_de_depar() {
    int i;

    // Init lucioles
    for (i = 0; i < NB_LUCIOLES; ++i) {
        lucioles[i].x = rand() % SCREEN_W;
        lucioles[i].y = rand() % SCREEN_H;
        lucioles[i].dx = (rand() % 3) - 1;
        lucioles[i].dy = (rand() % 3) - 1;
    }

    // Init oiseaux
    for (i = 0; i < NB_OISEAUX; ++i) {
        oiseaux[i].x = rand() % SCREEN_W;
        oiseaux[i].y = rand() % 150 + 20;
        oiseaux[i].dx = 1 + rand() % 2;
    }

    // Init arbres
    for (i = 0; i < NB_ARBRES; ++i) {
        arbres[i].x = i * (SCREEN_W / NB_ARBRES) + rand() % 50;
        arbres[i].direction = rand() % 2;
        arbres[i].largeur = 8 + rand() % 5;
        arbres[i].hauteur = 250 + rand() % 100;
    }
}

void arriere_plan(BITMAP* buffer) {
    int i;


    dessiner_fond(buffer);

    // Défilement des arbres
    for (i = 0; i < NB_ARBRES; ++i) {
        arbres[i].x -= SCROLL_SPEED;
        if (arbres[i].x < -50) {
            arbres[i].x = SCREEN_W + rand() % 100;
            arbres[i].direction = rand() % 2;
            arbres[i].largeur = 8 + rand() % 5;
            arbres[i].hauteur = 250 + rand() % 100;
        }
        dessiner_arbre_courbe(buffer, &arbres[i]);
    }

    dessiner_oiseaux(oiseaux, buffer);
    dessiner_lucioles(lucioles, buffer);

}