#ifndef HEADER__H
#define HEADER__H
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <stdio.h>
#include <math.h>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 512
#define TILE_SIZE 64
#define MAP_WIDTH 8
#define MAP_HEIGHT 8
#define PI 3.1415926535/* PI value */
#define P2 PI / 2
#define P3 3 * PI / 2
#define DR 0.0174533/* One degree in radians */

SDL_Renderer *initializeSDL();
#endif