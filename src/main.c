#include "../headers/header.h"
#include "../headers/player.h"
#include "../headers/map.h"
#include "../headers/event.h"
/**
 * main - The entry point of the program
 * Return: 0 on success
 * \returns 0 on success
*/
int main(void)
{
	int playerX = 2 * TILE_SIZE;/* Initial X position of the player */
	int playerY = 2 * TILE_SIZE;/* Initial Y position of the player */
	int quit = 0;
	int map[] = {
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 1, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1
		};/* Example map and player starting position */
		SDL_Point player = {playerX, playerY};
		SDL_Renderer *renderer = initializeSDL();
		float playerAngle = 0.2;
		SDL_Point playerDirection = {cos(playerAngle) * 3, sin(playerAngle) * 3};

		if (!renderer)
			return (1);
		while (!quit)
		{
			if (handleEventWithAngle(&player, &playerAngle, &playerDirection) == 1)
				quit = 1;
			SDL_RenderClear(renderer);
			/* renderMap(renderer, map); */
			drawRays2d(renderer, playerAngle, player, map);
			/* renderPlayer(renderer, player.x, player.y); */
			SDL_RenderPresent(renderer);
		}
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return (0);
}
