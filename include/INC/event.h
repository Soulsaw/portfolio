#ifndef EVENT__H
#define EVENT__H
#include "INC/header.h"
int handleEvent(SDL_Point *player);
int handleEventWithAngle(SDL_Point *player, float *playerAngle, SDL_Point *playerDirection);
#endif