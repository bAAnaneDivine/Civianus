#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include "../lib/petite_fonction.h"
/**
* \file petite_fonction.c
* \author Tan Tony
* \version 1.3
* \brief La création de petites fonctions utiles à l'affichage SDL.
*/

/**
* \fn void SDL_ExitWithError(const char *message)
* \param message Constante d'un objet de type char
* \brief Cette fonction va prendre en paramètre un message pour ensuite l'afficher sur le terminal avec l'erreur puis va quitter la fenêtre SDL ainsi que le programme.
*/
void SDL_ExitWithError(const char *message)
{
    SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}

/**
* \fn void clean_ressources(SDL_Window *w,SDL_Renderer *r,SDL_Texture *t)
* \param w Pointeur d'un objet de type SDL_Window
* \param r Pointeur d'un objet de type SDL_Renderer
* \param t Pointeur d'un objet de type SDL_Texture
* \brief Cette fonction va appeler les fonction SDL_Destroy... pour détruire ces différentes variables.
* \details Il détruit soit la fenêtre soit le rendu soit la texture soit deux des trois soit tous soit aucun.
*/
void clean_ressources(SDL_Window *w,SDL_Renderer *r,SDL_Texture *t)
{
    if(t != NULL)
        SDL_DestroyTexture(t);
    if(r != NULL)
        SDL_DestroyRenderer(r);
    if(w != NULL)
        SDL_DestroyWindow(w);
}
/**
* \fn void SDL_AfficherUneImage(SDL_Renderer *rendu,SDL_Surface *image,SDL_Texture *texture,SDL_Rect rectangle)
* \param rendu Pointeur d'un objet de type SDL_Renderer
* \param image Pointeur d'un objet de type SDL_Surface
* \param texture Pointeur d'un objet de type SDL_Texture
* \param rectangle Pointeur d'un objet de type SDL_Rect
* \brief Cette fonction va afficher notre image sur la fenêtre.
*/
void SDL_AfficherUneImage(SDL_Renderer *rendu,SDL_Surface *image,SDL_Texture *texture,SDL_Rect rectangle){
    if(image ==NULL){
        clean_ressources(NULL,rendu,texture);
        SDL_ExitWithError("Impossible de charger l'image");
    }
    texture= SDL_CreateTextureFromSurface(rendu,image);

    SDL_FreeSurface(image);
     if(texture ==NULL){
        clean_ressources(NULL,rendu,texture);
        SDL_ExitWithError("Impossible de creer la texture");
    }
    if(SDL_RenderCopy(rendu,texture,NULL,&rectangle)!=0){
        clean_ressources(NULL,rendu,texture);
        SDL_ExitWithError("Impossible d'afficher la texture");
    }
    SDL_RenderPresent(rendu);
}