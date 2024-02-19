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
	for (r = 0; r < SCREEN_WIDTH; r++)
	{
		/* Check Horizontal lines */
		dof = 0;
		float disH = 1000000, hx = player.x, hy = player.y;
		float aTan = -1 / tan(ra);

		playerLookingUp(player, &rx, &ry, &xo, &yo, ra, aTan);
		playerLookingDown(player, &rx, &ry, &xo, &yo, ra, aTan);
		coolisionWithWall(player, map, &rx, &ry, &xo, &yo, &dof,
		&disH, &hx, &hy);

		/* Check Vertical lines */
		dof = 0;
		float disV = 1000000, vx = player.x, vy = player.y;
		float nTan = -tan(ra);

		playerLookingLeft(player, &rx, &ry, &xo, &yo, ra, nTan);
		playerLookingRigth(player, &rx, &ry, &xo, &yo, ra, nTan);
		coolisionWithWall(player, map, &rx, &ry, &xo, &yo, &dof,
		&disV, &vx, &vy);
		cutRayLength(&disT, disV, disH, &rx, &ry, hx, hy, vx, vy);

		SDL_SetRenderDrawColor(renderer, 123, 34, 18, 255);
		SDL_RenderDrawLine(renderer, player.x + sqrt(TILE_SIZE) / 2,
		player.y + sqrt(TILE_SIZE) / 2, rx, ry);

		draw3dWalls(renderer, playerAngle, &disT, r, ra);		
		ra += PA;
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
	SDL_Rect sky = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT / 2};
	SDL_Rect floor = {0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2};

	/* Draw the sky */
	SDL_SetRenderDrawColor(renderer, 0, 153, 219, 255);
	SDL_RenderFillRect(renderer, &sky);

	/* Draw the floor */
	SDL_SetRenderDrawColor(renderer, 34, 177, 76, 255);
	SDL_RenderFillRect(renderer, &floor);
}
