#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include "headers/admin_SDL.h"
#include "headers/plateau.h"
#include "headers/menu.h"
#include "headers/structure_jeu.h"

/*
 *fonction pour la civilization globale
 *
 */

 civilization_t * crea_civ(int civi){
     civilization_t * civ=malloc(sizeof(civilization_t));
     civ->civilization=civi;
     civ->sciences_globale=2;
     civ->nb_ferme=0;
     civ->nb_biblio=0;
     if(civi==1){
      civ->bonus_sciences=3;
      civ->bonus_culture=1;
    }
    else if(civi==2){
    civ->bonus_sciences=2;
    civ->bonus_culture=2;
  }
    else if(civi==3){
      civ->bonus_sciences=1;
      civ->bonus_culture=3;

    }

     return(civ);
 }

civilization_t *fin_tour_civ(civilization_t *civ){

civ->sciences_globale=(civ->sciences_globale)+(2*(civ->nb_biblio)*(civ->bonus_sciences));
civ->culture_globale=(civ->culture_globale)+(3*(civ->nb_ferme)*(civ->bonus_culture));
return(civ);
}



/*
  *
  * fonction pour le colon
  *
  */


int est_libre(int liste_cases[i][j]){
    if(liste_cases[i][j]==1 || liste_cases[i][j]==2)
        return(0);
    else
      return(1);
}




void supp_image_colon(SDL_Rect plateau[i][j],SDL_Renderer *renderer,SDL_Texture * texture){
      SDL_FreeSurface;
      SDL_Surface *herbe;
      herbe=IMG_Load("./image/herbe.png");
      SDL_AfficherUneImage(renderer,herbe,texture,plateau[i][j]);
}


void affiche_colon(SDL_Rect plateau[LONGUEUR_CASE][LARGEUR_CASE],SDL_Renderer *renderer,colon_t * colon){
      SDL_Texture * texture=NULL;
      SDL_Surface *image_colon=NULL;
      int i=colon->x;
      int j=(colon->y)-1;
      image_colon=IMG_Load("./image/colon.png");
      SDL_AfficherUneImage(renderer,image_colon,texture,plateau[i][j]);
}

colon_t * crea_colon(int i,int j){
    colon_t * colon=malloc(sizeof(colon_t));

    colon->x=i;
    colon->y=j;
    colon->etat_cons=1;  //etat de non construction de ville;
    //affiche_colon(plateau);
    printf("position colon :");
    printf(" x=%d y=%d\n",colon->x,colon->y);
    return(colon);
}


void mvt_colon(SDL_Rect plateau[i][j],colon_t * colon,int x,int y){ //x et y viennent des fonctions clics

  SDL_Renderer *renderer;
  SDL_Texture * texture;

  do{
  /* clic ou appel de la fonction mvt_colon*/

  }while((((colon->x)-x)>1)|| (((colon->y)-y)>1) );
      /* refaire */
      colon->x=x;
      colon->y=y;
    /*  supp_image_colon(plateau,renderer,texture);
      affiche_colon(plateau);*/
}



/*
*
*fonction ville
*
*/

void affiche_ville(SDL_Rect cases[LONGUEUR_CASE][LARGEUR_CASE],ville_t *ville,SDL_Renderer *renderer){
      SDL_Texture * texture=NULL;
      SDL_Surface *image_ville=NULL;

      int i=ville->x;
      int j=(ville->y)-1;

      image_ville=IMG_Load("./image/ville3.png");
      SDL_AfficherUneImage(renderer,image_ville,texture,cases[i][j]);
  SDL_RenderPresent(renderer);
  printf("ville_afficher\n");
}


ville_t * crea_ville(int i,int j){
    ville_t * ville=malloc(sizeof(ville_t));

     ville->x=i;
     ville->y=j;
     ville->culture=1;
     ville->sciences=5;
     ville->niveau_ville=5;
     ville->nom_ville="FRONTIER";
  printf("position ville :");
    printf(" x=%d y=%d\n",ville->x,ville->y);
    return(ville);
}





