#include <stdio.h>
#include <stdlib.h>
#include "../lib/liste.h"
#include "../lib/Allemagne.h"
/*  lien des autres fichiers*/



t_ville elem[V];

void test_ville(){
  printf("erreur1");
  t_ville elem[V];
  t_ville * p[V];
  p[0]=elem[0].succ;
  printf("erreur2");
  /*p->Ville_P->niveau_ville=malloc(sizeof(int));
  p->Ville_P->niveau_nourriture=malloc(sizeof(int));
  */

  int i=0;
  char *nom_ville=tab[i]; //ref Allemagne.h


  while(p[i]->Ville_P != elem[0].Ville_P){


      printf("erreur3");
      printf("nom de la ville :%s \n",nom_ville);
      printf("niveau de la ville  :%d \n",p[i]->Ville_P->niveau_ville);
      printf("nombre de nourriture de la villes:%d \n",p[i]->Ville_P->culture);
      printf("nombre de nourriture de la villes:%d \n",p[i]->Ville_P->science);
      p[i]=p[i]->succ;
      i++;
  }
  printf("erreur4");
}
