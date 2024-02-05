#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "SDL2/SDL.h"
#include "INC/header.h"
/**
 * main - The entry point of the program
 * @ac: The argument size
 * @av: Pointer to pointer of array
 * Return: 0 on Success
*/
int main(int ac, char **av)
{
    SDL_Instance instance;
    SDL_Rect rect1 = {.x = (int)(SCREEN_WIDTH / MAP_HEIGTH), .y = (int)(SCREEN_HEIGTH / MAP_HEIGTH), .w = 12, .h = 12};
    bool quit =true;

    if (initInstance(&instance) == 1)
        return (EXIT_FAILURE);
    drawMap2D(instance.renderer);
    while (quit)
    {
        SDL_SetRenderDrawColor(instance.renderer, 76, 178, 76, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(instance.renderer, &rect1);
        if (handleEvent(instance.renderer, &rect1) == 1)
            quit = false;

        SDL_RenderPresent(instance.renderer);
    }
    SDL_DestroyRenderer(instance.renderer);
    SDL_DestroyWindow(instance.window);
    SDL_Quit();
    return EXIT_SUCCESS;
}