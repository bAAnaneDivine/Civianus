/*
* boutons ville et informations
*/
SDL_Rect rectangle_colon; //choix_ville creation colon
SDL_Rect rectangle_batisseur; //choix_ville creation batisseur
SDL_Rect rectangle_guerrier;//choix_ville creation guerrier
SDL_Rect rectangle_arm_long;//choix_ville creation armée_longue
SDL_Rect rectangle_arm_spec;//choix_ville creation armée_specifique
SDL_Rect rectangle_culture;//choix_ville informations culture
SDL_Rect rectangle_sciences;//choix_ville informations sciences
SDL_Rect rectangle_nom_ville;//choix_ville informations nom_ville
SDL_Rect rectangle_niveau_ville;//choix_ville informations niveau_ville

/*
* boutons colon
*/
SDL_Rect creer_ville;//choix colon creation ville
/*
* boutons batisseur
*/
SDL_Rect creer_ferme;//choix batisseur creation ferme
SDL_Rect nbr_coup_rest;//choix batisseur nombre de construction restantes
/*
* boutons guerrier
*/
SDL_Rect attaque_guerrier;//choix guerrier attaque
SDL_Rect pdv;//informations points de vie restants
SDL_Rect attaque;//informations points d'attaque
SDL_Rect defense;//informations points de defense
/*
* boutons arm_long
*/
SDL_Rect attaque_arm_long;//choix arm_long attaque
SDL_Rect pdv;//informations points de vie restants
SDL_Rect attaque;//informations points d'attaque
SDL_Rect defense;//informations points de defense
/*
* boutons arm_spec
*/
SDL_Rect attaque_arm_spec;//choix arm_spec attaque
SDL_Rect pdv;//informations points de vie restants
SDL_Rect attaque;//informations points d'attaque
SDL_Rect defense;//informations points de defense









