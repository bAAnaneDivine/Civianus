

#include <stdio.h>
#include <stdlib.h>

#include <SDL.h>
#include <SDL_image.h>

#include "../headers/admin_SDL.h"
#include "../headers/menu.h"
#include "../headers/plateau.h"
#include "../headers/structure_jeu.h"



/**
 *\file main.c
 * \brief Programme principal
 * \author Pierre Maël Cyprien
 * \version 1.0
 * \date 01/02/2022
*/

/// Main principal :
///
/// Initialisation des variables telles que la hauteur et la largeur, nécessaires à la taille de la fenêtre. Ensuite initialisation de chaque rectangle que ce soit pour les boutons, le personnage et le rendu. \n
/// Création d'une fenêtre et d'un rendu. \n
/// Appel des fonctions des autres fichiers. \n
/// Condition pour garder la fenêtre ouverte, attente des événements résultants du joueur.

//gcc src/main.c -o bin/main -I include -L lib -lmingw32 -lSDL2main -lSDL2 -mwindows


int main(int argc, char* argv[])
{
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    Uint32 affich_fenetre=0;

    int liste_cases[N][N];
    SDL_Rect cases[N][N];

    int height = 1000;
    int width = 700;

    SDL_Rect fenetre_surface;
    fenetre_surface.x = 0;
    fenetre_surface.y = 0;
    fenetre_surface.w = height;
    fenetre_surface.h = width;

    SDL_Rect rectangle_restart;
    rectangle_restart.x = (height / 2 / 1.5);
    rectangle_restart.y = (width / 3 * 2);
    rectangle_restart.w = 100;
    rectangle_restart.h = 50;

    SDL_Rect rectangle_quit;
    rectangle_quit.x = (height / 2 * 1);
    rectangle_quit.y = (width / 3 * 2);
    rectangle_quit.w = 100;
    rectangle_quit.h = 50;

    SDL_Rect rect_trajan;
    rect_trajan.x = 100;
    rect_trajan.y = 50;
    rect_trajan.w = 128;
    rect_trajan.h = 128;

    SDL_Rect rect_pierre;
    rect_pierre.x = 400;
    rect_pierre.y = 50;
    rect_pierre.w = 128;
    rect_pierre.h = 128;

    SDL_Rect rectangle_save;
    rectangle_save.x = 0;
    rectangle_save.y = 0;
    rectangle_save.w = 0;
    rectangle_save.h = 0;

    SDL_Rect rectangle_jeu;
    rectangle_jeu.x = 0;
    rectangle_jeu.y = 0;
    rectangle_jeu.w = 0;
    rectangle_jeu.h = 0;

    int x = 0, y = 0,numx,numy;


    //Lancement SDL
    SDL_initialisation();
    window = SDL_CreateWindow("test_plateau", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, height, width,0);

    if (window == NULL)
        SDL_ExitWithError("Impossible de creer la fen�tre");




    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == NULL) {
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de creer le rendu");
    }

    SDL_RenderPresent(renderer);

    SDL_bool program_launched = SDL_TRUE;

    SDL_Surface* image_restart=IMG_Load("./image/restart.png");
    SDL_Texture * texture=NULL;
SDL_AfficherUneImage(renderer,image_restart,texture,rectangle_restart);

    while (program_launched) {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                program_launched = SDL_FALSE;
                break;

            case SDL_MOUSEBUTTONDOWN: // Relâchement d'un clique
                 x = event.button.x;  //récupération de la position de la souris
                 y = event.button.y;

                printf("coord : x=%d, y=%d \n", x, y);
                numx = click_case_x(x);
                numy = click_case_y(y);
                printf("case : i=%d, j=%d \n", numx, numy);


                if ((x > rectangle_restart.x && x<(rectangle_restart.x + rectangle_restart.w) && y>rectangle_restart.y && y < (rectangle_restart.y + rectangle_restart.h)) && program_launched)
                {
                   SDL_RenderClear(renderer);

                        rectangle_restart.x = 0;
                        rectangle_restart.y = 0;
                        rectangle_restart.w = 0;
                        rectangle_restart.h = 0;

                        rectangle_quit.x = 0;
                        rectangle_quit.y = 0;
                        rectangle_quit.w = LARGEUR_CASE;
                        rectangle_quit.h = LONGUEUR_CASE;

                        rectangle_save.x = LONGUEUR_CASE;
                        rectangle_save.y = 0;
                        rectangle_save.w = LARGEUR_CASE;
                        rectangle_save.h = LONGUEUR_CASE;

                        rectangle_jeu.x = 0;
                        rectangle_jeu.y = LARGEUR_CASE;
                        rectangle_jeu.w = width-LARGEUR_CASE;
                        rectangle_jeu.h = height-LONGUEUR_CASE;

                        if(SDL_Init(SDL_INIT_VIDEO) != 0)   /*   Lancement SDL   */
                            SDL_ExitWithError("Initialisation SDL");
                        /*     Création de la fenêtre     */
                        crea_plat(cases);
                        affectation_cases(liste_cases,cases);

                            /*       Création du rendu de plateau     */
                        afficher_plateau(window,renderer,cases,liste_cases);
                        SDL_RenderPresent(renderer);



                }
                else if (x > rectangle_quit.x && x<(rectangle_quit.x + rectangle_quit.w) && y>rectangle_quit.y && y < (rectangle_quit.y + rectangle_quit.h))
                {
                    printf("programme quitté");
                    program_launched = SDL_FALSE;
                }
                break;

            default:
                break;
            }
        }
    }



    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;

}
