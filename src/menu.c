#include <stdio.h>
#include <stdlib.h>

#include <SDL.h>
#include <SDL_image.h>

#include "admin_SDL.h"
#include "fenetre.h"
#include "menu.h"

/**
 *\file menu.c 
 * \brief Création du menu de jeu
 * \author Pierre Maël Cyprien 
 * \version 1.0
 * \date 19/04/2021
*/


/// Création du menu :
///
/// Téléchargement de l'image de fond du menu. \n
/// Elaboration de deux rectangles dans lesquels ont été insérés les images des boutons "restart" et "quit"



void menu(SDL_Window* window, SDL_Renderer* renderer, SDL_Rect rectangle_restart, SDL_Rect rectangle_quit) {

    int const longueur_fenetre = 800;
    int const largeur_fenetre = 450;

    SDL_Surface* bouton_restart = NULL;
    SDL_Texture* bouton_restart_texture = NULL;

    SDL_Texture* bouton_quit_texture = NULL;
    SDL_Surface* bouton_quit = NULL;

    SDL_Rect rectangle_pers;
    rectangle_pers.x = 1;
    rectangle_pers.y = 1;


    SDL_Surface* fond = SDL_LoadBMP("./image/fond.bmp");
    SDL_Texture* fond_Texture = SDL_CreateTextureFromSurface(renderer, fond);

    SDL_Rect fenetre_surface = { 0,0,longueur_fenetre , largeur_fenetre };

    SDL_RenderCopy(renderer, fond_Texture, NULL, &fenetre_surface); // Copie du sprite grâce au SDL_Renderer
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); //couleurs rouge


    SDL_RenderFillRect(renderer, &rectangle_restart);
    SDL_RenderFillRect(renderer, &rectangle_quit);


    bouton_restart = SDL_LoadBMP("./image/restart.bmp"); //chargement de l'image du bouton restart

    if (bouton_restart == NULL) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de charger l'image");
    }

    bouton_restart_texture = SDL_CreateTextureFromSurface(renderer, bouton_restart);
    SDL_FreeSurface(bouton_restart);

    if (bouton_restart_texture == NULL) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de creer le bonton quitter");
    }

    if (SDL_RenderCopy(renderer, bouton_restart_texture, NULL, &rectangle_restart) != 0)
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible d'afficher la texture");
    }

    SDL_RenderPresent(renderer);

    bouton_quit = SDL_LoadBMP("./image/quit.bmp");       //chargement de l'image du bouton quitter

    if (bouton_quit == NULL) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de charger l'image");
    }

    bouton_quit_texture = SDL_CreateTextureFromSurface(renderer, bouton_quit);
    SDL_FreeSurface(bouton_quit);

    if (bouton_quit == NULL) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de creer le bonton quitter");
    }

    if (SDL_RenderCopy(renderer, bouton_quit_texture, NULL, &rectangle_quit) != 0)
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible d'afficher la texture");
    }
    SDL_RenderPresent(renderer);
}

void menu_select(SDL_Window* window, SDL_Renderer* renderer, int x, int y) { // faire la liste des civilisations disponibles + leur descrition et retourner la coordonnée du click souris pour sélectionner la civ 
   
    SDL_Surface* trajan = NULL;
    SDL_Texture* trajan_texture = NULL;
    SDL_Rect rect_trajan = { 100,50, 128 , 128 };
    trajan = SDL_LoadBMP("./image/trajan.bmp");
    trajan_texture = SDL_CreateTextureFromSurface(renderer, trajan);
    SDL_FreeSurface(trajan);
    SDL_RenderCopy(renderer, trajan_texture, NULL, &rect_trajan);
    SDL_RenderPresent(renderer);

    /*SDL_Texture* pierre_texture = NULL;
    SDL_Surface* pierre = NULL;
    pierre = SDL_LoadBMP("./image/pierreII.bmp");*/

    
}



