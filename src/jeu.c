
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include "headers/admin_SDL.h"
#include "headers/plateau.h"
#include "headers/menu.h"
#include "headers/structure_jeu.h"
#include "headers/jeu.h"
#include "headers/bandeau_action.h"
#include "headers/mouvement_personnage.h"




int  jeu(int civilization,SDL_Window* window, SDL_Renderer* renderer,int liste_cases[N][N]){

    civilization_t *civ;
  SDL_initialisation();
     SDL_Rect cases[LONGUEUR_CASE][LARGEUR_CASE];
     SDL_Texture * texture=NULL;
     int height = 1000;
     int width = 700;


     SDL_Rect passer_tour={LONGUEUR_CASE,0,LONGUEUR_CASE,LARGEUR_CASE};
      SDL_Rect rectangle_quit={0,0,LONGUEUR_CASE,LARGEUR_CASE};
      crea_plat(cases);
        SDL_bool program_launched = SDL_TRUE;
        int x,y,numx,numy;
         SDL_Event event;


         ville_t* ville=crea_ville(4,4);
         ville_t* ville2=crea_ville(4,15);
         ville_t* ville3=crea_ville(7,16);
         ville_t* ville5=crea_ville(17,6);
         batisseur_t *batisseur=NULL;
         colon_t *colon=crea_colon(12,5);
         guerrier_t *guerrier=crea_guerrier(8,10);
         guerrier_t *guerrier1=crea_guerrier(8,15);
         arm_long_t *archer=crea_arm_long(3,4);
         affiche_ville(cases,ville,renderer);
         affiche_ville(cases,ville2,renderer);
         affiche_ville(cases,ville3,renderer);
         affiche_ville(cases,ville5,renderer);
         affiche_colon(cases,renderer,colon);
         affiche_guerrier(cases,renderer,guerrier);
         affiche_guerrier(cases,renderer,guerrier1);
         affiche_arm_long(cases,renderer,archer);

          int tour=1;
          int choix = 0 ;
          int reset=0;

     while(program_launched){
        while (SDL_PollEvent(&event))
           {
               switch (event.type)
               {
                     case SDL_QUIT:
                         program_launched = SDL_FALSE;
                         break;

                     case SDL_MOUSEBUTTONDOWN:
                                /*faire toutes les actions*/
                                x = event.button.x;  /*récupération de la position de la souris*/
                                y = event.button.y;
                                printf("coord : x=%d, y=%d \n", x, y);
                                numx = click_case_x(x);
                                numy = click_case_y(y);
                                printf("case : i=%d, j=%d \n", numx, numy);


                                /*fonction_bandeau_inferieur*/
                                if(numx==ville->x && numy==ville->y){
                                      reset = 0 ;
                                      int choix=fonction_bandeau_ville(cases,renderer,ville);
                                            if(choix == 1){
                                              colon = crea_colon(ville->x+1,ville->y);
                                              affiche_colon(cases,renderer,colon);
                                              reset = 1;
                                            }
                                            else if(choix == 2)
                                            {
                                              batisseur_t *batisseur=crea_batisseur(4,6);
                                              affiche_batisseur(cases,renderer,batisseur);
                                              reset = 1;
                                            }
                                            else if (choix == 3)
                                            {
                                              guerrier_t *guerrier=crea_guerrier(1,5);
                                              affiche_guerrier(cases,renderer,guerrier);
                                              reset = 1;
                                            }
                                  }
                                if(colon != NULL){
                                    if(numx==colon->x && numy==colon->y){
                                    reset = 0 ;
                                    choix=fonction_bandeau_colon(cases,renderer,colon,liste_cases);
                                          if(choix == 1){
                                            ville_t * ville2 = crea_ville(colon->x,colon->y);
                                            affiche_ville(cases,ville2,renderer);
                                            colon=NULL;
                                            reset = 1;
                                          }
                                    }
                                }


                              if(batisseur != NULL){
                                if(numx==batisseur->x && numy==batisseur->y){
                                  choix = 0 ;
                                    int choix=fonction_bandeau_batisseur(cases,renderer,batisseur,liste_cases);

                                          if(choix==1){
                                          //  fonction_afficher_ferme(/*peut etre changer le plateau pour un réaffichage après*/);
                                            batisseur->nb_coup=batisseur->nb_coup-1;
                                            civ->nb_ferme=(civ->nb_ferme)+1;
                                            if(batisseur->nb_coup == 0)
                                                batisseur=NULL;
                                          }
                                          else if(choix == 2)
                                          {
                                            batisseur->nb_coup=batisseur->nb_coup-1;
                                              civ->nb_biblio=(civ->nb_biblio)+1;
                                            if(batisseur->nb_coup == 0)
                                                batisseur=NULL;
                                          }
                                    }

                                }

                                if((x > passer_tour.x && x<( passer_tour.x + passer_tour.w) && y> passer_tour.y && y < ( passer_tour.y +  passer_tour.h))){
                                    printf("tour n° :%d\n\n",tour);
                                        civ=fin_tour_civ(civ);
                                        printf("nb_ferme",civ->nb_ferme);
                                        tour++;

                                    break; /*clic pour passer au tour suivant pas le choix*/
                                }
                              if (x > rectangle_quit.x && x<(rectangle_quit.x + rectangle_quit.w) && y>rectangle_quit.y && y < (rectangle_quit.y + rectangle_quit.h))
                              {
                                  printf("\n programme quitté\n");
                                  program_launched = SDL_FALSE;
                                  break;
                              }

                            default:break;

              }

          }

      }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;

    }
