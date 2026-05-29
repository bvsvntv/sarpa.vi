#include "./rendering.h"
#include "./game.h"
#include "./logic.h"

const SDL_Color COLOR_RED = {.r = 0xFA, .g = 0x4E, .b = 0x58, .a = 255};
const SDL_Color COLOR_GREEN = {.r = 0x45, .g = 0xFE, .b = 0x02, .a = 255};

void render_sarpa(SDL_Renderer *renderer, int x, int y) {
  SDL_SetRenderDrawColor(renderer, COLOR_GREEN.r, COLOR_GREEN.g, COLOR_GREEN.b,
                         COLOR_GREEN.a);
  SDL_Rect segment;
  segment.w = CELL_SIZE * 0.85;
  segment.h = CELL_SIZE * 0.85;
  Sarpa *current = head;
  while (current != NULL) {
    segment.x = x + current->x;
    segment.y = y + current->y;
    SDL_RenderFillRect(renderer, &segment);
    current = current->next;
  }
}

void render_food(SDL_Renderer *renderer, int x, int y) {
  SDL_SetRenderDrawColor(renderer, COLOR_RED.r, COLOR_RED.g, COLOR_RED.b,
                         COLOR_RED.a);
  SDL_Rect foodRect;
  foodRect.w = CELL_SIZE * 0.85;
  foodRect.h = CELL_SIZE * 0.85;
  foodRect.x = x + food.x * CELL_SIZE;
  foodRect.y = y + food.y * CELL_SIZE;
  SDL_RenderFillRect(renderer, &foodRect);
}

void render_score(SDL_Renderer *renderer, TTF_Font *font, int score) {
  char text[48];
  snprintf(text, sizeof(text), "score:%d", score);

  SDL_Color textColor = {0x45, 0xFE, 0x02, 255};

  SDL_Surface *textSurface = TTF_RenderText_Solid(font, text, textColor);

  if (!textSurface) {
    fprintf(stderr, "Could not create text surface: %s\n", TTF_GetError());
    return;
  }

  SDL_Texture *textTexture =
      SDL_CreateTextureFromSurface(renderer, textSurface);

  if (!textTexture) {
    fprintf(stderr, "Could not create text texture: %s\n", SDL_GetError());
    SDL_FreeSurface(textSurface);
    return;
  }

  SDL_Rect textRect = {WINDOW_WIDTH - textSurface->w - 10,
                       WINDOW_HEIGHT - textSurface->h - 10, textSurface->w,
                       textSurface->h};

  SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

  SDL_DestroyTexture(textTexture);
  SDL_FreeSurface(textSurface);
}
