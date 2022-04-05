
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include "headers/plateau.h"
#include "headers/structure_jeu.h"



int fonction_mouvement_guerrier(SDL_Rect cases[LONGUEUR_CASE][LARGEUR_CASE], SDL_Renderer *renderer,guerrier_t *guerrier,int liste_cases[N][N]){
  SDL_Event event;
  SDL_Texture *texture1=NULL;

  int x=0;
  int y=0;
  int numx,numy;

printf("\nboucle1 \n\n");


        int choix=0;
        SDL_bool program_launched = SDL_TRUE;

      while (program_launched){
          while ( (SDL_PollEvent(&event) )){

              printf("\n boucle2 \n\n");

                switch(event.type){


                  case SDL_QUIT:
                      program_launched = SDL_FALSE;
                      break;

                    case(SDL_MOUSEBUTTONDOWN):

                        x=event.button.x;
                        y=event.button.y;
                        numx=click_case_x(x);
                        numy=click_case_y(y);
                            printf("\n boucle4 \n\n");


                            if((numx==(guerrier->x)+1 && numy==(guerrier->y)) ){

                             SDL_Surface *image=IMG_Load("./image/herbe.png");
                             SDL_AfficherUneImage(renderer,image,texture1,cases[guerrier->x][guerrier->y-1]);
                             guerrier->x=numx;
                             image=IMG_Load("./image/guerrier.png");
                               SDL_AfficherUneImage(renderer,image,texture1,cases[(guerrier->x)][(guerrier->y)-1]);
                             program_launched = SDL_FALSE;
                           }
                           /* reussi */
                           else if((numx==(guerrier->x) && numy==(guerrier->y)+1) ){

                             SDL_Surface *image=IMG_Load("./image/herbe.png");
                             SDL_AfficherUneImage(renderer,image,texture1,cases[guerrier->x][guerrier->y-1]);
                             guerrier->y=numy;
                             image=IMG_Load("./image/guerrier.png");
                               SDL_AfficherUneImage(renderer,image,texture1,cases[(guerrier->x)][(guerrier->y)-1]);
                             program_launched = SDL_FALSE;

                           }

                           else if((numx==(guerrier->x)-1 && numy==(guerrier->y)) ){

                             SDL_Surface *image=IMG_Load("./image/herbe.png");
                             SDL_AfficherUneImage(renderer,image,texture1,cases[guerrier->x][guerrier->y-1]);
                             guerrier->x=numx;
                             image=IMG_Load("./image/guerrier.png");
                               SDL_AfficherUneImage(renderer,image,texture1,cases[(guerrier->x)][(guerrier->y)-1]);
                             program_launched = SDL_FALSE;

                           }

                           else if((numx==(guerrier->x) && numy==(guerrier->y)-1) ){

                             SDL_Surface *image=IMG_Load("./image/herbe.png");
                             SDL_AfficherUneImage(renderer,image,texture1,cases[guerrier->x][guerrier->y-1]);
                             guerrier->y=numy;
                             image=IMG_Load("./image/guerrier.png");
                             SDL_AfficherUneImage(renderer,image,texture1,cases[(guerrier->x)][(guerrier->y)-1]);
                             program_launched = SDL_FALSE;

                           }

                       default:
                        break;
                    }
            }
      }
      return(choix);
}