void dest_ville(SDL_Rect plateau[i][j],ville_t * ville,int x,int y){ //x et y viennent des fonctions clics

  SDL_Renderer *renderer;
  SDL_Texture * texture;

    clean_ressources(NULL,NULL,texture);

}



/*
*
*fonction batisseur
*
*/


void supp_image_batisseur(SDL_Rect plateau[i][j],SDL_Renderer *renderer,SDL_Texture * texture){
      //SDL_FreeSurface;
      SDL_Surface *herbe;
      herbe=IMG_Load("./image/herbe.png");
      SDL_AfficherUneImage(renderer,herbe,texture,plateau[i][j]);
}


void affiche_batisseur(SDL_Rect plateau[LONGUEUR_CASE][LARGEUR_CASE],SDL_Renderer *renderer,batisseur_t* batisseur){
      SDL_Texture * texture;
      SDL_Surface *image_batisseur;
      int i=batisseur->x;
      int j=(batisseur->y)-1;
      image_batisseur=IMG_Load("./image/batisseur.png");
      SDL_AfficherUneImage(renderer,image_batisseur,texture,plateau[i][j]);

}

batisseur_t * crea_batisseur(int i,int j){
    batisseur_t * batisseur;
    batisseur=malloc(sizeof(batisseur_t));
    batisseur->x=i;
    batisseur->y=j;
    batisseur->nb_coup=3;

    printf("position batisseur :");

    return(batisseur);
}


void mvt_batisseur(SDL_Rect plateau[i][j],batisseur_t * batisseur,int x,int y){ //x et y viennent des fonctions clics

  SDL_Renderer *renderer;
  SDL_Texture * texture;

  do{
  /* clic ou appel de la fonction mvt_batisseur*/

  }while((((batisseur->x)-x)>1)|| (((batisseur->y)-y)>1) );
      /* refaire */
      batisseur->x=x;
      batisseur->y=y;
    //  supp_image_batisseur(plateau,renderer,texture);
    //  affiche_batisseur(plateau);
}


/*
*
*fonction guerrier
*
*/

void supp_image_guerrier(SDL_Rect plateau[i][j],SDL_Renderer *renderer,SDL_Texture * texture){
      SDL_FreeSurface;
      SDL_Surface *herbe;
      herbe=IMG_Load("./image/herbe.png");
      SDL_AfficherUneImage(renderer,herbe,texture,plateau[i][j]);
}


void affiche_guerrier(SDL_Rect plateau[LONGUEUR_CASE][LARGEUR_CASE],SDL_Renderer *renderer,guerrier_t* guerrier){
      SDL_Texture * texture;
      SDL_Surface *image_guerrier;
      int i=guerrier->x;
      int j=(guerrier->y)-1;
      image_guerrier=IMG_Load("./image/guerrier.png");
      SDL_AfficherUneImage(renderer,image_guerrier,texture,plateau[i][j]);

}

guerrier_t * crea_guerrier(int i,int j){
    guerrier_t * guerrier=malloc(sizeof(guerrier_t));

    guerrier->x=i;
    guerrier->y=j;
    guerrier->pdv=3;
    guerrier->att=1;
    guerrier->def=3;
    //affiche_guerrier(plateau);
    printf("position guerrier :");
    printf(" x=%d y=%d\n",guerrier->x,guerrier->y);
    return(guerrier);
}


void mvt_guerrier(SDL_Rect plateau[i][j],guerrier_t * guerrier,int x,int y){ //x et y viennent des fonctions clics

  SDL_Renderer *renderer;
  SDL_Texture * texture;

  do{
  /* clic ou appel de la fonction mvt_guerrier*/

  }while((((guerrier->x)-x)>1)|| (((guerrier->y)-y)>1) );
      /* refaire */
      guerrier->x=x;
      guerrier->y=y;
      supp_image_guerrier(plateau,renderer,texture);
    //  affiche_guerrier(plateau);
}

/*
  *
  * fonction pour le arm_spec
  *
*/



