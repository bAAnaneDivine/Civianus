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

    SDL_RenderFillRect(renderer, &fenetre_surface);

    SDL_Surface* fond = IMG_Load("./image/fond.jpg");
    SDL_Texture* fond_Texture = SDL_CreateTextureFromSurface(renderer, fond);

    SDL_FreeSurface(fond);

    SDL_RenderCopy(renderer, fond_Texture, NULL, &fenetre_surface); /* Copie du sprite grâce au SDL_Renderer*/

    SDL_DestroyTexture(fond_Texture);
    SDL_RenderFillRect(renderer, &rectangle_restart);
    SDL_RenderFillRect(renderer, &rectangle_quit);
    SDL_RenderFillRect(renderer, &rectangle_continuer);


    bouton_restart = IMG_Load("./image/restart.png"); /*chargement de l'image du bouton restart*/

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





    bouton_continuer = IMG_Load("./image/continuer.png"); /*chargement de l'image du bouton continuer*/

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








    bouton_quit = IMG_Load("./image/quit.png");       /*chargement de l'image du bouton quitter*/

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



int menu_select(SDL_Window* window, SDL_Renderer* renderer, SDL_Rect rect_trajan,SDL_Rect rect_pierre, SDL_Rect rect_Barberousse)
{ /* faire la liste des civilisations disponibles + leur descrition et retourner la coordonnée du click souris pour sélectionner la civ*/
SDL_Event event;

int x = 0, y = 0;
SDL_Rect rectangle_continuer_trajan;
rectangle_continuer_trajan.x = 137.5;
rectangle_continuer_trajan.y = 50;
rectangle_continuer_trajan.w = 150;
rectangle_continuer_trajan.h = 150;

SDL_Rect rectangle_continuer_pierre;
rectangle_continuer_pierre.x = 425;
rectangle_continuer_pierre.y = 50;
rectangle_continuer_pierre.w = 150;
rectangle_continuer_pierre.h = 150;

SDL_Rect rectangle_continuer_barberousse;
rectangle_continuer_barberousse.x = 712.5;
rectangle_continuer_barberousse.y = 50;
rectangle_continuer_barberousse.w = 150;
rectangle_continuer_barberousse.h = 150;

SDL_Surface* trajan_image = NULL;
SDL_Texture* trajan_texture = NULL;
SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
SDL_RenderFillRect(renderer, &rect_trajan);
trajan_image = IMG_Load("./image/trajan.png");
trajan_texture = SDL_CreateTextureFromSurface(renderer, trajan_image);
SDL_FreeSurface(trajan_image);
SDL_RenderCopy(renderer, trajan_texture, NULL, &rect_trajan);
SDL_RenderPresent(renderer);


SDL_Surface* pierre_image = NULL;
SDL_Texture* pierre_texture = NULL;
SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
SDL_RenderFillRect(renderer, &rect_pierre);
pierre_image = IMG_Load("./image/pierre.png");
pierre_texture = SDL_CreateTextureFromSurface(renderer, pierre_image);
SDL_FreeSurface(pierre_image);
SDL_RenderCopy(renderer, pierre_texture, NULL, &rect_pierre);
SDL_RenderPresent(renderer);

SDL_Surface* barberousse_image = NULL;
SDL_Texture* barberousse_texture = NULL;
SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
SDL_RenderFillRect(renderer, &rect_Barberousse);
barberousse_image = IMG_Load("./image/allemagne.png");
barberousse_texture = SDL_CreateTextureFromSurface(renderer, barberousse_image);
SDL_FreeSurface(barberousse_image);
SDL_RenderCopy(renderer, barberousse_texture, NULL, &rect_Barberousse);
SDL_RenderPresent(renderer);

SDL_bool program_launched = SDL_TRUE;
int civilisation=0, trouve=0;
while ((SDL_PollEvent(&event))||(trouve!=1)){
        switch (event.type){
            case SDL_QUIT:
                program_launched = SDL_FALSE;
                break;

            case SDL_MOUSEBUTTONDOWN:   /* Relâchement d'un clique*/
                x = event.button.x;  /*récupération de la position de la souris*/
                y = event.button.y;
                if (x > rectangle_continuer_trajan.x && x<(rectangle_continuer_trajan.x + rectangle_continuer_trajan.w) && y>rectangle_continuer_trajan.y && y < (rectangle_continuer_trajan.y + rectangle_continuer_trajan.h)){
                    trouve=1;
                    return (civilisation=1);
                }
                else if (x > rectangle_continuer_pierre.x && x<(rectangle_continuer_pierre.x + rectangle_continuer_pierre.w) && y>rectangle_continuer_pierre.y && y < (rectangle_continuer_pierre.y + rectangle_continuer_pierre.h)){
                    trouve=1;
                    return (civilisation=2);
                }
                else if (x > rectangle_continuer_barberousse.x && x<(rectangle_continuer_barberousse.x + rectangle_continuer_barberousse.w) && y>rectangle_continuer_barberousse.y && y < (rectangle_continuer_barberousse.y + rectangle_continuer_barberousse.h)){
                    trouve=1;
                    return (civilisation=3);

                }
                break;

            default:
                break;
        }
    }
}
