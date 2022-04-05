#include <stdio.h>
#include <stdlib.h>

#include <SDL.h>
#include <SDL_image.h>

#include "headers/admin_SDL.h"


/**
 *\file admin_SDL.c
 * \brief Création du module SDL
 * \author Pierre Maël Geoffrey
 * \version 1.0
 * \date 19/04/2021
*/


/* Création de la SDL
Initialisation de la SDL.*/


/*Lancement SDL*/
void SDL_initialisation() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        SDL_ExitWithError("Initialisation SDL");
}

/*Message d'erreur:
Conceptualisation d'une circonstance d'erreur.*/

void SDL_ExitWithError(const char* message)
{
    SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}
