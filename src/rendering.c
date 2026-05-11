#include "./rendering.h"
#include "./game.h"
#include "./logic.h"

void render_grid(SDL_Renderer *renderer, int x, int y) {
  SDL_SetRenderDrawColor(renderer, 0xCC, 0xCC, 0xCC, 255);
  SDL_Rect cell;
  cell.w = CELL_SIZE;
  cell.h = CELL_SIZE;
  for (int i = 0; i < WINDOW_WIDTH; i++) {
    for (int j = 0; j < WINDOW_HEIGHT; j++) {
      cell.x = x + (i * CELL_SIZE);
      cell.y = y + (j * CELL_SIZE);
      SDL_RenderDrawRect(renderer, &cell);
    }
  }
}

void render_sarpa(SDL_Renderer *renderer, int x, int y) {
  SDL_SetRenderDrawColor(renderer, 0x45, 0xFE, 0x02, 255);
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
  SDL_SetRenderDrawColor(renderer, 0xFA, 0x4E, 0x58, 255);
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
