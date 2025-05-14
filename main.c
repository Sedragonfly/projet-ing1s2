#include  "generale.h"




int main() {

        allegro_init();
        install_keyboard();
        install_mouse();
        set_color_depth(desktop_color_depth());

        if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0) != 0) {
            allegro_message("Problème mode graphique");
            allegro_exit();
            exit(EXIT_FAILURE);
        }




    t_joueur joueur = {150, 300, 0, 5, 0, 0};
    t_decore decore = {0,5};



    // Buffer unique pour tout
    BITMAP *buffer = create_bitmap(SCREEN_W, SCREEN_H);
    if (!buffer) {
        allegro_message("Erreur de création du buffer");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    BITMAP *buffer2 = create_bitmap(SCREEN_W, SCREEN_H);
    if (!buffer2) {
        allegro_message("Erreur de création du buffer");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    arriere_plan_de_depar(); // Initialiser les objets de décor
    charger_images(&joueur);
    menu_principal();
    while (!key[KEY_ESC]) {
        afficher_selection_niveau(buffer);
        int niveau = gerer_selection_niveau();
        blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h); // Afficher le buffer sur l'écran
        rest(10);
        if (niveau > 0) {
            while (!key[KEY_ESC]) {
                if(niveau == 1) {
                    clear_bitmap(buffer);      // Effacer tout les buffer
                    clear_bitmap(buffer2);
                    arriere_plan(buffer);      // Dessiner le fond (arbres, oiseaux, lucioles)
                    deplacement(&joueur, buffer);  // Dessiner le personnage par-dessus le fond
                    interaction(&joueur,&decore,buffer,buffer2);
                    blit(buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h); // Afficher le buffer sur l'écran
                    rest(10);
                }
                else if (niveau == 2) {
                    clear_bitmap(buffer);      // Effacer tout les buffer
                    clear_bitmap(buffer2);

                }
                else if (niveau == 3) {


                }
            }
        }


    }
    destroy_bitmap(buffer);
    allegro_exit();
    return 0;
}END_OF_MAIN();