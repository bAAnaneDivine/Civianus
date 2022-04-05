#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include "headers/admin_SDL.h"
#include "headers/menu.h"


#define N 54



#define Fenetre_width 700
#define Fenetre_height 1000
#define LONGUEUR_CASE 1000 / 20
#define LARGEUR_CASE 700 / 20

/**
 *\file plateau.c
 * \brief Création du plateau de jeu et affichage de celui ci
 * \author Pierre Cyprien
 * \version 1.0
 * \date 01/02/2022
*/



/**
* \fn void clean_ressources(SDL_Window *w,SDL_Renderer *r,SDL_Texture *t)
* \param w Récupère la fenêtre déjà initialisé
* \param r Récupère la rendu déjà initialisé
* \param t Récupère la texture déjà initialisé
* \brief Destruction des textures et rendus ainsi que de la fenêtre
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
* \fn SDL_AfficherUneImage(SDL_Renderer *renderer,SDL_Surface *image,SDL_Texture *texture,SDL_Rect rectangle)
* \param renderer Rendu d'affichage déjà initialisé
* \param image Récupère l'image déjà initialisé
* \param texture Récupère la texture déjà initialisé
* \param rectangle objet de type SDL_Rect déjà initialisé
* \brief Permet l'affichage d'une image et opère les cas d'erreurs éventuels
*/



void SDL_AfficherUneImage(SDL_Renderer *renderer,SDL_Surface *image,SDL_Texture *texture,SDL_Rect rectangle){
    if(image ==NULL){
        clean_ressources(NULL,renderer,texture);
        SDL_ExitWithError("Impossible de charger l'image");
    }
    texture= SDL_CreateTextureFromSurface(renderer,image);

    SDL_FreeSurface(image);
     if(texture ==NULL){
        clean_ressources(NULL,renderer,texture);
        SDL_ExitWithError("Impossible de creer la texture");
    }
    if(SDL_RenderCopy(renderer,texture,NULL,&rectangle)!=0){
        clean_ressources(NULL,renderer,texture);
        SDL_ExitWithError("Impossible d'afficher la texture");
    }
    SDL_RenderPresent(renderer);
}

/**
* \fn int fonction_rand_biome (int biome[N][N],int i,int j)
* \param biome[NB_CASE] Tableau de taille NB_CASE d'objet de type SDL_Rect déjà initialisé
* \brief Récupère une case de coordonnée i / j et lui affecte une valeur aléatoire qui définira sa texture dans la création de plateau
*/


int fonction_rand_biome (int biome[N][N],int i,int j){
int biom;
biom=rand()%20+1;
biome[i][j]=biom;
return (biome[i][j]);
}



/**
* \fn int crea_plat(SDL_Rect cases[LONGUEUR_CASE][LARGEUR_CASE])
* \param cases[NB_CASE] Tableau de taille NB_CASE d'objet de type SDL_Rect déjà initialisé
* \brief Récupère les cases définies auparavant et créé le plateau de jeu, d'abord par le bandeau d'information, puis la colonne de gauche et enfin le reste des cases à partir de la colonne
*/

int crea_plat(SDL_Rect cases[LONGUEUR_CASE][LARGEUR_CASE]){

  /* initialistaion variables */

  int i,j=0;


     /*definition taille case*/
    cases[0][0].w=LONGUEUR_CASE;
    cases[0][0].h=LARGEUR_CASE;
    cases[0][0].x=0;
    cases[0][0].y=LARGEUR_CASE;

     /*première colonne */
    for(j=1;j<=19;j++){
      cases[0][j].w=LONGUEUR_CASE;
      cases[0][j].h=LARGEUR_CASE;
      cases[0][j].x=cases[0][j-1].x;
      cases[0][j].y=cases[0][j-1].y+LARGEUR_CASE;
    }
    /*reste du plateau*/
    for(i=1;i<=20;i++){
      for(j=0;j<=19;j++){
          cases[i][j].w=LONGUEUR_CASE;
          cases[i][j].h=LARGEUR_CASE;
          cases[i][j].x=cases[i-1][j].x+LONGUEUR_CASE;
          cases[i][j].y=cases[i-1][j].y;
      }
    }


return(0);

}

