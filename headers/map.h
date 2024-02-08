#ifndef MAP__H
#define MAP__H
#include "../headers/header.h"
void renderMap(SDL_Renderer *renderer, int map[TILE_SIZE]);
void drawRays2d(SDL_Renderer *renderer, float playerAngle,
SDL_Point player, int map[]);
void drawFloorAndSky(SDL_Renderer *renderer);
float moveAngle(float pa);
/* Horizontal Walls check */
void playerLookingUp(SDL_Point player, float *rx, float *ry,
float *xo, float *yo, float ra, float aTan);
void playerLookingDown(SDL_Point player, float *rx, float *ry,
float *xo, float *yo, float ra, float aTan);
void lookingStraigth(SDL_Point player, float ra, float *rx,
float *ry, int *dof);
/* Vertical Walls checks */
void playerLookingLeft(SDL_Point player, float *rx, float *ry,
float *xo, float *yo, float ra, float nTan);
void playerLookingRigth(SDL_Point player, float *rx, float *ry,
float *xo, float *yo, float ra, float nTan);

void coolisionWithWall(SDL_Point player, int map[], float *rx, float *ry,
float *xo, float *yo, int *dof, float *dis, float *x, float *y);
#endif
