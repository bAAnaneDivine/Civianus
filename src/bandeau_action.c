
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>

#include "headers/plateau.h"
#include "headers/structure_jeu.h"
#include "headers/jeu.h"


int fonction_bandeau_ville(SDL_Rect cases[LONGUEUR_CASE][LARGEUR_CASE], SDL_Renderer *renderer){
  SDL_Event event;
  SDL_Texture *texture1=NULL;
  SDL_Texture *texture2=NULL;
  SDL_Texture *texture3=NULL;
  SDL_Texture *texture4=NULL;
  int x=0;
  int y=0;
  SDL_Rect rectangle_colon={LONGUEUR_CASE*4,0,LONGUEUR_CASE,LARGEUR_CASE}; /*choix_ville creation colon*/
  SDL_Surface * image_crea_colon=IMG_Load("./image/bouton_colon.png");
  SDL_AfficherUneImage(renderer,image_crea_colon,texture1,rectangle_colon);

  SDL_Rect rectangle_batisseur={LONGUEUR_CASE*5,0,LONGUEUR_CASE,LARGEUR_CASE}; /*choix_ville creation batisseur*/
  image_crea_colon=IMG_Load("./image/bouton_batisseur.png");
  SDL_AfficherUneImage(renderer,image_crea_colon,texture2,rectangle_batisseur);

  SDL_Rect rectangle_guerrier={LONGUEUR_CASE*6,0,LONGUEUR_CASE,LARGEUR_CASE}; /*choix_ville creation guerrier*/
  image_crea_colon=IMG_Load("./image/bouton_guerrier.png");
  SDL_AfficherUneImage(renderer,image_crea_colon,texture3,rectangle_guerrier);

  SDL_Rect rectangle_arm_long={LONGUEUR_CASE*7,0,LONGUEUR_CASE,LARGEUR_CASE}; /*choix_ville creation armée_longue*/
  image_crea_colon=IMG_Load("./image/bouton_archer.png");
  SDL_AfficherUneImage(renderer,image_crea_colon,texture4,rectangle_arm_long);


  /*    SDL_Rect rectangle_culture={LONGUEUR_CASE*9,0,LONGUEUR_CASE,LARGEUR_CASE}; // informations culture
      SDL_Rect rectangle_sciences={LONGUEUR_CASE*10,0,LONGUEUR_CASE,LARGEUR_CASE}; //informations sciences
      SDL_Rect rectangle_nom_ville={LONGUEUR_CASE*11,0,LONGUEUR_CASE,LARGEUR_CASE}; //informations nom_ville
      SDL_Rect rectangle_niveau_ville={LONGUEUR_CASE*12,0,LONGUEUR_CASE,LARGEUR_CASE}; //informations niveau_ville
*/
        /*
        text=ville->culture;
        afficher_texte(ttf* fond, SDL_Rect rectangle_culture,SDL_Renderer * renderer, TTF_Font* font, char* text, SDL_Color* color);
        afficher_texte(ttf* fond, SDL_Rect rectangle_sciences,SDL_Renderer * renderer, TTF_Font* font, char* text, SDL_Color* color);
        afficher_texte(ttf* fond, SDL_Rect rectangle_nom_ville,SDL_Renderer * renderer, TTF_Font* font, char* text, SDL_Color* color);
        afficher_texte(ttf* fond, SDL_Rect rectangle_niveau_ville,SDL_Renderer * renderer, TTF_Font* font, char* text, SDL_Color* color);

        */
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
                            printf("\n boucle4 \n\n");

                            if( (x > rectangle_colon.x && x<( rectangle_colon.x +  rectangle_colon.w) && y> rectangle_colon.y && y < ( rectangle_colon.y +  rectangle_colon.h)) ){
                                choix=1;
                                image_crea_colon=IMG_Load("./image/check.png");
                                SDL_AfficherUneImage(renderer,image_crea_colon,texture1,rectangle_colon);
                                image_crea_colon=IMG_Load("./image/check.png");
                                SDL_AfficherUneImage(renderer,image_crea_colon,texture2,rectangle_batisseur);
                                image_crea_colon=IMG_Load("./image/check.png");
                                SDL_AfficherUneImage(renderer,image_crea_colon,texture3,rectangle_guerrier);
                                image_crea_colon=IMG_Load("./image/check.png");
                                SDL_AfficherUneImage(renderer,image_crea_colon,texture4,rectangle_arm_long);
                                SDL_Rect rectangle_colon={0,0,0,0}; //choix_ville creation colon
                                SDL_Rect rectangle_batisseur={0,0,0,0}; //choix_ville creation batisseur
                                SDL_Rect rectangle_guerrier={0,0,0,0}; //choix_ville creation guerrier
                                SDL_Rect rectangle_arm_long={0,0,0,0};
                                program_launched = SDL_FALSE;

                            }
                            else if((x >  rectangle_batisseur.x && x<(rectangle_batisseur.x +  rectangle_batisseur.w) && y> rectangle_batisseur.y && y < ( rectangle_batisseur.y +  rectangle_batisseur.h))){
                              choix=2;
                              image_crea_colon=IMG_Load("./image/check.png");
                              SDL_AfficherUneImage(renderer,image_crea_colon,texture1,rectangle_colon);
                              image_crea_colon=IMG_Load("./image/check.png");
                              SDL_AfficherUneImage(renderer,image_crea_colon,texture2,rectangle_batisseur);
                              image_crea_colon=IMG_Load("./image/check.png");
                              SDL_AfficherUneImage(renderer,image_crea_colon,texture3,rectangle_guerrier);
                              image_crea_colon=IMG_Load("./image/check.png");
                              SDL_AfficherUneImage(renderer,image_crea_colon,texture4,rectangle_arm_long);
                              SDL_Rect rectangle_colon={0,0,0,0}; //choix_ville creation colon
                              SDL_Rect rectangle_batisseur={0,0,0,0}; //choix_ville creation batisseur
                              SDL_Rect rectangle_guerrier={0,0,0,0}; //choix_ville creation guerrier
                              SDL_Rect rectangle_arm_long={0,0,0,0};
                              program_launched = SDL_FALSE;

                            }
                            else if((x > rectangle_guerrier.x && x<(rectangle_guerrier.x + rectangle_guerrier.w) && y>rectangle_guerrier.y && y < (rectangle_guerrier.y + rectangle_guerrier.h))){
                              choix=3;
                              image_crea_colon=IMG_Load("./image/check.png");
                              SDL_AfficherUneImage(renderer,image_crea_colon,texture1,rectangle_colon);
                              image_crea_colon=IMG_Load("./image/check.png");
                              SDL_AfficherUneImage(renderer,image_crea_colon,texture2,rectangle_batisseur);
                              image_crea_colon=IMG_Load("./image/check.png");
                              SDL_AfficherUneImage(renderer,image_crea_colon,texture3,rectangle_guerrier);
                              image_crea_colon=IMG_Load("./image/check.png");
                              SDL_AfficherUneImage(renderer,image_crea_colon,texture4,rectangle_arm_long);
                              SDL_Rect rectangle_colon={0,0,0,0}; //choix_ville creation colon
                              SDL_Rect rectangle_batisseur={0,0,0,0}; //choix_ville creation batisseur
                              SDL_Rect rectangle_guerrier={0,0,0,0}; //choix_ville creation guerrier
                              SDL_Rect rectangle_arm_long={0,0,0,0};
                              program_launched = SDL_FALSE;

                            }
                           else if((x > rectangle_arm_long.x && x<(rectangle_arm_long.x + rectangle_arm_long.w) && y>rectangle_arm_long.y && y < (rectangle_arm_long.y + rectangle_arm_long.h) ) ) {
                              choix=4;
                              image_crea_colon=IMG_Load("./image/check.png");
                              SDL_AfficherUneImage(renderer,image_crea_colon,texture1,rectangle_colon);
                              image_crea_colon=IMG_Load("./image/check.png");
                              SDL_AfficherUneImage(renderer,image_crea_colon,texture2,rectangle_batisseur);
                              image_crea_colon=IMG_Load("./image/check.png");
                              SDL_AfficherUneImage(renderer,image_crea_colon,texture3,rectangle_guerrier);
                              image_crea_colon=IMG_Load("./image/check.png");
                              SDL_AfficherUneImage(renderer,image_crea_colon,texture4,rectangle_arm_long);
                              SDL_Rect rectangle_colon={0,0,0,0}; //choix_ville creation colon
                              SDL_Rect rectangle_batisseur={0,0,0,0}; //choix_ville creation batisseur
                              SDL_Rect rectangle_guerrier={0,0,0,0}; //choix_ville creation guerrier
                              SDL_Rect rectangle_arm_long={0,0,0,0};
                              program_launched = SDL_FALSE;
                            }

                       default:
                        break;

                    }
            }
      }
      return(choix);
}





