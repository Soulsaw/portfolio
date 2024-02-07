#include "INC/header.h"

SDL_Renderer *initializeSDL()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n",
                SDL_GetError());
        return NULL;
    }

    SDL_Window *window = SDL_CreateWindow("SDL Player Example",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SCREEN_WIDTH,
                                          SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        fprintf(stderr, "Window could not be created! SDL_Error: %s\n",
                SDL_GetError());
        SDL_Quit();
        return NULL;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
                                                SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        fprintf(stderr, "Renderer could not be created! SDL_Error: %s\n",
                SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return NULL;
    }

    return renderer;
}


void drawThickLine(SDL_Renderer* renderer, int x1, int y1, int x2, int y2, int width) {
    // Calculate the deltas
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    // Calculate the number of segments needed to cover the width
    int segments = width / 2;

    // Draw each segment
    for (int i = -segments; i <= segments; i++) {
        // Calculate the offsets
        int offsetX = dy * i / segments;
        int offsetY = dx * i / segments;

        // Draw the line segment
        SDL_RenderDrawLine(renderer, x1 - offsetX, y1 + offsetY, x2 - offsetX, y2 + offsetY);
    }
}