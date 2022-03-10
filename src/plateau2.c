#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include "admin_SDL.h"
#include "fenetre.h"
#include "menu.h"

#define N 50



int Fenetre_width=2160;
int Fenetre_height=3840;
int LONGUEUR_CASE=3840/20;
int LARGEUR_CASE=2160/20;







void clean_ressources(SDL_Window *w,SDL_Renderer *r,SDL_Texture *t)
{
    if(t != NULL)
        SDL_DestroyTexture(t);
    if(r != NULL)
        SDL_DestroyRenderer(r);
    if(w != NULL)
        SDL_DestroyWindow(w);
}

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



int crea_plat(int liste_biome[N][N],SDL_Rect cases[LONGUEUR_CASE][LARGEUR_CASE]){

  /* initialistaion variables */
  int effet;
  int indice=0;
  int i,j=0;


      /*definition taille case*/


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
          printf("image 0 %i creé \n",j);
        }

        for(i=1;i<=19;i++){
          for(j=0;j<=19;j++){
              cases[i][j].w=LONGUEUR_CASE;
              cases[i][j].h=LARGEUR_CASE;
              cases[i][j].x=cases[i-1][j].x+LONGUEUR_CASE;
              cases[i][j].y=cases[i-1][j].y;
              printf("image %i %i creé \n",i,j);

          }

        }
 /* effet a voir ce qu'on en fait,peut etre bonus selon la zone*/

/* bouton quitter */

SDL_Rect quit={Fenetre_height-LONGUEUR_CASE,0,LONGUEUR_CASE,LARGEUR_CASE};


 return(0);

}

int fonction_rand_biome (int biome[N][N],int i,int j){
int biom;
biom=rand()%10+1;
biome[i][j]=biom;
return (biome[i][j]);
}




/**
* \fn void afficher_plateau(SDL_Window *fenetre,SDL_Renderer * rendu,SDL_Rect cases[LONGUEUR_CASE][LARGEUR_CASE],int biome[NBR_BIOME])
* \param window Pointeur sur un objet de type SDL_Window
* \param renderer Pointeur sur un objet de type SDL_Renderer
* \param biomes[NB_CASE] Tableau de taille NB_CASE d'objet de type integer
* \param cases[NB_CASE] Tableau de taille NB_CASE d'objet de type SDL_Rect déjà initialisé
* \brief affichage du plateau
*/
/*affichage du plateau */
void afficher_plateau(SDL_Window *window,SDL_Renderer * renderer,SDL_Rect cases[LONGUEUR_CASE][LARGEUR_CASE],int biome[N][N]){
  SDL_Surface *image=NULL;
  SDL_Texture *texture=NULL;
  SDL_Texture *imagefond=NULL;


  int i,j;

  clean_ressources(NULL,renderer,NULL);


       /*Création du rendu de plateau*/
  renderer=SDL_CreateRenderer(window,-1,0);
  if(renderer == NULL)
    SDL_ExitWithError("Le renderer n'a pas pu être créé");



   /*Création de l'image de fond*/
  SDL_Rect fond={0,0,Fenetre_height,Fenetre_width};
  image= IMG_Load("./image/case_bleue.png");
  SDL_AfficherUneImage(renderer,image,imagefond,fond);




  /*Création de l'image du bandeau informations*/
 SDL_Rect bandeau_info={0,0,Fenetre_height,LARGEUR_CASE};
 image= IMG_Load("./image/fond_plateau1.png");
 SDL_AfficherUneImage(renderer,image,texture,bandeau_info);




/*     bouton quitter sur le plateau */

SDL_Rect quit={0,0,LONGUEUR_CASE,LARGEUR_CASE};
image= IMG_Load("./image/restart.bmp");
SDL_AfficherUneImage(renderer,image,texture,quit);

/*fonction quitter si on clique*/





  for(i=0;i<20;i++){
    for(j=0;j<20;j++){
      fonction_rand_biome (biome,i,j);
      switch(biome[i][j]){
        case 1:
          image= IMG_Load("./image/montagne.png");
          SDL_AfficherUneImage(renderer,image,texture,cases[i][j]);
        break;
        case 2:
          image= IMG_Load("./image/eau.png");
          SDL_AfficherUneImage(renderer,image,texture,cases[i][j]);
        break;
        case 3:
          image= IMG_Load("./image/herbe.png");
          SDL_AfficherUneImage(renderer,image,texture,cases[i][j]);
        break;
        case 4:
          image= IMG_Load("./image/herbe.png");
         SDL_AfficherUneImage(renderer,image,texture,cases[i][j]);
        break;
        case 5:
          image= IMG_Load("./image/herbe.png");
          SDL_AfficherUneImage(renderer,image,texture,cases[i][j]);
        break;
        case 6:
          image= IMG_Load("./image/herbe.png");
          SDL_AfficherUneImage(renderer,image,texture,cases[i][j]);
        break;
        case 7:
          image= IMG_Load("./image/herbe.png");
          SDL_AfficherUneImage(renderer,image,texture,cases[i][j]);
        break;
        case 8:
          image= IMG_Load("./image/herbe.png");
          SDL_AfficherUneImage(renderer,image,texture,cases[i][j]);
        break;
        case 9:
          image= IMG_Load("./image/herbe.png");
         SDL_AfficherUneImage(renderer,image,texture,cases[i][j]);
        break;
        case 10:
          image= IMG_Load("./image/herbe.png");
          SDL_AfficherUneImage(renderer,image,texture,cases[i][j]);
        break;

      }
    }
  }


  clean_ressources(NULL,NULL,texture);
  clean_ressources(NULL,NULL,imagefond);
}