void *  fonction_bandeau_superieur(SDL_Rect cases[N][N],int choix, SDL_Renderer *renderer){

  SDL_Event event;

      SDL_Rect rectangle_colon={LONGUEUR_CASE*4,0,LONGUEUR_CASE,LARGEUR_CASE}; //choix_ville creation colon
      SDL_Rect rectangle_batisseur={LONGUEUR_CASE*5,0,LONGUEUR_CASE,LARGEUR_CASE}; //choix_ville creation batisseur
      SDL_Rect rectangle_guerrier={LONGUEUR_CASE*6,0,LONGUEUR_CASE,LARGEUR_CASE}; //choix_ville creation guerrier
      SDL_Rect rectangle_arm_long={LONGUEUR_CASE*7,0,LONGUEUR_CASE,LARGEUR_CASE}; //choix_ville creation armée_longue
      SDL_Rect rectangle_arm_spec={LONGUEUR_CASE*8,0,LONGUEUR_CASE,LARGEUR_CASE}; //choix_ville creation armée_specifique

      SDL_Rect rectangle_culture={LONGUEUR_CASE*9,0,LONGUEUR_CASE,LARGEUR_CASE}; // informations culture
      SDL_Rect rectangle_sciences={LONGUEUR_CASE*10,0,LONGUEUR_CASE,LARGEUR_CASE}; //informations sciences
      SDL_Rect rectangle_nom_ville={LONGUEUR_CASE*11,0,LONGUEUR_CASE,LARGEUR_CASE}; //informations nom_ville
      SDL_Rect rectangle_niveau_ville={LONGUEUR_CASE*12,0,LONGUEUR_CASE,LARGEUR_CASE}; //informations niveau_ville


      SDL_Rect rectangle_crea_ville={LONGUEUR_CASE*9,0,LONGUEUR_CASE,LARGEUR_CASE};
  switch (choix) {
    case 1: // cas ou on click sur la ville


        /*
        afficher_texte(ttf* fond, SDL_Rect rectangle_culture,SDL_Renderer * renderer, TTF_Font* font, char* text, SDL_Color* color);
        afficher_texte(ttf* fond, SDL_Rect rectangle_sciences,SDL_Renderer * renderer, TTF_Font* font, char* text, SDL_Color* color);
        afficher_texte(ttf* fond, SDL_Rect rectangle_nom_ville,SDL_Renderer * renderer, TTF_Font* font, char* text, SDL_Color* color);
        afficher_texte(ttf* fond, SDL_Rect rectangle_niveau_ville,SDL_Renderer * renderer, TTF_Font* font, char* text, SDL_Color* color);

        */
            while (SDL_PollEvent(&event)) {

                if(event.type==SDL_MOUSEBUTTONDOWN){

                    int x=event.button.x;
                    int y=event.button.y;
                    if((x > rectangle_colon.x && x<( rectangle_colon.x +  rectangle_colon.w) && y> rectangle_colon.y && y < ( rectangle_colon.y +  rectangle_colon.h))){
                      crea_colon(cases,x,y);
                    }
                    if((x >  rectangle_batisseur.x && x<(rectangle_batisseur.x +  rectangle_batisseur.w) && y> rectangle_batisseur.y && y < ( rectangle_batisseur.y +  rectangle_batisseur.h))){
                      crea_batisseur(cases,x,y);
                    }
                    if((x > rectangle_guerrier.x && x<(rectangle_guerrier.x + rectangle_guerrier.w) && y>rectangle_guerrier.y && y < (rectangle_guerrier.y + rectangle_guerrier.h))){
                      crea_guerrier(cases,x,y);
                    }
                    if( (x > rectangle_arm_long.x && x<(rectangle_arm_long.x + rectangle_arm_long.w) && y>rectangle_arm_long.y && y < (rectangle_arm_long.y + rectangle_arm_long.h) ) ) {
                      crea_arm_long(cases,x,y);
                    }
                    if((x > rectangle_arm_spec.x && x<(rectangle_arm_spec.x + rectangle_arm_spec.w) && y>rectangle_arm_spec.y && y < (rectangle_arm_spec.y + rectangle_arm_spec.h))){
                      crea_arm_spec(cases,x,y);
                    }
                    clean_ressources(NULL,NULL,NULL);//image bouton pour juste bandeau superieur vierge
                      //  clean bandeau_inferieur;

              }
            break;
          }
          break;
  case 2: // cas ou on click sur le colon

      /*
      afficher_texte(ttf* fond, SDL_Rect rectangle_culture,SDL_Renderer * renderer, TTF_Font* font, char* text, SDL_Color* color);
      */

    while (SDL_PollEvent(&event))
      {

        if(event.type==SDL_MOUSEBUTTONDOWN){

              int x=event.button.x;
              int y=event.button.y;
              if((x > cases[19][0].x && x<( cases[19][0].x +  cases[19][0].w) && y> cases[19][0].y && y < ( cases[19][0].y +  cases[19][0].h))){
              ville_t * ville=malloc(sizeof(ville_t));
              ville=crea_ville(x,y);
              affiche_ville(cases,ville,renderer);

              /*etat de tout les boutons a 0 */
            }

            clean_ressources(NULL,NULL,NULL);//image bouton pour juste bandeau superieur vierge
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

            int x=event.button.x;
            int y=event.button.y;
            if((x > cases[19][0].x && x<( cases[19][0].x +  cases[19][0].w) && y> cases[19][0].y && y < ( cases[19][0].y +  cases[19][0].h))){
            //  crea_ferme(cases,x,y);
              /*etat de tout les boutons a 0 */
            }
            clean_ressources(NULL,NULL,NULL);//image bouton pour juste bandeau superieur vierge
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

            int x=event.button.x;
            int y=event.button.y;
            if((x > cases[19][0].x && x<( cases[19][0].x +  cases[19][0].w) && y> cases[19][0].y && y < ( cases[19][0].y +  cases[19][0].h))){
            //  attaque(cases,x,y);// fonction avec clic pour savoir quel armée taper
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

            int x=event.button.x;

            int y=event.button.y;
            if((x > cases[19][0].x && x<( cases[19][0].x +  cases[19][0].w) && y> cases[19][0].y && y < ( cases[19][0].y +  cases[19][0].h))){
          //    attaque(cases,x,y);// fonction avec clic pour savoir quel armée taper
              /*etat de tout les boutons a 0 */
            }
            clean_ressources(NULL,NULL,NULL);//image bouton pour juste bandeau superieur vierge
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
            int x=event.button.x;
            int y=event.button.y;
            if((x > cases[19][0].x && x<( cases[19][0].x +  cases[19][0].w) && y> cases[19][0].y && y < ( cases[19][0].y +  cases[19][0].h))){
            //  attaque(cases,x,y);// fonction avec clic pour savoir quel armée taper
              /*etat de tout les boutons a 0 */
            }
            clean_ressources(NULL,NULL,NULL);//image bouton pour juste bandeau superieur vierge
              //  clean bandeau_inferieur;
              break;
      }
  }
  break;

}
return((0)); //return de la strcture
}
