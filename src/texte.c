#include "headers/texte.h"

SDL_Texture* Creation_Text(SDL_Renderer *renderer,SDL_Rect *tailText,const char *police,const int tailPolice,const int style,const char *texte,const SDL_Color couleur,const int position_x,const int position_y ){
	TTF_Font* font=NULL;
	SDL_Texture * texte_tex =NULL;
	SDL_Surface * ecrire=NULL;
	font=TTF_OpenFont ( police,tailPolice);
	if ( font == NULL ){
		fprintf ( stderr , " erreur chargement font: %s \n ",TTF_GetError() );
		return texte_tex;
	}
	TTF_SetFontStyle(font,style);
	ecrire =TTF_RenderUTF8_Blended( font , texte ,couleur );
	texte_tex = SDL_CreateTextureFromSurface( renderer , ecrire );
	tailText->x=position_x;
	tailText->y=position_y;
	SDL_QueryTexture( texte_tex , NULL , NULL , &tailText->w , &tailText->h);
	SDL_FreeSurface( ecrire);
	TTF_CloseFont(font);
	return texte_tex;
}
// bouton3->Table[0]->t =Creation_Text(renderer,lire_Rect(bouton3->Table[0],1),"image/police/Takenoko.TTF",Width/48,TTF_STYLE_BOLD,"Quiter",Bleu,(Width/4)+(Height*2/18),(Height*5/8)+(Height*2/18));
