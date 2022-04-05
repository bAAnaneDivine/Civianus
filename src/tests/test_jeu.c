#include <stdio.h>
#include <stdlib.h>

#include <SDL.h>
#include <SDL_image.h>

#include "../headers/admin_SDL.h"
#include "../headers/menu.h"
#include "../headers/plateau.h"
#include "../headers/structure_jeu.h"
#include "../headers/jeu.h"


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
    SDL_Texture *texture=NULL;
    SDL_Surface *image_restart=IMG_Load("image/restart.png");
    Uint32 affich_fenetre=0;

    int liste_cases[N][N];
    SDL_Rect cases[LONGUEUR_CASE][LARGEUR_CASE];

    int height = 1000;
    int width = 700;


    SDL_Rect rectangle_quit;
    rectangle_quit.x = 0;
    rectangle_quit.y = 0;
    rectangle_quit.w = LONGUEUR_CASE;
  rectangle_quit.h = LARGEUR_CASE;

    SDL_Rect rectangle_restart;
    rectangle_restart.x = LONGUEUR_CASE;
    rectangle_restart.y = 0;
    rectangle_restart.w = LONGUEUR_CASE;
    rectangle_restart.h = LARGEUR_CASE;


    int x = 0, y = 0,numx,numy;



    //Lancement SDL
    SDL_initialisation();
    window = SDL_CreateWindow("[EN COURS] DE REP@RATION", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, height, width,0);

    if (window == NULL)
        SDL_ExitWithError("Impossible de creer la fen�tre");




    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == NULL) {
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de creer le rendu");
    }

    SDL_AfficherUneImage(renderer,image_restart,texture,rectangle_restart);


    SDL_bool program_launched = SDL_TRUE;

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

                 if (x > rectangle_quit.x && x<(rectangle_quit.x + rectangle_quit.w) && y>rectangle_quit.y && y < (rectangle_quit.y + rectangle_quit.h))
                 {
                     printf("programme quitté\n");
                     program_launched = SDL_FALSE;
                 }

                if(SDL_Init(SDL_INIT_VIDEO) != 0)   /*   Lancement SDL   */
                    SDL_ExitWithError("Initialisation SDL");
                if (x > rectangle_restart.x && x<(rectangle_restart.x + rectangle_restart.w) && y>rectangle_restart.y && y < (rectangle_restart.y + rectangle_restart.h))
                    {
                      rectangle_restart.x = 0;
                      rectangle_restart.y = 0;
                      rectangle_restart.w =0;
                      rectangle_restart.h =0;
                      /*     Création de la fenêtre     */
                      crea_plat(cases);
                      affectation_cases(liste_cases,cases);

                          /*       Création du rendu de plateau     */
                      afficher_plateau(window,renderer,cases,liste_cases);
                      SDL_RenderPresent(renderer);
                      program_launched=jeu(1,window, renderer,liste_cases);

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