int fonction_bandeau_batisseur(SDL_Rect cases[LONGUEUR_CASE][LARGEUR_CASE], SDL_Renderer *renderer,batisseur_t *batisseur,int liste_cases[N][N]){
  SDL_Event event;
  SDL_Texture *texture1=NULL;
  SDL_Texture *texture2=NULL;
  int x=0;
  int y=0;
  int numx,numy;
      SDL_Rect rectangle_ferme={LONGUEUR_CASE*4,0,LONGUEUR_CASE,LARGEUR_CASE}; /*choix_ville creation colon*/
      SDL_Surface * image_crea_batisseur=IMG_Load("./image/bouton_ferme.png");
      SDL_AfficherUneImage(renderer,image_crea_batisseur,texture1,rectangle_ferme);

      SDL_Rect rectangle_biblio={LONGUEUR_CASE*5,0,LONGUEUR_CASE,LARGEUR_CASE}; /*choix_ville creation batisseur*/
      image_crea_batisseur=IMG_Load("./image/bouton_biblio.png");
      SDL_AfficherUneImage(renderer,image_crea_batisseur,texture2,rectangle_biblio);


printf("\nboucle1 \n\n");


        /*
        text=ville->culture;
        afficher_texte(ttf* fond, SDL_Rect rectangle_culture,SDL_Renderer * renderer, TTF_Font* font, char* text, SDL_Color* color);
        afficher_texte(ttf* fond, SDL_Rect rectangle_sciences,SDL_Renderer * renderer, TTF_Font* font, char* text, SDL_Color* color);
        afficher_texte(ttf* fond, SDL_Rect rectangle_nom_ville,SDL_Renderer * renderer, TTF_Font* font, char* text, SDL_Color* color);
        afficher_texte(ttf* fond, SDL_Rect rectangle_niveau_ville,SDL_Renderer * renderer, TTF_Font* font, char* text, SDL_Color* color);

        */
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

                            if( (x > rectangle_ferme.x && x<( rectangle_ferme.x +  rectangle_ferme.w) && y> rectangle_ferme.y && y < ( rectangle_ferme.y +  rectangle_ferme.h)) ){
                                choix=1;
                                image_crea_batisseur=IMG_Load("./image/check.png");
                                SDL_AfficherUneImage(renderer,image_crea_batisseur,texture1,rectangle_ferme);
                                image_crea_batisseur=IMG_Load("./image/check.png");
                                SDL_AfficherUneImage(renderer,image_crea_batisseur,texture2,rectangle_biblio);
                                SDL_Rect rectangle_ferme={0,0,0,0};
                                SDL_Rect rectangle_biblio={0,0,0,0};
                                program_launched = SDL_FALSE;

                            }
                            else if((x >  rectangle_biblio.x && x<(rectangle_biblio.x +  rectangle_biblio.w) && y> rectangle_biblio.y && y < ( rectangle_biblio.y +  rectangle_biblio.h))){
                              choix=2;
                              image_crea_batisseur=IMG_Load("./image/check.png");
                              SDL_AfficherUneImage(renderer,image_crea_batisseur,texture1,rectangle_ferme);
                              image_crea_batisseur=IMG_Load("./image/check.png");
                              SDL_AfficherUneImage(renderer,image_crea_batisseur,texture2,rectangle_biblio);
                              SDL_Rect rectangle_ferme={0,0,0,0};
                              SDL_Rect rectangle_biblio={0,0,0,0};
                              program_launched = SDL_FALSE;

                          }

                       default:
                        break;
                    }
            }
      }
      return(choix);
}




