#include  "generale.h"

void initialisation_allegro();




int main() {
    BITMAP *image_bleu;
    BITMAP *image_violet;
    BITMAP *image_personage;
    srand(time(NULL));

    // Lancer allegro et le mode graphique
    allegro_init();
    install_keyboard();
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    image_bleu=load_bitmap("bleu.bmp",NULL);
    image_violet=load_bitmap("violet.bmp",NULL);
    image_personage=load_bitmap("personage.bmp",NULL);
    BITMAP *image[]={image_bleu,image_violet};
    BITMAP *animations[11];
    char filename[32];
    for (int i = 0; i < 11; i++) {
        sprintf(filename, "animation_volle_%d.bmp", i + 1);
        animations[i] = load_bitmap(filename, NULL);
        if (!animations[i]) {
            allegro_message("Erreur chargement %s", filename);
            exit(EXIT_FAILURE);
        }
    }
    t_joueur joueur = {400, 300, 0, 0, 0};



    BITMAP *buffer=create_bitmap(SCREEN_W,SCREEN_H);
    while (!key[KEY_ESC]) {


        clear_bitmap(buffer);
        arriere_plan(&joueur,image,buffer);

        masked_blit(image_personage, buffer, 0, 0, 430-image_personage->w/2, joueur.y-160, image_personage->w, image_personage->h);
        deplacement(&joueur, buffer, animations);
        blit(buffer,screen,0,0,0,0,buffer->w,buffer->h);
        rest(10);
    }



    //quand on a plus besoin de la bitmap, on la détruit

    destroy_bitmap(image_bleu);
    destroy_bitmap(image_violet);
    allegro_exit();
    return 0;
}END_OF_MAIN();

void initialisation_allegro() {
    allegro_init(); // appel obligatoire (var.globales, recup. infos syst me ...)
    install_keyboard(); //pour utiliser le clavier
    install_mouse(); //pour utiliser la souris
    //pour choisir la profondeur de couleurs (8,16,24 ou 32 bits)
    set_color_depth(desktop_color_depth()); //ici : identique à celle du bureau

    //sélection du mode graphique
    // avec choix d'un driver+mode+résolution de l'écran
    /// si échec, le programme s'arrête
    if(set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0)
    {
        allegro_message("probleme mode graphique");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
}
