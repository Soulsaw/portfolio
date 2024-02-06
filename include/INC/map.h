#ifndef MAP__H
#define MAP__H
#include "INC/header.h"
void renderMap(SDL_Renderer *renderer, int map[MAP_HEIGHT][MAP_WIDTH]);
void renderMapTexture(SDL_Renderer *renderer, int map[MAP_HEIGHT][MAP_WIDTH],
                      SDL_Texture *wallTexture, SDL_Texture *floorTexture);
#endif