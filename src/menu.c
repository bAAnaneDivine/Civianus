#include <stdio.h>
#include <stdlib.h>

#include <SDL.h>
#include <SDL_image.h>

#include "./headers/admin_SDL.h"
#include "./headers/menu.h"


/**
 *\file menu.c
 * \brief Création du menu de jeu
 * \author Pierre Maël
 * \version 1.0
 * \date 01/02/2022
*/

/**
* \fn void menu(SDL_Window* window, SDL_Renderer* renderer, SDL_Rect rectangle_restart, SDL_Rect rectangle_continuer, SDL_Rect rectangle_quit, SDL_Rect fenetre_surface)
* \param window Pointeur sur un objet de type SDL_Window
* \param renderer Pointeur sur un objet de type SDL_Renderer
* \param rectangle_restart Rectangle objet de type SDL_Rect déjà initialisé
* \param rectangle_continuer Rectangle objet de type SDL_Rect déjà initialisé
* \param rectangle_quit Rectangle objet de type SDL_Rect déjà initialisé
* \param fenetre_surface Récupération d'une surface déjà initialisée
* \brief Elaboration de trois rectangles dans lesquels ont été insérés les images des boutons "restart", "continuer" et "quit"
*/


void menu(SDL_Window* window, SDL_Renderer* renderer, SDL_Rect rectangle_restart, SDL_Rect rectangle_continuer, SDL_Rect rectangle_quit, SDL_Rect fenetre_surface) {

    SDL_Surface* bouton_restart = NULL;
    SDL_Texture* bouton_restart_texture = NULL;

    SDL_Surface* bouton_continuer = NULL;
    SDL_Texture* bouton_continuer_texture = NULL;

    SDL_Texture* bouton_quit_texture = NULL;
    SDL_Surface* bouton_quit = NULL;
    int height = 800;
    int width = 450;

    SDL_RenderFillRect(renderer, &fenetre_surface);

    SDL_Surface* fond = IMG_Load("./image/fond.jpg");
    SDL_Texture* fond_Texture = SDL_CreateTextureFromSurface(renderer, fond);

    SDL_FreeSurface(fond);

    SDL_RenderCopy(renderer, fond_Texture, NULL, &fenetre_surface); // Copie du sprite grâce au SDL_Renderer

    SDL_DestroyTexture(fond_Texture);
    SDL_RenderFillRect(renderer, &rectangle_restart);
    SDL_RenderFillRect(renderer, &rectangle_quit);
    SDL_RenderFillRect(renderer, &rectangle_continuer);


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





    bouton_continuer = SDL_LoadBMP("./image/continuer.bmp"); //chargement de l'image du bouton continuer

    if (bouton_continuer == NULL) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de charger l'image");
    }

    bouton_continuer_texture = SDL_CreateTextureFromSurface(renderer, bouton_continuer);
    SDL_FreeSurface(bouton_continuer);

    if (bouton_continuer_texture == NULL) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de creer le bonton quitter");
    }

    if (SDL_RenderCopy(renderer, bouton_continuer_texture, NULL, &rectangle_continuer) != 0)
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



/**
* \fn void menu_select(SDL_Window* window, SDL_Renderer* renderer, SDL_Rect rect_trajan,SDL_Rect rect_pierre, SDL_Rect rect_Barberousse)
* \param window Pointeur sur un objet de type SDL_Window
* \param renderer Pointeur sur un objet de type SDL_Renderer
* \param rect_trajan Rectangle objet de type SDL_Rect déjà initialisé pour le choix de la civilization de trajan
* \param rect_pierre Rectangle objet de type SDL_Rect déjà initialisé pour le choix de la civilization de pierre Ier
* \param rect_Barberousse Rectangle objet de type SDL_Rect déjà initialisé pour le choix de la civilization de barberousse
* \brief Le joueur choisis une civilization parmis les trois proposés
*/



void menu_select(SDL_Window* window, SDL_Renderer* renderer, SDL_Rect rect_trajan,SDL_Rect rect_pierre, SDL_Rect rect_Barberousse)
{ // faire la liste des civilisations disponibles + leur descrition et retourner la coordonnée du click souris pour sélectionner la civ

    SDL_Surface* trajan_image = NULL;
    SDL_Texture* trajan_texture = NULL;
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderFillRect(renderer, &rect_trajan);
    trajan_image = IMG_Load("./image/trajan.png");
    trajan_texture = SDL_CreateTextureFromSurface(renderer, trajan_image);
    //SDL_FreeSurface(trajan_image);
    SDL_RenderCopy(renderer, trajan_texture, NULL, &rect_trajan);
    SDL_RenderPresent(renderer);

   // rect_trajan =Creation_Text(renderer,rect_trajan,"image/police/Takenoko.TTF",Width/48,TTF_STYLE_BOLD,"Quitter",blue,(Width/4)+(Height*2/18),(Height*5/8)+(Height*2/18));

    SDL_Surface* pierre_image = NULL;
    SDL_Texture* pierre_texture = NULL;
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderFillRect(renderer, &rect_pierre);
    pierre_image = IMG_Load("./image/pierre.png");
    pierre_texture = SDL_CreateTextureFromSurface(renderer, pierre_image);
    //SDL_FreeSurface(trajan_image);
    SDL_RenderCopy(renderer, pierre_texture, NULL, &rect_pierre);
    SDL_RenderPresent(renderer);

    SDL_Surface* Barberousse_image = NULL;
    SDL_Texture* Barberousse_texture = NULL;
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderFillRect(renderer, &rect_Barberousse);
    Barberousse_image = IMG_Load("./image/allemagne.png");
    Barberousse_texture = SDL_CreateTextureFromSurface(renderer, Barberousse_image);
    //SDL_FreeSurface(trajan_image);
    SDL_RenderCopy(renderer, Barberousse_texture, NULL, &rect_Barberousse);
    SDL_RenderPresent(renderer);




}
