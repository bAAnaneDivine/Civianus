#ifndef _JEU_H_
#define _JEU_H_

void afficher_personnage(SDL_Window* window, SDL_Renderer* renderer, SDL_Rect rectangle_pers);
void deplacer(SDL_Event event, SDL_Rect* rectangle_pers);

#endif