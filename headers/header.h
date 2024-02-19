#ifndef HEADER__H
#define HEADER__H
#include "SDL2/SDL.h"
#include <stdio.h>
#include <math.h>

#define SCREEN_WIDTH 1126
#define SCREEN_HEIGHT 700
#define TILE_SIZE 16
#define MAP_SIZE 96
#define MAP_WIDTH 12
#define MAP_HEIGHT 8
#define PI 3.1415926535/* PI value */
#define P2 (PI / 2)
#define P3 (3 * (PI / 2))
#define DR 0.0174533/* One degree in radians */
#define PA 0.00092999

SDL_Renderer *initializeSDL();
void drawThickLine(SDL_Renderer *renderer, int x1, int y1, int x2,
				   int y2, int width);
#endif
