#include <stdio.h>
#include <stdlib.h>

#include <SDL.h>
#include <SDL_image.h>

#include "admin_SDL.h"
#include "jeu.h"
#include "fenetre.h"
#include "menu.h"

/**
 *\file jeu.c 
 * \brief Gestion du personnage
 * \author Pierre Maël Geoffrey
 * \version 1.0
 * \date 19/04/2021
*/



/// Déplacement :
///
/// Reconnaissance des touches du joueur.

void deplacer(SDL_Event event, SDL_Rect* rectangle_pers) {


        switch (event.key.keysym.sym) {

        case SDLK_LEFT:
            if (rectangle_pers->x > 0) {
                rectangle_pers->x -= 10;
            }
            break;

        case SDLK_RIGHT:
            if (rectangle_pers->x < 766) {
                rectangle_pers->x += 10;
            }
            break;

        case SDLK_UP:
            if (rectangle_pers->y > 0) {
                rectangle_pers->y -= 10;
            }
            break;

        case SDLK_DOWN:
            if (rectangle_pers->y < 416) {
                rectangle_pers->y += 10;
            }
            break;
        }
    
}