int fonction_mouvement_colon(SDL_Rect cases[LONGUEUR_CASE][LARGEUR_CASE], SDL_Renderer *renderer,colon_t *colon,int liste_cases[N][N]){
  SDL_Event event;
  SDL_Texture *texture1=NULL;

  int x=0;
  int y=0;
  int numx,numy;

printf("\nboucle1 \n\n");


        int choix=0;
        SDL_bool program_launched = SDL_TRUE;

      while (program_launched){
          while ( (SDL_PollEvent(&event) )){

              printf("\n boucle2 \n\n");

                switch(event.type){


                  case SDL_QUIT:
                      program_launched = SDL_FALSE;
                      break;

                    case(SDL_MOUSEBUTTONDOWN):

                        x=event.button.x;
                        y=event.button.y;
                        numx=click_case_x(x);
                        numy=click_case_y(y);
                            printf("\n boucle4 \n\n");


                             if((numx==(colon->x)+1 && numy==(colon->y)) ){

                              SDL_Surface *image=IMG_Load("./image/herbe.png");
                              SDL_AfficherUneImage(renderer,image,texture1,cases[colon->x][colon->y-1]);
                              colon->x=numx;
                              image=IMG_Load("./image/colon.png");
                                SDL_AfficherUneImage(renderer,image,texture1,cases[(colon->x)][(colon->y)-1]);
                              program_launched = SDL_FALSE;
                            }
                            /* reussi */
                            else if((numx==(colon->x) && numy==(colon->y)+1) ){

                              SDL_Surface *image=IMG_Load("./image/herbe.png");
                              SDL_AfficherUneImage(renderer,image,texture1,cases[colon->x][colon->y-1]);
                              colon->y=numy;
                              image=IMG_Load("./image/colon.png");
                                SDL_AfficherUneImage(renderer,image,texture1,cases[(colon->x)][(colon->y)-1]);
                              program_launched = SDL_FALSE;

                            }

                            else if((numx==(colon->x)-1 && numy==(colon->y)) ){

                              SDL_Surface *image=IMG_Load("./image/herbe.png");
                              SDL_AfficherUneImage(renderer,image,texture1,cases[colon->x][colon->y-1]);
                              colon->x=numx;
                              image=IMG_Load("./image/colon.png");
                                SDL_AfficherUneImage(renderer,image,texture1,cases[(colon->x)][(colon->y)-1]);
                              program_launched = SDL_FALSE;

                            }

                            else if((numx==(colon->x) && numy==(colon->y)-1) ){

                              SDL_Surface *image=IMG_Load("./image/herbe.png");
                              SDL_AfficherUneImage(renderer,image,texture1,cases[colon->x][colon->y-1]);
                              colon->y=numy;
                              image=IMG_Load("./image/colon.png");
                              SDL_AfficherUneImage(renderer,image,texture1,cases[(colon->x)][(colon->y)-1]);
                              program_launched = SDL_FALSE;

                            }

                       default:
                        break;
                    }
            }
      }
      return(choix);
}


int fonction_mouvement_batisseur(SDL_Rect cases[LONGUEUR_CASE][LARGEUR_CASE], SDL_Renderer *renderer,batisseur_t *batisseur,int liste_cases[N][N]){
  SDL_Event event;
  SDL_Texture *texture1=NULL;

  int x=0;
  int y=0;
  int numx,numy;

printf("\nboucle1 \n\n");


        int choix=0;
        SDL_bool program_launched = SDL_TRUE;

      while (program_launched){
          while ( (SDL_PollEvent(&event) )){

              printf("\n boucle2 \n\n");

                switch(event.type){


                  case SDL_QUIT:
                      program_launched = SDL_FALSE;
                      break;

                    case(SDL_MOUSEBUTTONDOWN):

                        x=event.button.x;
                        y=event.button.y;
                        numx=click_case_x(x);
                        numy=click_case_y(y);
                            printf("\n boucle4 \n\n");


                             if((numx==(batisseur->x)+1 && numy==(batisseur->y)) ){

                              SDL_Surface *image=IMG_Load("./image/herbe.png");
                              SDL_AfficherUneImage(renderer,image,texture1,cases[batisseur->x][batisseur->y-1]);
                              batisseur->x=numx;
                              image=IMG_Load("./image/batisseur.png");
                                SDL_AfficherUneImage(renderer,image,texture1,cases[(batisseur->x)][(batisseur->y)-1]);
                              program_launched = SDL_FALSE;
                            }
                            /* reussi */
                            else if((numx==(batisseur->x) && numy==(batisseur->y)+1) ){

                              SDL_Surface *image=IMG_Load("./image/herbe.png");
                              SDL_AfficherUneImage(renderer,image,texture1,cases[batisseur->x][batisseur->y-1]);
                              batisseur->y=numy;
                              image=IMG_Load("./image/batisseur.png");
                                SDL_AfficherUneImage(renderer,image,texture1,cases[(batisseur->x)][(batisseur->y)-1]);
                              program_launched = SDL_FALSE;

                            }

                            else if((numx==(batisseur->x)-1 && numy==(batisseur->y)) ){

                              SDL_Surface *image=IMG_Load("./image/herbe.png");
                              SDL_AfficherUneImage(renderer,image,texture1,cases[batisseur->x][batisseur->y-1]);
                              batisseur->x=numx;
                              image=IMG_Load("./image/batisseur.png");
                                SDL_AfficherUneImage(renderer,image,texture1,cases[(batisseur->x)][(batisseur->y)-1]);
                              program_launched = SDL_FALSE;

                            }

                            else if((numx==(batisseur->x) && numy==(batisseur->y)-1) ){

                              SDL_Surface *image=IMG_Load("./image/herbe.png");
                              SDL_AfficherUneImage(renderer,image,texture1,cases[batisseur->x][batisseur->y-1]);
                              batisseur->y=numy;
                              image=IMG_Load("./image/batisseur.png");
                              SDL_AfficherUneImage(renderer,image,texture1,cases[(batisseur->x)][(batisseur->y)-1]);
                              program_launched = SDL_FALSE;

                            }

                       default:
                        break;
                    }
            }
      }
      return(choix);
}


