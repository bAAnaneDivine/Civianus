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

    int height = 800;
    int width = 450;

    SDL_Rect rect_fond;
    rect_fond.x = 0;
    rect_fond.y = 0;
    rect_fond.w = height;
    rect_fond.h = width;

    SDL_Rect rect_trajan;
    rect_trajan.x = 100;
    rect_trajan.y = 50;
    rect_trajan.w = 50;
    rect_trajan.h = 50;

    SDL_Rect rect_pierre;
    rect_pierre.x = 100;
    rect_pierre.y = 100;
    rect_pierre.w = 50;
    rect_pierre.h = 50;



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
    menu_select(window, renderer, rect_trajan, rect_pierre, rect_fond);
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
