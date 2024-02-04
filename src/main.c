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
    SDL_Rect rect1 = {.x = 100, .y = 100, .w = 20, .h = 20};
    bool quit =true;

    if (initInstance(&instance) == 1)
        return (EXIT_FAILURE);
    drawMap2D(instance.renderer);
    while (quit)
    {
        if (handleEvent(instance.renderer, &rect1) == 1)
            quit = false;

        SDL_RenderPresent(instance.renderer);
    }
    SDL_DestroyRenderer(instance.renderer);
    SDL_DestroyWindow(instance.window);
    SDL_Quit();
    return EXIT_SUCCESS;
}