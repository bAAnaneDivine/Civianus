/*gcc -c texte.c -o bin/texte -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -mwindows*/

#include <stdio.h>
#include <stdlib.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>


int main(int argc, char* argv[])
{
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    TTF_Font* font= NULL;
    SDL_Surface* text = NULL;
    SDL_Texture* txt = NULL;
    SDL_Color blackColor = { 0, 0, 0 };

    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    window = SDL_CreateWindow("test texte", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800,400,0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    font = TTF_OpenFont("polices/04B_30__.TTF", 12);
    text=TTF_RenderText_Blended(font,"Hello",blackColor);
    txt=SDL_CreateTextureFromSurface(renderer,text);
    SDL_FreeSurface(text);

    SDL_Rect dest_coo;
    dest_coo.x=40;
    dest_coo.y=40;
    dest_coo.w=text->w;
    dest_coo.h=text->h;

    SDL_RenderCopy(renderer,txt,NULL,&dest_coo);
    SDL_RenderPresent(renderer);

    SDL_Delay(5000);


    SDL_DestroyTexture(txt);
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return EXIT_SUCCESS;

}
/*
void afficher_texte(SDL_Renderer* renderer, TTF_font* font, SDL_Color color, SDL_Rect rect, char texte)
{
  SDL_Surface* s_texte = NULL;
  SDL_Texture* t_texte = NULL;

  TTF_Init();
  s_texte=TTF_RenderText_Blended(font,texte,color);
  t_texte=SDL_CreateTextureFromSurface(renderer,s_texte);
  SDL_FreeSurface(s_texte);

  SDL_RenderCopy(renderer,t_texte,NULL,&rect);
  SDL_RenderPresent(renderer);

  SDL_DestroyTexture(txt);
  TTF_CloseFont(font);
  TTF_Quit();
}
*/
