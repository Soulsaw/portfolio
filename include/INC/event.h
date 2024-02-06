#ifndef EVENT__H
#define EVENT__H
#include "INC/header.h"
int handleEvent(int map[MAP_HEIGHT][MAP_WIDTH],  SDL_Point *player);
int handleEventWithAngle(int map[MAP_HEIGHT][MAP_WIDTH], SDL_Point *player, float *playerAngle, SDL_Point *point);
#endif