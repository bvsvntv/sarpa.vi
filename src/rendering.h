#ifndef RENDERING_H_
#define RENDERING_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

void render_sarpa(SDL_Renderer *renderer, int x, int y);
void render_food(SDL_Renderer *renderer, int x, int y);
void render_grid(SDL_Renderer * renderer, int x, int y);
void render_score(SDL_Renderer * renderer, TTF_Font *font, int score);

#endif
