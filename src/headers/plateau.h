#ifndef _PLATEAU_H_
#define _MENU_PLATEAU_H__H_

#define N 35

#define Fenetre_width 700
#define Fenetre_height 1000
#define LONGUEUR_CASE 50
#define LARGEUR_CASE 35

void clean_ressources(SDL_Window *w,SDL_Renderer *r,SDL_Texture *t);
void SDL_AfficherUneImage(SDL_Renderer *renderer,SDL_Surface *image,SDL_Texture *texture,SDL_Rect rectangle);


int crea_plat(SDL_Rect cases[LONGUEUR_CASE][LARGEUR_CASE]);
int affectation_cases(int liste_biome[N][N],SDL_Rect cases[LONGUEUR_CASE][LARGEUR_CASE]);
int fonction_rand_biome (int biome[N][N],int i,int j);
void afficher_plateau(SDL_Window *window,SDL_Renderer * renderer,SDL_Rect cases[LONGUEUR_CASE][LARGEUR_CASE],int biome[N][N]);

#endif
