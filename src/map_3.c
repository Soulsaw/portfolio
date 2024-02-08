#include "../headers/map.h"
#include "../headers/player.h"
/**
 * drawRays2d - This function draw a map using the RGBA color
 * to fill the rectangle
 * @renderer: The renderer to draw the map on
 * \param renderer The renderer to draw the map on
 * @map: The map the Matrix of `X` column and `Y` row
 * \param map The map the Matrix of `X` column and `Y` row
 * @playerAngle: The texture to use
 * \param playerAngle The texture using for drawing
 * @player: The player current position
 * \param player The player current position
 * Return: Nothing
 * \returns Nothing
 */
void drawRays2d(SDL_Renderer *renderer, float playerAngle,
SDL_Point player, int map[])
{
	int r, dof, disT;
	float rx, ry, ra, xo, yo;

	drawFloorAndSky(renderer);
	ra = playerAngle - DR * 30;
	ra = moveAngle(ra);
	for (r = 0; r < 60; r++)
	{
		/* Check Horizontal lines */
		dof = 0;
		float disH = 1000000, hx = player.x, hy = player.y;
		float aTan = -1 / tan(ra);

		playerLookingUp(player, &rx, &ry, &xo, &yo, ra, aTan);
		playerLookingDown(player, &rx, &ry, &xo, &yo, ra, aTan);
		lookingStraigth(player, ra, &rx, &ry, &dof);
		coolisionWithWall(player, map, &rx, &ry, &xo, &yo, &dof,
		&disH, &hx, &hy);
		/* Check Vertical lines */
		dof = 0;
		float disV = 1000000, vx = player.x, vy = player.y;
		float nTan = -tan(ra);

		playerLookingLeft(player, &rx, &ry, &xo, &yo, ra, nTan);
		playerLookingRigth(player, &rx, &ry, &xo, &yo, ra, nTan);
		lookingStraigth(player, ra, &rx, &ry, &dof);
		coolisionWithWall(player, map, &rx, &ry, &xo, &yo, &dof,
		&disV, &vx, &vy);
		cutRayLength(&disT, disV, disH, &rx, &ry, hx, hy, vx, vy);

		SDL_SetRenderDrawColor(renderer, 113, 113, 113, 255);
		SDL_RenderDrawLine(renderer, player.x + 4, player.y + 4, rx, ry);

		draw3dWalls(renderer, playerAngle, &disT, r, ra);
		ra += DR;
		ra = moveAngle(ra);
	}
}

/**
 * drawFloorAndSky - This function permit to set the color of
 * the sky and the floor
 * @renderer: The renderer to print on
 * \param renderer the renderer to draw on
 * Return: Nothing
 * \returns Nothing
*/
void drawFloorAndSky(SDL_Renderer *renderer)
{
	SDL_Rect sky = {534, 0, 470, 160};
	SDL_Rect floor = {534, 160, 470, 160};

	/* Draw the sky */
	SDL_SetRenderDrawColor(renderer, 0, 153, 219, 255);
	SDL_RenderFillRect(renderer, &sky);

	/* Draw the floor */
	SDL_SetRenderDrawColor(renderer, 34, 177, 76, 255);
	SDL_RenderFillRect(renderer, &floor);
}