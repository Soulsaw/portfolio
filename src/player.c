#include "../headers/player.h"
/**
 * renderPlayer - This function render the player
 * @renderer: The render tho draw
 * @playerX: The x position of the player
 * @playerY: The y position of the player
 * Return: Nothing
*/
void renderPlayer(SDL_Renderer *renderer, int playerX, int playerY)
{
	SDL_Rect playerRect = {playerX, playerY, sqrt(TILE_SIZE), sqrt(TILE_SIZE)};

	SDL_SetRenderDrawColor(renderer, 0XAA, 0XAA, 0XAA, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRect(renderer, &playerRect);
}

/**
 * renderPlayerWithAngle - This function render the player
 * with his direction
 * @renderer: The render tho draw
 * @playerX: The x position of the player
 * @playerY: The y position of the player
 * @playerDirection: The direction of the player
 * Return: Nothing
*/
void renderPlayerWithAngle(SDL_Renderer *renderer, int playerX, int playerY,
		SDL_Point playerDirection)
{
	SDL_Rect playerRect = {playerX, playerY, sqrt(TILE_SIZE), sqrt(TILE_SIZE)};

	SDL_SetRenderDrawColor(renderer, 230, 177, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRect(renderer, &playerRect);
	/* Render the short line representing player direction */
	SDL_SetRenderDrawColor(renderer, 230, 177, 0, SDL_ALPHA_OPAQUE);
	drawThickLine(renderer, playerX + 4,
			playerY + 4,
			playerX + playerDirection.x * 5,
			playerY + playerDirection.y * 5, 3);
	SDL_SetRenderDrawColor(renderer, 113, 113, 113, SDL_ALPHA_OPAQUE);
}
/**
 * dist - This function claculatethe distance betwen player and walls
 * @ax: The a abscissa
 * @bx: The b abscissa
 * @ay: The a ordinate
 * @by: The b ordinate
 * Return: The gap between two points
*/
float dist(float ax, float ay, float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}