int fonction_bandeau_colon(SDL_Rect cases[LONGUEUR_CASE][LARGEUR_CASE], SDL_Renderer *renderer,colon_t *colon,int liste_cases[N][N]){
  SDL_Event event;
  SDL_Texture *texture1=NULL;
  SDL_Texture *texture2=NULL;
  SDL_Texture *texture3=NULL;
  SDL_Texture *texture4=NULL;
  SDL_Texture *texture5=NULL;
  SDL_Texture *texture6=NULL;
  int x=0;
  int y=0;
  int numx,numy,coorx,coory;

      SDL_Rect rectangle_ville={LONGUEUR_CASE*4,0,LONGUEUR_CASE,LARGEUR_CASE}; /*choix_ville creation colon*/
      SDL_Rect rectangle_retour={LONGUEUR_CASE*5,0,LONGUEUR_CASE,LARGEUR_CASE};
      SDL_Surface * image_crea_ville=IMG_Load("./image/bouton_ville1.png");
      SDL_AfficherUneImage(renderer,image_crea_ville,texture1,rectangle_ville);


        int choix=0;
        SDL_bool program_launched = SDL_TRUE;

      while (program_launched){
          while ( (SDL_PollEvent(&event) )){

              printf("\n boucle2 colon \n\n");

                switch(event.type){


                  case SDL_QUIT:
                      program_launched = SDL_FALSE;
                      break;

                    case(SDL_MOUSEBUTTONDOWN):

                        x=event.button.x;
                        y=event.button.y;
                        numx=click_case_x(x);
                        numy=click_case_y(y);
                            printf("\n boucle4 colon\n\n");

                            if( (x > rectangle_ville.x && x<( rectangle_ville.x +  rectangle_ville.w) && y> rectangle_ville.y && y < ( rectangle_ville.y +  rectangle_ville.h)) ){
                                choix=1;
                                image_crea_ville=IMG_Load("./image/check.png");
                                SDL_AfficherUneImage(renderer,image_crea_ville,texture1,rectangle_ville);
                                image_crea_ville=IMG_Load("./image/check.png");
                                SDL_AfficherUneImage(renderer,image_crea_ville,texture2,rectangle_retour);
                                SDL_Rect rectangle_ville={0,0,0,0}; //choix_ville creation colon
                                SDL_Rect rectangle_retour={0,0,0,0}; //choix_ville creation batisseur
                                program_launched = SDL_FALSE;

                            }
                            else if((x >  rectangle_retour.x && x<(rectangle_retour.x +  rectangle_retour.w) && y> rectangle_retour.y && y < ( rectangle_retour.y +  rectangle_retour.h))){
                            choix=2;
                            image_crea_ville=IMG_Load("./image/check.png");
                            SDL_AfficherUneImage(renderer,image_crea_ville,texture1,rectangle_ville);
                            image_crea_ville=IMG_Load("./image/check.png");
                            SDL_AfficherUneImage(renderer,image_crea_ville,texture2,rectangle_retour);
                            SDL_Rect rectangle_ville={0,0,0,0}; //choix_ville creation colon
                            SDL_Rect rectangle_retour={0,0,0,0}; //choix_ville creation batisseur
                            fonction_mouvement_colon(cases,renderer,colon,liste_cases);
                            program_launched = SDL_FALSE;

                          }

                    }
            }
      }
      return(choix);
}







