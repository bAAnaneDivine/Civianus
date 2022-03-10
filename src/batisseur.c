#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
#include "plateau.h"
#include "Allemagne.h"
#include "batisseur.h"
#include <SDL.h>
#include <SDL_image.h>
//#include un .h qui reunit toutes les fonctions






int batisseur(int plateau[N][N],batisseur_t * bat)
{
  int etat;
  int i,j;
    do{
    //SDL_MOUSE_CLIC sur la case a coté ou alors fleche pour voir quel coté aller

  }while((plateau[i][j] != plateau[bat->x+1][bat->y] || plateau[bat->x-1][bat->y] ||
    plateau[bat->x][bat->y-1] || plateau[bat->x][bat->y+1])
    && plateau[i][j]!=0);
      bat->x=i;
      bat->y=j;


  //if( /*clic ou pop up pour demander pour la creation de village*/){
      bat->etat=0;

      /* image render change pour le mettre l'image de la ville et remove l'image du batisseur*/
      if(  bat->etat==0){
      ville * new_ville;    //ref structure allemagne.h
      /*new_ville->nom_ville=tab[vill+1];*/
      new_ville->x=bat->x;
      new_ville->y=bat->y;
      new_ville->niveau_ville=1;
      new_ville->culture=0;
      new_ville->science=0;
      plateau[new_ville->x][new_ville->y]=10;
      //afficher_plateau(plateau);
    /*  bat->x=NULL;
      bat->y=NULL;
      bat->etat=NULL;
      free(bat); */
      }


}
