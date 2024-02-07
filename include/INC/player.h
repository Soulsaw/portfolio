#ifndef PLAYER__H
#define PLAYER__H
#include "INC/header.h"
void renderPlayer(SDL_Renderer *renderer, int playerX, int playerY);
void renderPlayerTexture(SDL_Renderer *renderer, SDL_Texture *playerTexture, int playerX, int playerY);
void renderPlayerWithAngle(SDL_Renderer *renderer, int playerX, int playerY, SDL_Point playerDirection);
float dist(float ax, float ay, float bx, float by, float angle);
#endif