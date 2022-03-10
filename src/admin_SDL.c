#include <stdio.h>
#include <stdlib.h>

#include <SDL.h>
#include <SDL_image.h>
//#include <SDL_ttf.h>

#include "admin_SDL.h"


/**
 *\file admin_SDL.c 
 * \brief Création du module SDL
 * \author Pierre Maël Cyprien
 * \version 1.0
 * \date 01/02/2022
*/


/// Création de la SDL :
///
/// Initialisation de la SDL.


//Lancement SDL
void SDL_initialisation() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        SDL_ExitWithError("Initialisation SDL");
}

/// Message d'erreur:
///
/// Conceptualisation d'une circonstance d'erreur. 

void SDL_ExitWithError(const char* message)
{
    SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}


/// Affichage d'un texte:

SDL_Texture* createText(SDL_Renderer* renderer, TTF_Font* font, char text[], SDL_Color* color) {
    SDL_Surface* text_img = TTF_RenderText_Solid(font, text, color);
    SDL_Texture* text_tex = SDL_CreateTextureFromSurface(renderer, text_img);

    SDL_FreeSurface(text_img);
    return text_tex;
}