int fonction_mouvement_archer(SDL_Rect cases[LONGUEUR_CASE][LARGEUR_CASE], SDL_Renderer *renderer,arm_long_t * arm_long,int liste_cases[N][N]){
  SDL_Event event;
  SDL_Texture *texture1=NULL;

  int x=0;
  int y=0;
  int numx,numy;

printf("\nboucle1 \n\n");


        int choix=0;
        SDL_bool program_launched = SDL_TRUE;

      while (program_launched){
          while ( (SDL_PollEvent(&event) )){

              printf("\n boucle2 \n\n");

                switch(event.type){


                  case SDL_QUIT:
                      program_launched = SDL_FALSE;
                      break;

                    case(SDL_MOUSEBUTTONDOWN):

                        x=event.button.x;
                        y=event.button.y;
                        numx=click_case_x(x);
                        numy=click_case_y(y);
                            printf("\n boucle4 \n\n");


                             if((numx==(arm_long->x)+1 && numy==(arm_long->y)) ){

                              SDL_Surface *image=IMG_Load("./image/herbe.png");
                              SDL_AfficherUneImage(renderer,image,texture1,cases[arm_long->x][arm_long->y-1]);
                              arm_long->x=numx;
                              image=IMG_Load("./image/archer.png");
                                SDL_AfficherUneImage(renderer,image,texture1,cases[(arm_long->x)][(arm_long->y)-1]);
                              program_launched = SDL_FALSE;
                            }
                            /* reussi */
                            else if((numx==(arm_long->x) && numy==(arm_long->y)+1) ){

                              SDL_Surface *image=IMG_Load("./image/herbe.png");
                              SDL_AfficherUneImage(renderer,image,texture1,cases[arm_long->x][arm_long->y-1]);
                              arm_long->y=numy;
                              image=IMG_Load("./image/archer.png");;
                                SDL_AfficherUneImage(renderer,image,texture1,cases[(arm_long->x)][(arm_long->y)-1]);
                              program_launched = SDL_FALSE;

                            }

                            else if((numx==(arm_long->x)-1 && numy==(arm_long->y)) ){

                              SDL_Surface *image=IMG_Load("./image/herbe.png");
                              SDL_AfficherUneImage(renderer,image,texture1,cases[arm_long->x][arm_long->y-1]);
                              arm_long->x=numx;
                              image=IMG_Load("./image/archer.png");
                                SDL_AfficherUneImage(renderer,image,texture1,cases[(arm_long->x)][(arm_long->y)-1]);
                              program_launched = SDL_FALSE;

                            }

                            else if((numx==(arm_long->x) && numy==(arm_long->y)-1) ){

                              SDL_Surface *image=IMG_Load("./image/herbe.png");
                              SDL_AfficherUneImage(renderer,image,texture1,cases[arm_long->x][arm_long->y-1]);
                              arm_long->y=numy;
                              image=IMG_Load("./image/archer.png");
                              SDL_AfficherUneImage(renderer,image,texture1,cases[(arm_long->x)][(arm_long->y)-1]);
                              program_launched = SDL_FALSE;

                            }

                       default:
                        break;
                    }
            }
      }
      return(choix);
}
