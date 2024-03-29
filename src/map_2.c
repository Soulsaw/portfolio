#include "../headers/map.h"
#include "../headers/player.h"
/**
 * playerLookingUp - This function permit to get the distance
 * between player and wall if he looking Left
 * @player: The player current position
 * @rx: The rayon x
 * @ry: The rayon y
 * @xo: The xo
 * @yo: The yo
 * @ra: The rayon angle
 * @nTan: The tan of the angle
 * Return: Nothing
*/
void playerLookingLeft(SDL_Point player, float *rx, float *ry,
float *xo, float *yo, float ra, float nTan)
{
	if (ra > P2 && ra < P3)
	{
		*rx = (int)(player.x / TILE_SIZE) * TILE_SIZE - 1;
		*ry = (player.x - *rx) * nTan + player.y;
		*xo = -TILE_SIZE;
		*yo = -(*xo) * nTan;
	}
}
/**
 * playerLookingUp - This function permit to get the distance
 * between player and wall if he looking Down
 * @player: The player current position
 * @rx: The rayon x
 * @ry: The rayon y
 * @xo: The xo
 * @yo: The yo
 * @ra: The rayon angle
 * @nTan: The tan of the angle
 * Return: Nothing
*/
void playerLookingRigth(SDL_Point player, float *rx, float *ry,
float *xo, float *yo, float ra, float nTan)
{
	if (ra < P2 || ra > P3)
	{
		*rx = (int)(player.x / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
		*ry = (player.x - *rx) * nTan + player.y;
		*xo = TILE_SIZE;
		*yo = -(*xo) * nTan;
	}
}
/**
 * playerLookingUp - This function permit to get the distance
 * between player and wall if he looking Down
 * @player: The player current position
 * @map: The player map
 * @rx: The rayon x
 * @ry: The rayon y
 * @xo: The xo
 * @yo: The yo
 * @dof: The rayon angle
 * @dis: Distance between the player and the Vertical or Horizontal Wall
 * @x: The tan of the angle
 * @y: The tan of the angle
 * Return: Nothing
*/
void coolisionWithWall(SDL_Point player, int map[], float *rx, float *ry,
float *xo, float *yo, int *dof, float *dis, float *x, float *y)
{
	int mx, my, mp;

	while (*dof < MAP_WIDTH)
	{
		mx = (int)(*rx / TILE_SIZE);
		my = (int)(*ry  / TILE_SIZE);
		mp = my * MAP_WIDTH + mx;
		if (mp > 0 && mp < MAP_SIZE && map[mp] == 1)
		{
			*x = *rx;
			*y = *ry;
			*dis = dist(player.x, player.y, *x, *y);
			*dof = MAP_WIDTH;
		}
		else
		{
			*rx += *xo;
			*ry += *yo;
			*dof += 1;
		}
	}
}
/**
 * playerLookingUp - This function permit to get the distance
 * between player and wall if he looking Down
 * @disT: The rayon x
 * @disV: The rayon y
 * @disH: The xo
 * @rx: The yo
 * @ry: The rayon angle
 * @hx: Distance between the player and the Vertical or Horizontal Wall
 * @hy: The tan of the angle
 * @vx: The tan of the angle
 * @vy: The tan of the angle
 * Return: Nothing
*/
void cutRayLength(int *disT, float disV, float disH, float *rx, float *ry,
float hx, float hy, float vx, float vy)
{
	if (disV < disH)
	{
		*rx = vx;
		*ry = vy;
		*disT = disV;
	}
	if (disH < disV)
	{
		*rx = hx;
		*ry = hy;
		*disT = disH;
	}
}
/**
 * draw3dWalls - This funtion permit to draw a 3d renderer
 * @renderer: The renderer to draw the 3d Walls
 * @pa: The player angle
 * @disT: The horizontal or the vertical distance with the walls
 * @r: The n^th ray to draw
 * @ra: The rayon angle
 * Return: Nothing
*/
void draw3dWalls(SDL_Renderer *renderer, float pa, int *disT,
int r, float ra)
{
	float ca = pa - ra + ra;

	ca = moveAngle(ca);
	*disT = (*disT) * cos(ca);/* fix fisheye */
	float heigth = (float)SCREEN_WIDTH;
	float plan = ceil(heigth / (2 * 0.57735));/* tan(30) = 0,57735 */
	float lineH = ceil(((float)TILE_SIZE / *disT) * plan);

	float lineO = (float)(SCREEN_HEIGHT / 2) - lineH / 2;/* Line offsets */

	if (SDL_SetRenderDrawColor(renderer, 113, 113, 113, 255) != 0)
	{
		fprintf(stderr, "Error: SDL_SetRenderDrawColor > %s\n",
		SDL_GetError());
		exit(1);
	}
	drawThickLine(renderer, r, lineO, r, lineH + lineO, 1);
	if (SDL_SetRenderDrawColor(renderer, 33, 171, 74, 255) != 0)
	{
		fprintf(stderr, "Error: SDL_SetRenderDrawColor > %s\n", SDL_GetError());
		exit(1);
	}
}
