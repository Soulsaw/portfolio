#ifndef MAP__H
#define MAP__H
#include "../headers/header.h"
void renderMap(SDL_Renderer *renderer, int map[TILE_SIZE]);
void renderMapTexture(SDL_Renderer *renderer, int map[TILE_SIZE],
SDL_Texture *wallTexture, SDL_Texture *floorTexture);
void drawRays2d(SDL_Renderer *renderer, float playerAngle,
SDL_Point player, int map[]);
#endif