void supp_image_arm_spec(SDL_Rect plateau[i][j],SDL_Renderer *renderer,SDL_Texture * texture){
      SDL_FreeSurface;
      SDL_Surface *herbe;
      herbe=IMG_Load("./image/herbe.png");
      SDL_AfficherUneImage(renderer,herbe,texture,plateau[i][j]);
}


void affiche_arm_spec(SDL_Rect plateau[LONGUEUR_CASE][LARGEUR_CASE],SDL_Renderer *renderer,arm_spec_t* arm_spec){
      SDL_Texture * texture;
      SDL_Surface *image_arm_spec;
      int i=arm_spec->x;
      int j=(arm_spec->y)-1;
      image_arm_spec=IMG_Load("./image/nombre_tour.png");
      SDL_AfficherUneImage(renderer,image_arm_spec,texture,plateau[i][j]);

}

arm_spec_t * crea_arm_spec(int i,int j){
    arm_spec_t * arm_spec=malloc(sizeof(arm_spec_t));

    arm_spec->x=i;
    arm_spec->y=j;
    arm_spec->pdv=3;
    arm_spec->att=1;
    arm_spec->def=3;
    //affiche_arm_spec(plateau);
    printf("position arm_spec :");
    printf(" x=%d y=%d\n",arm_spec->x,arm_spec->y);
    return(arm_spec);
}


void mvt_arm_spec(SDL_Rect plateau[i][j],arm_spec_t * arm_spec,int x,int y){ //x et y viennent des fonctions clics

  SDL_Renderer *renderer;
  SDL_Texture * texture;

  do{
  /* clic ou appel de la fonction mvt_arm_spec*/

  }while((((arm_spec->x)-x)>1)|| (((arm_spec->y)-y)>1) );
      /* refaire */
      arm_spec->x=x;
      arm_spec->y=y;
      supp_image_arm_spec(plateau,renderer,texture);
  //    affiche_arm_spec(plateau);
}


/*
  *
  * fonction pour le arm_long
  *
*/



void supp_image_arm_long(SDL_Rect plateau[i][j],SDL_Renderer *renderer,SDL_Texture * texture){
      SDL_FreeSurface;
      SDL_Surface *herbe;
      herbe=IMG_Load("./image/herbe.png");
      SDL_AfficherUneImage(renderer,herbe,texture,plateau[i][j]);
}


void affiche_arm_long(SDL_Rect plateau[LONGUEUR_CASE][LARGEUR_CASE],SDL_Renderer *renderer,arm_long_t* arm_long){
      SDL_Texture * texture;
      SDL_Surface *image_arm_long;
      int i=arm_long->x;
      int j=(arm_long->y)-1;
      image_arm_long=IMG_Load("./image/archer.png");
      SDL_AfficherUneImage(renderer,image_arm_long,texture,plateau[i][j]);

}

arm_long_t * crea_arm_long(int i,int j){
    arm_long_t * arm_long=malloc(sizeof(arm_long_t));

    arm_long->x=i;
    arm_long->y=j;
    arm_long->pdv=3;
    arm_long->att=1;
    arm_long->def=3;
    //affiche_arm_long(plateau);
    printf("position arm_long :");
    printf(" x=%d y=%d\n",arm_long->x,arm_long->y);
    return(arm_long);
}


void mvt_arm_long(SDL_Rect plateau[i][j],arm_long_t * arm_long,int x,int y){ //x et y viennent des fonctions clics

  SDL_Renderer *renderer;
  SDL_Texture * texture;

  do{
  /* clic ou appel de la fonction mvt_arm_long*/

  }while((((arm_long->x)-x)>1)|| (((arm_long->y)-y)>1) );
      /* refaire */
      arm_long->x=x;
      arm_long->y=y;
      supp_image_arm_long(plateau,renderer,texture);
    //  affiche_arm_long(plateau);
}



/*

création fonction ville

*/
int click_case_x(int valx){
  int numx=valx/LONGUEUR_CASE;
  printf("case : i=%d \n", numx);
  return(numx);
}

int click_case_y(int valy){
int numy=valy/LARGEUR_CASE;
  printf("case : j=%d \n", numy);
  return(numy);
}
