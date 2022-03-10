#ifndef _ADMIN_SDL_H_
#define _ADMIN_SDL_H_

void SDL_ExitWithError(const char* message);
void SDL_initialisation();
SDL_Texture* createText(SDL_Renderer* renderer, TTF_Font* font, char text[], SDL_Color* color)

#endif