#include "INC/header.h"
#include "INC/media.h"
#include "INC/player.h"
#include "INC/map.h"
#include "INC/event.h"

int main(int argc, char *argv[])
{
    int playerX = 2 * TILE_SIZE;/* Initial X position of the player */
    int playerY = 2 * TILE_SIZE;/* Initial Y position of the player */
    int quit = 0;
    int map[] = {
        1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 1, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 1, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1};/* Example map and player starting position */
    SDL_Point player = {playerX, playerY};
    SDL_Renderer *renderer = initializeSDL();
    float playerAngle = 0.0;
    SDL_Point playerDirection = {cos(playerAngle) * 5, sin(playerAngle) * 5};
   SDL_Point px ={300, 300};

    if (renderer == NULL)
        return 1;
    while (!quit)
    {
        if (handleEventWithAngle(&player, &playerAngle, &playerDirection) == 1)
            quit = 1;
        SDL_RenderClear(renderer);
        renderMap(renderer, map);
        renderPlayerWithAngle(renderer, player.x, player.y, playerDirection);
        drawRays3d(renderer, playerAngle, player, map);
        SDL_RenderPresent(renderer);
    }
/*     SDL_DestroyTexture(wallTexture);
    SDL_DestroyTexture(playerTexture); */
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    return 0;
}
