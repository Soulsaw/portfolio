#include "../headers/player.h"

void renderPlayer(SDL_Renderer *renderer, int playerX, int playerY)
{
    SDL_SetRenderDrawColor(renderer, 0XAA, 0XAA, 0XAA, SDL_ALPHA_OPAQUE);
    SDL_Rect playerRect = {playerX, playerY, sqrt(TILE_SIZE), sqrt(TILE_SIZE)};
    SDL_RenderFillRect(renderer, &playerRect);
}

void renderPlayerWithAngle(SDL_Renderer *renderer, int playerX, int playerY,
                           SDL_Point playerDirection)
{
    SDL_SetRenderDrawColor(renderer, 230, 177, 0, SDL_ALPHA_OPAQUE);
    SDL_Rect playerRect = {playerX, playerY, sqrt(TILE_SIZE), sqrt(TILE_SIZE)};
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
 * @ax:
 * @bx:
 * @ay:
 * @by:
 * Return: The sqrt of
*/
float dist(float ax, float ay, float bx, float by)
{
    return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}