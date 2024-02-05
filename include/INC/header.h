#ifndef HEADER__H
#define HEADER__H
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <stdio.h>
#include <math.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define TILE_SIZE 24
#define MAP_WIDTH 12
#define MAP_HEIGHT 12
#define PI 3.1415926535897

int handleEvent(int map[MAP_HEIGHT][MAP_WIDTH],  SDL_Point *player);
void renderMap(SDL_Renderer *renderer, int map[MAP_HEIGHT][MAP_WIDTH]);
void renderMapTexture(SDL_Renderer *renderer, int map[MAP_HEIGHT][MAP_WIDTH], SDL_Texture* wallTexture);
void renderPlayer(SDL_Renderer *renderer, int playerX, int playerY);
void renderPlayerTexture(SDL_Renderer *renderer, SDL_Texture *playerTexture, int playerX, int playerY);
void renderPlayerWithAngle(SDL_Renderer *renderer, int playerX, int playerY, SDL_Point point);
int handleEventWithAngle(int map[MAP_HEIGHT][MAP_WIDTH], SDL_Point *player, float *playerAngle, SDL_Point *point);
SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* path);
SDL_Renderer* initializeSDL();
#endif