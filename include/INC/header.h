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

SDL_Renderer* initializeSDL();
#endif