#include "../headers/map.h"
#include "../headers/player.h"
/**
 * renderMap - This function draw a map using the RGBA color
 * to fill the rectangle
 * @renderer: The renderer to draw the map on
 * \param renderer The renderer to draw the map on
 * @map: The map the Matrix of `X` column and `Y` row
 * \param map The map the Matrix of `X` column and `Y` row
 * Return: Nothing
 * \returns Nothing
 */
void renderMap(SDL_Renderer *renderer, int map[])
{
	int x, y;

	for (y = 0; y < MAP_HEIGHT; ++y)
	{
		for (x = 0; x < MAP_WIDTH; ++x)
		{
			if (map[y * MAP_WIDTH + x] == 1)
			{
				SDL_SetRenderDrawColor(renderer, 0XFF, 0XFF, 0XFF,
				255);
				SDL_Rect wallRect = {x * TILE_SIZE + 1, y * TILE_SIZE + 1,
				TILE_SIZE - 1, TILE_SIZE - 1};
				SDL_RenderFillRect(renderer, &wallRect);
			}
		}
	}
}
/**
 * moveAngle - This function permit to move the rayon angle
 * @ra: The player angle
 * \param ra The player angle
 * Return: The new rayon angle of the player view
 * \returns The new player view rayon
*/
float moveAngle(float ra)
{
	if (ra < 0)
	{
		ra += 2 * PI;
	}
	if (ra > 2 * PI)
	{
		ra -= 2 * PI;
	}
	return (ra);
}
/**
 * playerLookingUp - This function permit to get the distance
 * between player and wall if he looking Up
 * @player: The player current position
 * @rx: The rayon x
 * @ry: The rayon y
 * @xo: The xo
 * @yo: The yo
 * @ra: The rayon angle
 * @aTan: The tan of the angle
 * Return: Nothing
*/
void playerLookingUp(SDL_Point player, float *rx, float *ry,
float *xo, float *yo, float ra, float aTan)
{
	if (ra > PI)
	{
		*ry = (int)(player.y / TILE_SIZE) * TILE_SIZE - 1;
		*rx = (player.y - *ry) * aTan + player.x;
		*yo = -TILE_SIZE;
		*xo = -(*yo) * aTan;
	} /* Looking up */
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
 * @aTan: The tan of the angle
 * Return: Nothing
*/
void playerLookingDown(SDL_Point player, float *rx, float *ry,
float *xo, float *yo, float ra, float aTan)
{
	if (ra < PI)
	{
		*ry = (int)(player.y / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
		*rx = (player.y - *ry) * aTan + player.x;
		*yo = TILE_SIZE;
		*xo = -(*yo) * aTan;
	} /* Looking down */
}
/**
 * playerLookingUp - This function permit to get the distance
 * between player and wall if he looking Down
 * @player: The player current position
 * @rx: The rayon x
 * @ry: The rayon y
 * @ra: The rayon angle
 * @dof: The tan of the angle
 * Return: Nothing
*/
void lookingStraigth(SDL_Point player, float ra, float *rx,
float *ry, int *dof)
{
	if (ra == 0 || ra == PI)
	{
		*rx = player.x;
		*ry = player.y;
		*dof = 8;
	}
}
