#include "INC/header.h"
int initInstance(SDL_Instance *instance){
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_Log("Erreur: Initialisation de la SDL > %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    instance->window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH, SCREEN_HEIGTH, SDL_WINDOW_SHOWN);
    if (!instance->window)
        SDL_ExitWithError("SDL_CreateWindow");
    instance->renderer = SDL_CreateRenderer(instance->window, -1, 0);
    if (!instance->renderer)
    {
        SDL_DestroyWindow(instance->window);
        SDL_ExitWithError("SDL_CreateRenderer");
    }
    return (0);
}
/**
 * SDL_ExitWithError - Exit the SDL with the giving error message
 * @message: The message to printout
 * Return: 0 on success and 1 on failure
*/
int SDL_ExitWithError(const char *message)
{
    SDL_Log("Error: %s > %s\n", message, SDL_GetError());
    SDL_Quit();
    return (1);
}

int handleEvent(SDL_Renderer *render, SDL_Rect *rect)
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
            return 1;
        else if (event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_a:
                if (rect->x > 0)
                {
                    rect->x -= 5;
                }
                break;
            case SDLK_d:
                if (rect->x < SCREEN_WIDTH)
                {
                    rect->x += 5;
                }
                break;
            case SDLK_w:
                if (rect->y > 0)
                {
                    rect->y -= 5;
                }
                break;
            case SDLK_s:
                if (rect->y < SCREEN_HEIGTH)
                {
                    rect->y += 5;
                }
                break;                                            
            }
        }
        /**SDL_RenderFillRect(render, rect);*/
        SDL_RenderPresent(render);
    }
    return (0);
}
void drawMap2D(SDL_Renderer *render)
{
    int map[] =
    {
        1,1,1,1,1,1,1,1,1,1,1,1,
        1,0,0,0,1,0,0,0,0,0,0,1,
        1,0,0,0,1,0,0,1,0,0,0,1,
        1,0,0,1,1,0,0,1,1,1,1,1,
        1,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,1,1,1,0,0,1,1,1,1,
        1,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,1,
        1,1,1,1,1,0,0,1,1,1,1,1
    };
    int x, y, x0, y0;

    x0 = (int)(SCREEN_WIDTH / MAP_HEIGTH);
    y0 = (int)(SCREEN_HEIGTH / MAP_HEIGTH);
    for (x = 0; x < MAP_HEIGTH; x++)
    {
        for (y = 0; y < MAP_HEIGTH; y++)
        {
            if (map[y + (x * MAP_HEIGTH)] == 1)
                SDL_SetRenderDrawColor(render, 97, 97, 97, SDL_ALPHA_OPAQUE);
            else
                SDL_SetRenderDrawColor(render, 20, 150, 10, SDL_ALPHA_OPAQUE);
            SDL_Rect rect = {.x = y * x0, .y = x * y0, .w = x0 - 1, .h = y0 - 1};
            SDL_RenderFillRect(render, &rect);
            SDL_RenderPresent(render);
        }
    }
}

SDL_Surface *loadMedia()
{
    SDL_Surface *surface = NULL;

    return (surface);
}