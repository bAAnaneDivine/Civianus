
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include "headers/admin_SDL.h"
#include "headers/plateau.h"
#include "headers/menu.h"
#include "headers/structure_jeu.h"
#include "headers/jeu.h"




int fonction_bandeau_ville(SDL_Rect cases[N][N], SDL_Renderer *renderer){
  SDL_Event event;
  SDL_Texture *texture=NULL;
      SDL_Rect rectangle_colon={LONGUEUR_CASE*4,0,LONGUEUR_CASE,LARGEUR_CASE}; //choix_ville creation colon
      SDL_Surface * image_crea_colon=IMG_Load("./image/Joueur1.png");
      SDL_AfficherUneImage(renderer,image_crea_colon,texture,rectangle_colon);

      SDL_Rect rectangle_batisseur={LONGUEUR_CASE*5,0,LONGUEUR_CASE,LARGEUR_CASE}; //choix_ville creation batisseur
      image_crea_colon=IMG_Load("./image/Joueur2.png");
      SDL_AfficherUneImage(renderer,image_crea_colon,texture,rectangle_batisseur);

      SDL_Rect rectangle_guerrier={LONGUEUR_CASE*6,0,LONGUEUR_CASE,LARGEUR_CASE}; //choix_ville creation guerrier
      image_crea_colon=IMG_Load("./image/Joueur3.png");
      SDL_AfficherUneImage(renderer,image_crea_colon,texture,rectangle_guerrier);

      SDL_Rect rectangle_arm_long={LONGUEUR_CASE*7,0,LONGUEUR_CASE,LARGEUR_CASE}; //choix_ville creation armée_longue
      image_crea_colon=IMG_Load("./image/Joueur4.png");
      SDL_AfficherUneImage(renderer,image_crea_colon,texture,rectangle_arm_long);

     SDL_Rect rectangle_arm_spec={LONGUEUR_CASE*8,0,LONGUEUR_CASE,LARGEUR_CASE}; //choix_ville creation armée_specifique

  /*    SDL_Rect rectangle_culture={LONGUEUR_CASE*9,0,LONGUEUR_CASE,LARGEUR_CASE}; // informations culture
      SDL_Rect rectangle_sciences={LONGUEUR_CASE*10,0,LONGUEUR_CASE,LARGEUR_CASE}; //informations sciences
      SDL_Rect rectangle_nom_ville={LONGUEUR_CASE*11,0,LONGUEUR_CASE,LARGEUR_CASE}; //informations nom_ville
      SDL_Rect rectangle_niveau_ville={LONGUEUR_CASE*12,0,LONGUEUR_CASE,LARGEUR_CASE}; //informations niveau_ville
*/
printf("\nboucle1 \n\n");

        /*
        afficher_texte(ttf* fond, SDL_Rect rectangle_culture,SDL_Renderer * renderer, TTF_Font* font, char* text, SDL_Color* color);
        afficher_texte(ttf* fond, SDL_Rect rectangle_sciences,SDL_Renderer * renderer, TTF_Font* font, char* text, SDL_Color* color);
        afficher_texte(ttf* fond, SDL_Rect rectangle_nom_ville,SDL_Renderer * renderer, TTF_Font* font, char* text, SDL_Color* color);
        afficher_texte(ttf* fond, SDL_Rect rectangle_niveau_ville,SDL_Renderer * renderer, TTF_Font* font, char* text, SDL_Color* color);

        */
            while (SDL_PollEvent(&event)) {

              printf("\n boucle2 \n\n");

                switch(event.type){
                  printf("\n boucle3 \n\n");

                  int x=event.button.x;
                  int y=event.button.y;
                    case(SDL_MOUSEBUTTONDOWN):

                            printf("\n boucle4 \n\n");

                            if((x > rectangle_colon.x && x<( rectangle_colon.x +  rectangle_colon.w) && y> rectangle_colon.y && y < ( rectangle_colon.y +  rectangle_colon.h))){
                                colon_t* colon=crea_colon(4,4);
                                affiche_colon(cases,renderer,colon);
                                printf("\ncolon creer\n\n");
                                return 1;
                            }
                            if((x >  rectangle_batisseur.x && x<(rectangle_batisseur.x +  rectangle_batisseur.w) && y> rectangle_batisseur.y && y < ( rectangle_batisseur.y +  rectangle_batisseur.h))){
                              batisseur_t *batisseur=crea_batisseur(x,y);
                              affiche_batisseur(cases,renderer,batisseur);
                              printf("\nbatisseur creer\n\n");
                              return 2;
                            }
                            if((x > rectangle_guerrier.x && x<(rectangle_guerrier.x + rectangle_guerrier.w) && y>rectangle_guerrier.y && y < (rectangle_guerrier.y + rectangle_guerrier.h))){
                              guerrier_t *guerrier=crea_guerrier(x,y);
                              affiche_guerrier(cases,renderer,guerrier);
                            }
                            if( (x > rectangle_arm_long.x && x<(rectangle_arm_long.x + rectangle_arm_long.w) && y>rectangle_arm_long.y && y < (rectangle_arm_long.y + rectangle_arm_long.h) ) ) {
                              crea_arm_long(x,y);

                            }
                            if((x > rectangle_arm_spec.x && x<(rectangle_arm_spec.x + rectangle_arm_spec.w) && y>rectangle_arm_spec.y && y < (rectangle_arm_spec.y + rectangle_arm_spec.h))){
                              crea_arm_spec(x,y);
                            }
                            clean_ressources(NULL,NULL,NULL);//image bouton pour juste bandeau superieur vierge
                              //  clean bandeau_inferieur;

                    }
            }
}







