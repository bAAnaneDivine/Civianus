#ifndef _COLON_H_
#define _COLON_H_

int i,j;
/*stats de civilization globale*/
typedef struct civilization_s{
  int civilization;
  int sciences_globale;
  int culture_globale;
  int nb_ferme;
  int nb_biblio;
  int bonus_sciences;
  int bonus_culture;
}civilization_t;



/* srtucture batisseur */
typedef struct batisseur_t{
  int x;
  int y;
  int nb_coup;
}batisseur_t;
/* structure colon */

typedef struct colon_t{
  int x;
  int y;
  int etat_cons;
}colon_t;

/* srtucture ville avec avantage */
typedef struct ville{
  int x;
  int y;
  int culture;
  int sciences;
  int niveau_ville;
  char*  nom_ville;
}ville_t;

/* structure guerrier classique */
typedef struct guerrier{
  int x;
  int y;
  int pdv;
  int att;
  int def;
}guerrier_t;

/* structure armée longue distance*/
typedef struct arm_long{
  int x;
  int y;
  int pdv;
  int att;
  int def;
}arm_long_t;
/* structure armée specifique */
typedef struct arm_spec{
  int x;
  int y;
  int pdv;
  int att;
  int def;
}arm_spec_t;

/*
 *fonction pour la civilization globale
 *
 */








/*
 *fonction pour le colon
 *
 */
int est_libre(int biome[i][j]);
void supp_image_colon(SDL_Rect plateau[i][j],SDL_Renderer *renderer,SDL_Texture * texture);
colon_t * crea_colon(int i,int j);
void mvt_colon(SDL_Rect plateau[i][j],colon_t * colon,int x,int y);
void affiche_colon(SDL_Rect plateau[LONGUEUR_CASE][LARGEUR_CASE],SDL_Renderer *renderer,colon_t * colon);



/*
  *
  * fonction pour la ville
  *
*/
void affiche_ville(SDL_Rect plateau[LONGUEUR_CASE][LARGEUR_CASE],ville_t *ville,SDL_Renderer *renderer);
ville_t * crea_ville(int i,int j);

/*
  *
  * fonction pour le batisseur
  *
*/

void supp_image_batisseur(SDL_Rect plateau[i][j],SDL_Renderer *renderer,SDL_Texture * texture);
void affiche_batisseur(SDL_Rect plateau[LONGUEUR_CASE][LARGEUR_CASE],SDL_Renderer *renderer,batisseur_t * batisseur);
batisseur_t * crea_batisseur(int i,int j);
void mvt_batisseur(SDL_Rect plateau[i][j],batisseur_t* batisseur,int x,int y);

/*
  *
  * fonction pour le guerrier
  *
*/

void supp_image_guerrier(SDL_Rect plateau[i][j],SDL_Renderer *renderer,SDL_Texture * texture);
void affiche_guerrier(SDL_Rect plateau[LONGUEUR_CASE][LARGEUR_CASE],SDL_Renderer *renderer,guerrier_t* guerrier);
guerrier_t * crea_guerrier(int i,int j);
void mvt_guerrier(SDL_Rect plateau[i][j],guerrier_t * guerrier,int x,int y);

/*
  *
  * fonction pour le arm_long
  *
*/
void supp_image_arm_long(SDL_Rect plateau[i][j],SDL_Renderer *renderer,SDL_Texture * texture);
void affiche_arm_long(SDL_Rect plateau[LONGUEUR_CASE][LARGEUR_CASE],SDL_Renderer *renderer,arm_long_t* arm_long);
arm_long_t * crea_arm_long(int i,int j);
void mvt_arm_long(SDL_Rect plateau[i][j],arm_long_t * arm_long,int x,int y);

/*
  *
  * fonction pour le arm_spec
  *
*/
void supp_image_arm_spec(SDL_Rect plateau[i][j],SDL_Renderer *renderer,SDL_Texture * texture);
void affiche_arm_spec(SDL_Rect plateau[LONGUEUR_CASE][LARGEUR_CASE],SDL_Renderer *renderer,arm_spec_t* arm_spec);
arm_spec_t * crea_arm_spec(int i,int j);
void mvt_arm_spec(SDL_Rect plateau[i][j],arm_spec_t * arm_spec,int x,int y);



int click_case_x(int i);
int click_case_y(int j);

#endif
