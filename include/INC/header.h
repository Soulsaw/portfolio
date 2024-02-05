#ifndef HEADER__H
#define HEADER__H
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <stdio.h>
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define TILE_SIZE 12
#define MAP_WIDTH 12
#define MAP_HEIGHT 12

int initInstance(SDL_Instance *);
int SDL_ExitWithError(const char *message);
int handleEvent(int map[MAP_HEIGHT][MAP_WIDTH],  SDL_Point *player);
void drawMap2D(SDL_Renderer *);
void renderMap(SDL_Renderer *renderer, int map[MAP_HEIGHT][MAP_WIDTH], SDL_Texture* wallTexture);
void renderPlayer(SDL_Renderer *renderer, SDL_Texture *playerTexture, int playerX, int playerY);
SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* path);
SDL_Renderer* initializeSDL();
#endif