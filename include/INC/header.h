#ifndef HEADER__H
#define HEADER__H
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <stdio.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define TILE_SIZE 45
#define MAP_WIDTH 12
#define MAP_HEIGHT 12
/**
 * struct SDL_Instance - The instance of the SDL
 * @window: The window to create
 * @renderer: The renderer for the draw
 *
*/
typedef struct SDL_Instance
{
SDL_Window *window;
SDL_Renderer *renderer;
} SDL_Instance;

int initInstance(SDL_Instance *);
int SDL_ExitWithError(const char *message);
int handleEvent(int map[MAP_HEIGHT][MAP_WIDTH],  SDL_Point *player);
void drawMap2D(SDL_Renderer *);
void renderMap(SDL_Renderer *renderer, int map[MAP_HEIGHT][MAP_WIDTH], SDL_Texture* wallTexture);
void renderPlayer(SDL_Renderer *renderer, SDL_Texture *playerTexture, int playerX, int playerY);
SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* path);
SDL_Renderer* initializeSDL();
#endif