/**
* \fn int affectation_cases(int biome[N][N],SDL_Rect cases[LONGUEUR_CASE][LARGEUR_CASE])
* \param biome Fonction d'affectation d'un biome aléatoire
* \param cases[NB_CASE] Tableau de taille NB_CASE d'objet de type SDL_Rect déjà initialisé
* \brief Inscrit dans un fichier de sauvegarde les cases du plateau pour permettre de continuer la partie
*/

int affectation_cases(int biome[N][N],SDL_Rect cases[LONGUEUR_CASE][LARGEUR_CASE]){

  /* initialistaion variables */
  int effet;
  int indice=0;
  int i,j=0;


      /*ouverture fichier map*/
    FILE * map;
    map = fopen( "./src/map.txt", "w" );


    for(i=1;i<=19;i++){
      for(j=0;j<=19;j++){
          cases[i][j].w=LONGUEUR_CASE;
          cases[i][j].h=LARGEUR_CASE;
          cases[i][j].x=cases[i-1][j].x+LONGUEUR_CASE;
          cases[i][j].y=cases[i-1][j].y;
          fonction_rand_biome (biome,i,j);
          fprintf( map, "%i ",biome[i][j]);
      }
    }
 /* effet a voir ce qu'on en fait,peut etre bonus selon la zone*/


fclose(map);
return(0);

}

/**
* \fn void afficher_plateau(SDL_Window *window,SDL_Renderer * renderer,SDL_Rect cases[LONGUEUR_CASE][LARGEUR_CASE],int biome[N][N])
* \param window Pointeur sur un objet de type SDL_Window
* \param renderer Pointeur sur un objet de type SDL_Renderer
* \param cases[NB_CASE] Tableau de taille NB_CASE d'objet de type SDL_Rect déjà initialisé
* \param biome[NB_CASE] Tableau de taille NB_CASE d'objet de type integer déjà initialisé
* \brief affichage du plateau
*/


void afficher_plateau(SDL_Window *window,SDL_Renderer * renderer,SDL_Rect cases[LONGUEUR_CASE][LARGEUR_CASE],int biome[N][N]){
  SDL_Surface *image=NULL;
  SDL_Texture *texture=NULL;
  SDL_Texture *imagefond=NULL;
  FILE * map;
  map = fopen( "./src/map.txt", "r" );

  int i,j;

  clean_ressources(NULL,renderer,NULL);


  /*Création du rendu de plateau*/
renderer=SDL_CreateRenderer(window,-1,0);
if(renderer == NULL)
SDL_ExitWithError("Le renderer n'a pas pu être créé");



  /*Création de l'image de fond*/
SDL_Rect fond={0,0,Fenetre_height,Fenetre_width};
image= IMG_Load("./image/check.png");
SDL_AfficherUneImage(renderer,image,imagefond,fond);




  /*Création de l'image du bandeau informations*/
SDL_Rect bandeau_info={0,0,Fenetre_height,LARGEUR_CASE};
image= IMG_Load("./image/fond_plateau1.png");
SDL_AfficherUneImage(renderer,image,texture,bandeau_info);




  /* bouton quitter sur le plateau */
SDL_Rect quit={0,0,LONGUEUR_CASE,LARGEUR_CASE};
image= IMG_Load("./image/quit.png");
SDL_AfficherUneImage(renderer,image,texture,quit);



int adresse=0;
  for(i=0;i<20;i++){
    for(j=0;j<20;j++){
      fscanf(map, "%i",&adresse);
      switch(adresse){
        case 1:
          image= IMG_Load("./image/montagne.png");
          SDL_AfficherUneImage(renderer,image,texture,cases[i][j]);
        break;
        case 2:
        image= IMG_Load("./image/eau.png");
          SDL_AfficherUneImage(renderer,image,texture,cases[i][j]);
        break;
        default:
          image= IMG_Load("./image/herbe.png");
          SDL_AfficherUneImage(renderer,image,texture,cases[i][j]);
        break;
      }
      

      adresse++;
    }
  }

  image= IMG_Load("./image/ville1.png"); /* base alliée */
  SDL_AfficherUneImage(renderer,image,texture,cases[3][7]);
  image= IMG_Load("./image/ville1.png"); /* base alliée */
  SDL_AfficherUneImage(renderer,image,texture,cases[17][8]);


  clean_ressources(NULL,NULL,texture);
  clean_ressources(NULL,NULL,imagefond);
  fclose(map);
}
