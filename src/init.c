#include "../headers/header.h"
/**
 * initializeSDL - Initialize the SDL Library and put a renderer on it
 * Return: renderer instanceor NULL on failure
 * \returns An a renderer on windows
*/
SDL_Renderer *initializeSDL()
{
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n",
				SDL_GetError());
		return (NULL);
	}
	window = SDL_CreateWindow("Portfolio project",
							  SDL_WINDOWPOS_UNDEFINED,
							  SDL_WINDOWPOS_UNDEFINED,
							  SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (!window)
	{
		fprintf(stderr, "Window could not be created! SDL_Error: %s\n",
				SDL_GetError());
		SDL_Quit();
		return (NULL);
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer)
	{
		fprintf(stderr, "Renderer could not be created! SDL_Error: %s\n",
				SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		return (NULL);
	}
	return (renderer);
}
/**
 * drawThickLine - Draw a line with a ``thick``
 * @renderer: The renderer to draw the lines
 * \param renderer: The renderer to draw the lines
 * @x1: The started x position
 * \param x1: The started x position
 * @y1: The started y position
 * \param y1: The started y position
 * @x2: The end x position
 * \param x2: The end x position
 * @y2: The end y position
 * \param y2: The end y position
 * @width: The thick of the lines
 * \param width The thick of the lines
 * Return: Nothing
 * \returns Nothing
*/
void drawThickLine(SDL_Renderer *renderer, int x1, int y1,
				   int x2, int y2, int width)
{
	int x;

	for (x = 0; x < width; x++)
	{
		SDL_RenderDrawLine(renderer, x1 + x, y1, x2 + x, y2);
	}
}
