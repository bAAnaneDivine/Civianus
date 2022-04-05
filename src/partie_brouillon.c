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



SDL_Event event;

while (SDL_PollEvent(&event))
{


switch (choix) {
  case 1: // cas ou on click sur la ville
        // case 0
          rectangle_colon.x = 0;
          rectangle_colon.y = width-LARGEUR_CASE;
          rectangle_colon.w = LARGEUR_CASE;
          rectangle_colon.h = LONGUEUR_CASE;
          SDL_AfficherUneImage
      // case 1
          rectangle_batisseur.x = LONGUEUR_CASE;
          rectangle_batisseur.y = width-LARGEUR_CASE;
          rectangle_batisseur.w = LARGEUR_CASE;
          rectangle_batisseur.h = LONGUEUR_CASE;
          SDL_AfficherUneImage
      // case 2
          rectangle_guerrier.x = LONGUEUR_CASE*2 ;
          rectangle_guerrier.y = width-LARGEUR_CASE;
          rectangle_guerrier.w = LARGEUR_CASE;
          rectangle_guerrier.h = LONGUEUR_CASE;
          SDL_AfficherUneImage
      // case 3
          rectangle_arm_long.x = LONGUEUR_CASE*3;
          rectangle_arm_long.y = width-LARGEUR_CASE;
          rectangle_arm_long.w = LARGEUR_CASE;
          rectangle_arm_long.h = LONGUEUR_CASE;
          SDL_AfficherUneImage
      // case 4
          rectangle_arm_spec.x = LONGUEUR_CASE*4;
          rectangle_arm_spec.y = width-LARGEUR_CASE;
          rectangle_arm_spec.w = LARGEUR_CASE;
          rectangle_arm_spec.h = LONGUEUR_CASE;
          SDL_AfficherUneImage
      // case 5 et 6
          rectangle_culture.x = LONGUEUR_CASE*5;
          rectangle_culture.y = width-LARGEUR_CASE;
          rectangle_culture.w = LARGEUR_CASE;
          rectangle_culture.h = LONGUEUR_CASE*2;
          SDL_AfficherUnTexte
      // case 7 et 8
          rectangle_sciences.x = LONGUEUR_CASE*5;
          rectangle_sciences.y = width-LARGEUR_CASE;
          rectangle_sciences.w = LARGEUR_CASE;
          rectangle_sciences.h = LONGUEUR_CASE*2;
          SDL_AfficherUnTexte
      // case 9 et 10
          rectangle_nom_ville.x = LONGUEUR_CASE*5;
          rectangle_nom_ville.y = width-LARGEUR_CASE;
          rectangle_nom_ville.w = LARGEUR_CASE;
          rectangle_nom_ville.h = LONGUEUR_CASE*2;
          SDL_AfficherUnTexte
      // case 11 et 12
          rectangle_niveau_ville.x = LONGUEUR_CASE*5;
          rectangle_niveau_ville.y = width-LARGEUR_CASE;
          rectangle_niveau_ville.w = LARGEUR_CASE;
          rectangle_niveau_ville.h = LONGUEUR_CASE*2;
