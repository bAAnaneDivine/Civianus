#include <stdio.h>
#include <stdlib.h>

#include <SDL.h>
#include <SDL_image.h>

#include "admin_SDL.h"
#include "fenetre.h"
#include "menu.h"

/**
 *\file main.c 
 * \brief Programme principal
 * \author Pierre Maël Cyprien
 * \version 1.0
 * \date 19/04/2021
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
    
    int const height = 800;
    int const width = 450;


    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    SDL_Rect rectangle_pers;
    rectangle_pers.x = 1;
    rectangle_pers.y = 1;

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

    int x = 0, y = 0;


    //Lancement SDL
    SDL_initialisation();

    window = SDL_CreateWindow("[EN COURS] DE REP@RATION", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, height, width, 0);

    if (window == NULL)
        SDL_ExitWithError("Impossible de creer la fen�tre");




    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == NULL) {
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de creer le rendu");
    }

    menu(window, renderer, rectangle_restart, rectangle_quit);
    SDL_RenderPresent(renderer);

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
                while ((x > rectangle_restart.x && x<(rectangle_restart.x + rectangle_restart.w) && y>rectangle_restart.y && y < (rectangle_restart.y + rectangle_restart.h)) && program_launched)
                {
                    /*SDL_DestroyRenderer(renderer);
                    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
                    fenetre(window, renderer);
                    SDL_RenderPresent(renderer);*/
                    menu_select(window, renderer, x, y);
                    SDL_RenderPresent(renderer);



                    while (SDL_PollEvent(&event))
                    {
                        switch (event.type)
                        {
                        case SDL_KEYDOWN:
                            fenetre(window, renderer);
                            SDL_RenderPresent(renderer);
                            break;

                        case SDL_QUIT:
                            program_launched = SDL_FALSE;
                            break;

                        default:
                            break;
                        }
                    }
                }
                if (x > rectangle_quit.x && x<(rectangle_quit.x + rectangle_quit.w) && y>rectangle_quit.y && y < (rectangle_quit.y + rectangle_quit.h))
                {
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
