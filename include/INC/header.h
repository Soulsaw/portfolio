#ifndef HEADER__H
#define HEADER__H
#include "SDL2/SDL.h"
#define SCREEN_WIDTH 860
#define SCREEN_HEIGTH 640
#define MAP_WIDTH 12
#define MAP_HEIGTH 12
/**
 * struct SDL_Instance - The instance of the SDL
 * @window: The window to create
 * @renderer: The renderer for the draw
 *
*/
typedef struct SDL_Instance
{
SDL_Window *window;
SDL_Renderer *renderer;
} SDL_Instance;

int initInstance(SDL_Instance *);
int SDL_ExitWithError(const char *message);
int handleEvent(SDL_Renderer *, SDL_Rect *);
void drawMap2D(SDL_Renderer *);
SDL_Surface *loadMedia();
#endif