int  jeu(int civilization,SDL_Window* window, SDL_Renderer* renderer){

  SDL_initialisation();
     Uint32 affich_fenetre=0;
     SDL_Rect cases[N][N];
     SDL_Texture * texture=NULL;
     int height = 1000;
     int width = 700;


     SDL_Rect passer_tour={LONGUEUR_CASE,0,LONGUEUR_CASE,LARGEUR_CASE};
     SDL_Rect btn_crea_colon={LONGUEUR_CASE*3,0,LONGUEUR_CASE,LARGEUR_CASE};
     SDL_Surface * image_crea_colon=IMG_Load("./image/nombre_joueur.png");
     SDL_AfficherUneImage(renderer,image_crea_colon,texture,btn_crea_colon);
      SDL_Rect rectangle_quit={0,0,LONGUEUR_CASE,LARGEUR_CASE};
      crea_plat(cases);
        SDL_bool program_launched = SDL_TRUE;
        int x,y,numx,numy;
         SDL_Event event;

  /*       ----------->   */        ville_t* ville=crea_ville(4,4);

          //affiche_ville(cases,ville,4,4,renderer);
          int tour=1;
     while(program_launched){
        while (SDL_PollEvent(&event))
           {
               switch (event.type)
               {
                     case SDL_QUIT:
                         program_launched = SDL_FALSE;
                         break;

                     case SDL_MOUSEBUTTONDOWN:
                                //faire toutes les actions
                                x = event.button.x;  //récupération de la position de la souris
                                y = event.button.y;
                                printf("coord : x=%d, y=%d \n", x, y);
                                numx = click_case_x(x);
                                numy = click_case_y(y);
                                printf("case : i=%d, j=%d \n", numx, numy);


                                //fonction_bandeau_inferieur
                                if(numx==ville->x && numy==ville->y){
                                  fonction_bandeau_ville(cases,renderer);

                                  affiche_ville(cases,ville,renderer);

                                }

                                if((x > passer_tour.x && x<( passer_tour.x + passer_tour.w) && y> passer_tour.y && y < ( passer_tour.y +  passer_tour.h))){
                                    printf("tour n° :%d\n\n",tour);
                                    affiche_ville(cases,ville,renderer);
                                        tour++;

                                    break; //clic pour passer au tour suivant pas le choix

                                }
                                if((x > btn_crea_colon.x && x<( btn_crea_colon.x + btn_crea_colon.w) && y> btn_crea_colon.y && y < ( btn_crea_colon.y +  btn_crea_colon.h))){

        /*       ----------->   */     colon_t* colon=crea_colon(12,12);

                                affiche_colon(cases,renderer,colon);


                                }


                              if (x > rectangle_quit.x && x<(rectangle_quit.x + rectangle_quit.w) && y>rectangle_quit.y && y < (rectangle_quit.y + rectangle_quit.h))
                              {
                                  printf("\n programme quitté\n");
                                  program_launched = SDL_FALSE;
                                  break;
                              }


              }

          }

      }
  free(ville);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;

    }
