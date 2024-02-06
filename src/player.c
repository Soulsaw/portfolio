#include "INC/player.h"

void renderPlayer(SDL_Renderer *renderer, int playerX, int playerY)
{
    SDL_SetRenderDrawColor(renderer, 0XAA, 0XAA, 0XAA, SDL_ALPHA_OPAQUE);
    SDL_Rect playerRect = {playerX, playerY, TILE_SIZE / 3, TILE_SIZE / 3};
    SDL_RenderFillRect(renderer, &playerRect);
}

void renderPlayerWithAngle(SDL_Renderer *renderer, int playerX, int playerY,
                           SDL_Point point)
{
    SDL_SetRenderDrawColor(renderer, 0XAA, 0XAA, 0XAA, SDL_ALPHA_OPAQUE);
    SDL_Rect playerRect = {playerX, playerY, TILE_SIZE / 3, TILE_SIZE / 3};
    SDL_RenderFillRect(renderer, &playerRect);

    /* Render the short line representing player direction */
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color
    SDL_RenderDrawLine(renderer, playerX + (TILE_SIZE / 6),
                       playerY + (TILE_SIZE / 6),
                       playerX + point.x * 3,
                       playerY + point.y * 3);
    SDL_SetRenderDrawColor(renderer, 0X7F, 0X7F, 0X7F, SDL_ALPHA_OPAQUE);
}
void renderPlayerTexture(SDL_Renderer *renderer, SDL_Texture *playerTexture,
                         int playerX, int playerY)
{
    SDL_Rect playerRect = {playerX, playerY, TILE_SIZE / 3, TILE_SIZE / 3};
    SDL_RenderCopy(renderer, playerTexture, NULL, &playerRect);
}