int fonction_bandeau_guerrier(SDL_Rect cases[LONGUEUR_CASE][LARGEUR_CASE], SDL_Renderer *renderer,guerrier_t * guerrier,int liste_cases[N][N]){
  SDL_Event event;
  SDL_Texture *texture1=NULL;

  int x=0;
  int y=0;
  int numx,numy;

      SDL_Rect rectangle_attaque={LONGUEUR_CASE*4,0,LONGUEUR_CASE,LARGEUR_CASE};
      SDL_Surface * image_bouton_attque=IMG_Load("./image/bouton_attaque.png");
      SDL_AfficherUneImage(renderer,image_bouton_attque,texture1,rectangle_attaque);
      SDL_Rect rectangle_mouvement={LONGUEUR_CASE*5,0,LONGUEUR_CASE,LARGEUR_CASE};
      SDL_Surface * image_bouton_mouvement=IMG_Load("./image/bouton_mouvement.png");
      SDL_AfficherUneImage(renderer,image_bouton_attque,texture1,rectangle_mouvement);
      SDL_Rect rectangle_retour={LONGUEUR_CASE*6,0,LONGUEUR_CASE,LARGEUR_CASE};
      SDL_Surface * image_bouton_retour=IMG_Load("./image/bouton_retour.png");
      SDL_AfficherUneImage(renderer,image_bouton_attque,texture1,rectangle_retour);

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

                            if( (x > rectangle_attaque.x && x<( rectangle_attaque.x +  rectangle_attaque.w) && y> rectangle_attaque.y && y < ( rectangle_attaque.y +  rectangle_attaque.h)) ){
                                choix=1;
                                image_bouton_attque=IMG_Load("./image/check.png");
                                SDL_AfficherUneImage(renderer,image_bouton_attque,texture1,rectangle_attaque);
                                SDL_Rect rectangle_attaque={0,0,0,0};

                                program_launched = SDL_FALSE;

                            }
                            else if( (x > rectangle_mouvement.x && x<( rectangle_mouvement.x +  rectangle_mouvement.w) && y> rectangle_mouvement.y && y < ( rectangle_mouvement.y +  rectangle_mouvement.h)) ){
                                choix=1;
                                image_bouton_attque=IMG_Load("./image/check.png");
                                SDL_AfficherUneImage(renderer,image_bouton_attque,texture1,rectangle_mouvement);
                                SDL_Rect rectangle_mouvement={0,0,0,0};
                                fonction_mouvement_guerrier(cases,renderer,guerrier,liste_cases);
                                program_launched = SDL_FALSE;

                            }
                            else if( (x > rectangle_retour.x && x<( rectangle_retour.x +  rectangle_retour.w) && y> rectangle_retour.y && y < ( rectangle_retour.y +  rectangle_retour.h)) ){
                                choix=1;
                                image_bouton_attque=IMG_Load("./image/check.png");
                                SDL_AfficherUneImage(renderer,image_bouton_attque,texture1,rectangle_retour);
                                SDL_Rect rectangle_retour={0,0,0,0};

                                program_launched = SDL_FALSE;

                            }


                       default:
                        break;
                    }
            }
      }
      return(choix);
}
