#include  "generale.h"
BITMAP *fond_menu = NULL;

void afficher_ecran_jouer() {
    BITMAP *buffer = create_bitmap(SCREEN_W, SCREEN_H);

    int bouton_x = SCREEN_W/2 - 100;
    int bouton_y = SCREEN_H/2 - 25;
    int bouton_largeur = 200;
    int bouton_hauteur = 50;

    while (!key[KEY_ESC]) {
        blit(fond_menu, buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H); // <<< Afficher fond

        rectfill(buffer, bouton_x, bouton_y, bouton_x + bouton_largeur, bouton_y + bouton_hauteur, makecol(0, 100, 200));
        rect(buffer, bouton_x, bouton_y, bouton_x + bouton_largeur, bouton_y + bouton_hauteur, makecol(255, 255, 255));
        textout_centre_ex(buffer, font, "JOUER", SCREEN_W/2, SCREEN_H/2 - 8, makecol(255, 255, 255), -1);

        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        show_mouse(screen);

        if (mouse_b & 1) {
            if (mouse_x >= bouton_x && mouse_x <= bouton_x + bouton_largeur &&
                mouse_y >= bouton_y && mouse_y <= bouton_y + bouton_hauteur) {
                rest(200);
                break;
                }
        }

        rest(10);
    }

    destroy_bitmap(buffer);
}

void demander_pseudo(char *pseudo) {
    BITMAP *buffer = create_bitmap(SCREEN_W, SCREEN_H);
    int pos = 0;
    int saisie_finie = 0;

    while (!key[KEY_ESC] && !saisie_finie) {
        // Charger l'image "psedo.bmp"
        BITMAP *psedo = load_bitmap("psedo.bmp", NULL);
        if (!psedo) {
            allegro_message("Erreur : Impossible de charger psedo.bmp !");
            // Utiliser un fond de couleur unie en cas d'erreur
            rectfill(buffer, 0, 0, SCREEN_W, SCREEN_H, makecol(0, 0, 0));
        } else {
            // Afficher l'image "psedo.bmp" si elle est chargée avec succès
            blit(psedo, buffer, 0, 0, 0, 0, psedo->w, psedo->h);
            destroy_bitmap(psedo); // Libérer la mémoire après utilisation
        }

        textout_centre_ex(buffer, font, "Entrez votre pseudo :", SCREEN_W/2, SCREEN_H/2 - 40, makecol(255, 255, 255), -1);

        int start_x = SCREEN_W/2 - (pos * 10);
        for (int i = 0; i < pos; i++) {
            char lettre[2] = {pseudo[i], '\0'};
            textout_ex(buffer, font, lettre, start_x + i * 20, SCREEN_H/2, makecol(255, 0, 0), -1);
        }

        textout_centre_ex(buffer, font, "(Appuyez sur ENTREE pour valider)", SCREEN_W/2, SCREEN_H/2 + 60, makecol(200, 200, 200), -1);

        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        show_mouse(screen);

        if (keypressed()) {
            int k = readkey() & 0xff;
            if (k >= 32 && k <= 126 && pos < MAX_PSEUDO-1) {
                pseudo[pos] = k;
                pos++;
                pseudo[pos] = '\0';
            }
            if (k == 8 && pos > 0) {
                pos--;
                pseudo[pos] = '\0';
            }
            if (k == 13 && pos > 0) {
                saisie_finie = 1;
            }
        }

        rest(10);
    }

    destroy_bitmap(buffer);
}

int pseudo_existe(const char *pseudo) {
    FILE *f = fopen("save.txt", "r");
    if (!f) {
        allegro_message("Erreur : Impossible d'ouvrir save.txt en lecture !");
        return 0;
    }

    char ligne[MAX_PSEUDO];
    while (fgets(ligne, sizeof(ligne), f)) {
        ligne[strcspn(ligne, "\r\n")] = '\0'; // Retirer \n ou \r\n
        if (strcmp(ligne, pseudo) == 0) {
            fclose(f);
            return 1; // Pseudo trouvé
        }
    }

    fclose(f);
    return 0; // Pseudo non trouvé
}



void menu_principal() {

    fond_menu = load_bitmap("decor_menu.bmp", NULL);
    if (!fond_menu) {
        allegro_message("Erreur chargement de l'image de fond !");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    char pseudo[MAX_PSEUDO] = "";
    int quitter = 0; // <<< ajouté

    afficher_ecran_jouer();

    if (key[KEY_ESC]) {
        quitter = 1;
    } else {
        demander_pseudo(pseudo);
    }

    if (quitter) {
        allegro_message("Fermeture du menu...");
        return; // quitter proprement
    }

    if (pseudo_existe(pseudo)) {
        BITMAP *buffer = create_bitmap(SCREEN_W, SCREEN_H);
        int choix = -1;

        while (choix == -1 && !key[KEY_ESC]) {

            textout_centre_ex(buffer, font, "Pseudo reconnu !", SCREEN_W/2, SCREEN_H/2 - 80, makecol(255, 255, 0), -1);

            rectfill(buffer, SCREEN_W/2 - 120, SCREEN_H/2 - 20, SCREEN_W/2 + 120, SCREEN_H/2 + 20, makecol(0, 200, 0));
            rect(buffer, SCREEN_W/2 - 120, SCREEN_H/2 - 20, SCREEN_W/2 + 120, SCREEN_H/2 + 20, makecol(255, 255, 255));
            textout_centre_ex(buffer, font, "CONTINUER", SCREEN_W/2, SCREEN_H/2 - 8, makecol(255, 255, 255), -1);

            rectfill(buffer, SCREEN_W/2 - 120, SCREEN_H/2 + 40, SCREEN_W/2 + 120, SCREEN_H/2 + 80, makecol(200, 0, 0));
            rect(buffer, SCREEN_W/2 - 120, SCREEN_H/2 + 40, SCREEN_W/2 + 120, SCREEN_H/2 + 80, makecol(255, 255, 255));
            textout_centre_ex(buffer, font, "NOUVELLE PARTIE", SCREEN_W/2, SCREEN_H/2 + 52, makecol(255, 255, 255), -1);

            blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
            show_mouse(screen);

            if (mouse_b & 1) {
                if (mouse_x >= SCREEN_W/2 - 120 && mouse_x <= SCREEN_W/2 + 120 &&
                    mouse_y >= SCREEN_H/2 - 20 && mouse_y <= SCREEN_H/2 + 20) {
                    choix = 1;
                }
                if (mouse_x >= SCREEN_W/2 - 120 && mouse_x <= SCREEN_W/2 + 120 &&
                    mouse_y >= SCREEN_H/2 + 40 && mouse_y <= SCREEN_H/2 + 80) {
                    choix = 2;
                }
                rest(200);
            }

            rest(10);
        }

        if (choix == 1) {
            char texte[100];
            sprintf(texte, "Vous continuez avec : %s", pseudo);
            allegro_message(texte);
        } else if (choix == 2) {
            char texte[100];
            sprintf(texte, "Nouvelle partie avec : %s", pseudo);
            allegro_message(texte);
        }

        destroy_bitmap(buffer);
    } else {
        char texte[100];
        sprintf(texte, "Pseudo inconnu. Nouvelle partie avec : %s", pseudo);
        allegro_message(texte);
    }

    destroy_bitmap(fond_menu);
}