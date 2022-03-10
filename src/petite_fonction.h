#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
/**
* \file petite_fonction.h
* \author Tan Tony
* \version 2.6
* \brief Les fonctions prototypes de menu.c,petite_fonction.c et creer_partie.c
*/
/** *\brief La taille en longueur de notre fenêtre*/
int Fenetre_width;
 /** *\brief La taille en largeur de notre fenêtre*/
int Fenetre_height;
void clean_ressources(SDL_Window *w,SDL_Renderer *r,SDL_Texture *t);
void SDL_AfficherUneImage(SDL_Renderer *rendu,SDL_Surface *image,SDL_Texture *texture,SDL_Rect rectangle);
void SDL_ExitWithError(const char *message);
void creation_partie(SDL_Window *fenetre,int * joueur, int * tour,int * quitter);
void menu(SDL_Window *fenetre,int * joueur, int * tour,int * quitter);
