#ifndef PLAYER__H
#define PLAYER__H
#include "../headers/header.h"
void renderPlayer(SDL_Renderer *renderer, int playerX, int playerY);
void renderPlayerWithAngle(SDL_Renderer *renderer, int playerX,
int playerY, SDL_Point playerDirection);
float dist(float ax, float ay, float bx, float by);
#endif
