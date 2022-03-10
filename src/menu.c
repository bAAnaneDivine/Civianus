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
 * \date 01/02/2022
*/


/// Création du menu :
///
/// Téléchargement de l'image de fond du menu. \n
/// Elaboration de deux rectangles dans lesquels ont été insérés les images des boutons "restart" et "quit"

void menu(SDL_Window* window, SDL_Renderer* renderer, SDL_Rect rectangle_restart, SDL_Rect rectangle_quit, SDL_Rect fenetre_surface) {

    SDL_Surface* bouton_restart = NULL;
    SDL_Texture* bouton_restart_texture = NULL;

    SDL_Texture* bouton_quit_texture = NULL;
    SDL_Surface* bouton_quit = NULL;

    int height = 800;
    int width = 450;

    SDL_RenderFillRect(renderer, &fenetre_surface);

    SDL_Surface* fond = SDL_LoadBMP("./image/fond.bmp");
    SDL_Texture* fond_Texture = SDL_CreateTextureFromSurface(renderer, fond);

    SDL_FreeSurface(fond);

    SDL_RenderCopy(renderer, fond_Texture, NULL, &fenetre_surface); // Copie du sprite grâce au SDL_Renderer
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); //couleur blanc

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

    if (bouton_quit_texture == NULL) {
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

void menu_select(SDL_Window* window, SDL_Renderer* renderer, SDL_Rect rect_trajan, SDL_Rect rect_pierre, SDL_Rect rect_fond)
{ // faire la liste des civilisations disponibles + leur descrition et retourner la coordonnée du click souris pour sélectionner la civ 


    SDL_Surface* fond_image = NULL;
    SDL_Texture* fond_texture = NULL;

    SDL_Surface* trajan_image = NULL;
    SDL_Texture* trajan_texture = NULL;

    SDL_Surface* pierre_image = NULL;
    SDL_Texture* pierre_texture = NULL;

    SDL_RenderFillRect(renderer, &rect_fond);

    fond_image = SDL_LoadBMP("./image/fond.bmp");       //chargement de l'image du fond

    if (fond_image == NULL) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de charger l'image");
    }

    fond_texture = SDL_CreateTextureFromSurface(renderer, fond_image);
    SDL_FreeSurface(fond_image);

    if (fond_texture == NULL) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de creer le bonton quitter");
    }

    if (SDL_RenderCopy(renderer, fond_texture, NULL, &rect_fond) != 0)
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible d'afficher la texture");
    }



    trajan_image = SDL_LoadBMP("./image/trajan.bmp");       //chargement de l'image du bouton quitter

    if (trajan_image == NULL) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de charger l'image");
    }

    trajan_texture = SDL_CreateTextureFromSurface(renderer, trajan_image);
    SDL_FreeSurface(trajan_image);

    if (trajan_texture == NULL) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de creer le bonton quitter");
    }

    if (SDL_RenderCopy(renderer, trajan_texture, NULL, &rect_trajan) != 0)
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible d'afficher la texture");
    }

   
    
    
    
    pierre_image = SDL_LoadBMP("./image/pierre1er.bmp");       //chargement de l'image du bouton quitter

    if (pierre_image == NULL) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de charger l'image");
    }

    pierre_texture = SDL_CreateTextureFromSurface(renderer, pierre_image);
    SDL_FreeSurface(pierre_image);

    if (pierre_texture == NULL) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de creer le bonton quitter");
    }

    if (SDL_RenderCopy(renderer, pierre_texture, NULL, &rect_pierre) != 0)
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible d'afficher la texture");
    }
    SDL_RenderPresent(renderer);



}



