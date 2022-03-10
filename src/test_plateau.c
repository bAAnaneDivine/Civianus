#include <stdio.h>
#include <stdlib.h>
#include "plateau.h"
#include <SDL.h>
#include <SDL_image.h>


SDL_Rect plateau[N][N];
int liste_biome[N];
int NBR_BIOME;



int main(int argc,char ** arg){
	SDL_Window * fenetre=NULL;
  SDL_Renderer *rendu= NULL;
  int liste_cases[NBR_BIOME];
  SDL_Rect cases[N][N];
/*  if(SDL_Init(SDL_INIT_VIDEO) != 0)      Lancement SDL
    SDL_ExitWithError("Initialisation SDL");*/
  /*     Création de la fenêtre     */
  fenetre=SDL_CreateWindow("INFO PARTY",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,Fenetre_width,Fenetre_height,0);
  SDL_GetWindowSize(fenetre,&Fenetre_width,&Fenetre_height);
	crea_plat(liste_cases,cases);
    /*       Création du rendu de plateau     */
  rendu=SDL_CreateRenderer(fenetre,-1,0);

  afficher_plateau(fenetre,rendu,cases,liste_cases);
  SDL_RenderPresent(rendu);
	int i;

  printf("\n Test creation plateau \n\n");
  for(i=0;i<NBR_BIOME && !hors_liste_plat(); i++){
      printf("effet case %i: %i\n\n",ec->nb_case,ec->effet);
      suivant_plat();
  }
  SDL_DestroyRenderer(rendu);
  SDL_DestroyWindow(fenetre);
  SDL_Quit();
  return(0);
}
