#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include "headers/admin_SDL.h"
#include "headers/plateau.h"
#include "headers/menu.h"
#include "headers/structure_jeu.h"



  void  fonction_bandeau_inferieur(SDL_Rect cases[N][N],int choix, SDL_Renderer *renderer,SDL_Surface *texture){

    SDL_Event event;

    switch (choix) {
      case 1: // cas ou on click sur la ville
          /*  sdl_afficher_un_texte(info_ville,cases[19][10]);
            sdl_afficher_un_texte(info_ville,);
            sdl_afficher_un_texte(info_ville,);
*/
              while (SDL_PollEvent(&event))
                {
                  if(event.type==SDL_MOUSEBUTTONDOWN){
                      //SDL_AfficherUnTexte
                      if((x > cases[0][5].x && x<( cases[19][0].x +  cases[19][0].w) && y> cases[19][0].y && y < ( cases[19][0].y +  cases[19][0].h))){
                        crea_colon(cases,x,y);
                        /*etat de tout les boutons a 0 */
                      }
                      if((x >  cases[19][1].x && x<( cases[19][1].x +  cases[19][1].w) && y> cases[19][1].y && y < ( cases[19][1].y +  cases[19][1].h))){
                        crea_batisseur(cases,x,y);
                      }
                      if((x >  cases[19][2].x && x<(cases[19][2].x + cases[19][2].w) && y>cases[19][2].y && y < (cases[19][2].y + cases[19][2].h))){
                        crea_guerrier(cases,x,y);
                      }
                      if((x > cases[19][3].x && x<(cases[19][3].x + cases[19][3].w) && y>cases[19][3].y && y < (cases[19][3].y + cases[19][3].h)){
                        crea_arm_long(cases,x,y);
                      }
                      if((x > cases[19][4].x && x<(cases[19][4].x + cases[19][4].w) && y>cases[19][4].y && y < (cases[19][4].y + cases[19][4].h))){
                        crea_arm_spec(cases,x,y);
                      }
                      clean resources(texture ou renderer);//image bouton pour juste bandeau inferieur vierge
                        //  clean bandeau_inferieur;
                        break;
                }
            }
            break;
    case 2: // cas ou on click sur le colon
/*
    sdl_afficher_un_texte(info_colon,cases[19][10]);
    sdl_afficher_un_texte(info_ville,);
    sdl_afficher_un_texte(info_ville,);
    */
    SDL_Surface *image_colon;
    image_colon=IMG_Load("./image/de10.png");
    SDL_AfficherUneImage(renderer,bouton1,texture,plateau[0][5]);
      while (SDL_PollEvent(&event))
        {
          if(event.type==SDL_MOUSEBUTTONDOWN){
              //SDL_AfficherUnTexte
              if((x > cases[19][0].x && x<( cases[19][0].x +  cases[19][0].w) && y> cases[19][0].y && y < ( cases[19][0].y +  cases[19][0].h))){
                ville_t * ville=malloc(sizeof(ville_t));
                ville=crea_ville(cases,x,y);
                affiche_ville(cases[x][y],ville);
                /*etat de tout les boutons a 0 */
              }

              clean resources(texture ou renderer);//image bouton pour juste bandeau inferieur vierge
                //  clean bandeau_inferieur;
                break;
        }
    }
    break;

    case 3: // cas ou on click sur le batisseur
  /*  sdl_afficher_un_texte(info_batisseur,cases[19][10]);
    sdl_afficher_un_texte(info_ville,);
    sdl_afficher_un_texte(info_ville,);
*/
      while (SDL_PollEvent(&event))
        {
          if(event.type==SDL_MOUSEBUTTONDOWN){
              //SDL_AfficherUnTexte
              if((x > cases[19][0].x && x<( cases[19][0].x +  cases[19][0].w) && y> cases[19][0].y && y < ( cases[19][0].y +  cases[19][0].h))){
                crea_ferme(cases,x,y);
                /*etat de tout les boutons a 0 */
              }
              clean resources(texture ou renderer);//image bouton pour juste bandeau inferieur vierge
                //  clean bandeau_inferieur;
                break;
        }
    }
    break;
    case 4: // cas ou on click sur le guerrier
  /*  sdl_afficher_un_texte(info_batisseur,cases[19][10]);
    sdl_afficher_un_texte(info_ville,);
    sdl_afficher_un_texte(info_ville,);*/

      while (SDL_PollEvent(&event))
        {
          if(event.type==SDL_MOUSEBUTTONDOWN){
              //SDL_AfficherUnTexte
              if((x > cases[19][0].x && x<( cases[19][0].x +  cases[19][0].w) && y> cases[19][0].y && y < ( cases[19][0].y +  cases[19][0].h))){
                attaque(cases,x,y);// fonction avec clic pour savoir quel armée taper
                /*etat de tout les boutons a 0 */
              }

        }
    }
    break;
    case 5: // cas ou on click sur le arm_long
  /*  sdl_afficher_un_texte(info_batisseur,cases[19][10]);
    sdl_afficher_un_texte(info_ville,);
    sdl_afficher_un_texte(info_ville,);*/

      while (SDL_PollEvent(&event))
        {
          if(event.type==SDL_MOUSEBUTTONDOWN){
              //SDL_AfficherUnTexte
              if((x > cases[19][0].x && x<( cases[19][0].x +  cases[19][0].w) && y> cases[19][0].y && y < ( cases[19][0].y +  cases[19][0].h))){
                attaque(cases,x,y);// fonction avec clic pour savoir quel armée taper
                /*etat de tout les boutons a 0 */
              }
              clean resources(texture ou renderer);//image bouton pour juste bandeau inferieur vierge
                //  clean bandeau_inferieur;
                break;
        }
    }
    break;
    case 6: // cas ou on click sur le arm_spec
  /*  sdl_afficher_un_texte(info_batisseur,cases[19][10]);
    sdl_afficher_un_texte(info_ville,);
    sdl_afficher_un_texte(info_ville,);
*/
      while (SDL_PollEvent(&event))
        {
          if(event.type==SDL_MOUSEBUTTONDOWN){
              //SDL_AfficherUnTexte
              if((x > cases[19][0].x && x<( cases[19][0].x +  cases[19][0].w) && y> cases[19][0].y && y < ( cases[19][0].y +  cases[19][0].h))){
                attaque(cases,x,y);// fonction avec clic pour savoir quel armée taper
                /*etat de tout les boutons a 0 */
              }
              clean resources(texture ou renderer);//image bouton pour juste bandeau inferieur vierge
                //  clean bandeau_inferieur;
                break;
        }
    }
    break;

  }

}






 void jeu(int civilization) {

   SDL_Window* window = NULL;
   SDL_Renderer* renderer = NULL;

   Uint32 affich_fenetre=0;

   int liste_cases[N][N];
   SDL_Rect cases[N][N];

   int height = 1000;
   int width = 700;


   SDL_Rect passer_tour={LONGUEUR_CASE,0,LONGUEUR_CASE,LARGEUR_CASE};

      SDL_bool program_launched = SDL_TRUE;
      int ancien_click_x,ancien_click_y;

   for(int tour=1;program_launched;tour++){
       SDL_Event event;
       int ancien_click_x,ancien_click_y;

       crea_colon(cases,3,4);
     while (SDL_PollEvent(&event))
       {

           switch (event.type)
           {
           case SDL_QUIT:
               program_launched = SDL_FALSE;
               break;

           case SDL_MOUSEBUTTONDOWN: // Relâchement d'un clique
                x = event.button.x;  //récupération de la position de la souris
                y = event.button.y;
                printf("coord : x=%d, y=%d \n", x, y);
                numx = click_case_x(x);
                numy = click_case_y(y);
                printf("case : i=%d, j=%d \n", numx, numy);


                  if(numx==ville->x && numy==ville->y){
                      /* fonction bandeau_inferieur a modifier + action  */
                      fonction_bandeau_inferieur(cases,choix, renderer,texture);

                  }
                  if(numx==colon->x && numy==colon->y){

                      /*fonction bandeau_inferieur a modifier + action */
                      fonction_bandeau_inferieur(cases,choix, renderer,texture);

                  }
                  if(numx==batisseur->x && numy==batisseur->y){

                      /*fonction bandeau_inferieur a modifier + action */
                      fonction_bandeau_inferieur(cases,choix, renderer,texture);

                  }
                  if(numx==guerrier->x && numy==guerrier->y){

                      /* fonction bandeau_inferieur a modifier + action */
                      fonction_bandeau_inferieur(cases,choix, renderer,texture);

                  }
                  if(numx==arm_long->x && numy==arm_long->y){

                      /* fonction bandeau_inferieur a modifier +action */
                      fonction_bandeau_inferieur(cases,choix, renderer,texture);


                  }
                  if(numx==arm_spec->x && numy==arm_spec->y){

                      /* fonction bandeau_inferieur a modifier + action */
                      fonction_bandeau_inferieur(cases,choix, renderer,texture);


                  }




                /*
                    mouvements colon
                    if colon->etat_cons ==0
                    creation ville;*/
                    /*
                      clic case ville
                      clic choix bandeau inferieur
                       */


                    /*
                    if bouton_batisseur
                      tour +5
                      creation_batisseur;
                    if bouton_colon
                      tour +5
                      creation_colon;
                    if bouton_guerrier
                      tour +5
                      creation_guerrier;
                    if bouton_arm_long
                      tour +5
                      creation_arm_long;*/

                    /*  pareil pour les clics sur unités */







                    if((x > passer_tour.x && x<( passer_tour.x + passer_tour.w) && y> passer_tour.y && y < ( passer_tour.y +  passer_tour.h))){
                      break; //clic pour passer au tour suivant pas le choix



               else if (x > rectangle_quit.x && x<(rectangle_quit.x + rectangle_quit.w) && y>rectangle_quit.y && y < (rectangle_quit.y + rectangle_quit.h))
               {
                   printf("programme quitté");
                   program_launched = SDL_FALSE;
               }
               break;

           default:
               break;
           }
       }
   }



   SDL_DestroyRenderer(renderer);
   SDL_DestroyWindow(window);
   SDL_Quit();

   return EXIT_SUCCESS;




  /* while()
     creation premier colon
    crea_colon(plateau,x,y);
    while(colon->etat_cons!=0){
      mvt_colon;*/

      if((x > passer_tour.x && x<( passer_tour.x + passer_tour.w) && y> passer_tour.y && y < ( passer_tour.y +  passer_tour.h))){



    }

}
