#ifndef _BANDEAU_ACTION_H_
#define _BANDEAU_ACTION_H_

int fonction_bandeau_ville(SDL_Rect cases[LONGUEUR_CASE][LARGEUR_CASE], SDL_Renderer *renderer,ville_t *ville);

int fonction_bandeau_batisseur(SDL_Rect cases[LONGUEUR_CASE][LARGEUR_CASE], SDL_Renderer *renderer,batisseur_t *batisseur, int liste_cases[N][N]);

int fonction_bandeau_colon(SDL_Rect cases[LONGUEUR_CASE][LARGEUR_CASE], SDL_Renderer *renderer,colon_t *colon,int liste_cases[N][N]);

int fonction_bandeau_guerrier(SDL_Rect cases[LONGUEUR_CASE][LARGEUR_CASE], SDL_Renderer *renderer,guerrier_t *guerrier,int liste_cases[N][N]);

int fonction_bandeau_archer(SDL_Rect cases[LONGUEUR_CASE][LARGEUR_CASE], SDL_Renderer *renderer,arm_long_t*arm_long,int liste_cases[N][N]);

#endif
