#include "INC/event.h"
/**
 * handleEvent - This function permit to move the player user the user handler
 * Description: This function permit to push the player if the user press on the
 * keys right
 * @map: Is the game map
 * \param map The game ```map```
 * \param player The current ```player position```
 * @player: Is the player current position
 * Return: 0 or 1
 */
int handleEvent(int map[MAP_HEIGHT][MAP_WIDTH], SDL_Point *player)
{
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0)
    {
        if (event.type == SDL_QUIT)
            return (1);
        else if (event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_a:
                if (player->x - TILE_SIZE >=
                        0 &&
                    map[player->y / TILE_SIZE]
                       [(player->x - (TILE_SIZE / 3)) / TILE_SIZE] != 1)
                {
                    player->x -= TILE_SIZE / 3;
                }
                break;
            case SDLK_d:
                if (player->x + TILE_SIZE <
                        (TILE_SIZE * MAP_HEIGHT) - (TILE_SIZE / 3) &&
                    map[player->y / TILE_SIZE]
                       [(player->x + (TILE_SIZE / 3)) / TILE_SIZE] != 1)
                {
                    player->x += TILE_SIZE / 3;
                }
                break;
            case SDLK_w:
                if (player->y - TILE_SIZE >= 0 &&
                    map[(player->y - (TILE_SIZE / 3)) / TILE_SIZE][player->x / TILE_SIZE] != 1)
                {
                    player->y -= TILE_SIZE / 3;
                }
                break;
            case SDLK_s:
                if (player->y < (TILE_SIZE * MAP_HEIGHT) -
                                    (TILE_SIZE / 3) &&
                    map[(player->y + (TILE_SIZE / 3)) / TILE_SIZE]
                       [player->x / TILE_SIZE] != 1)
                {
                    player->y += TILE_SIZE / 3;
                }
                break;
            }
        }
    }
    return (0);
}

int handleEventWithAngle(int map[MAP_HEIGHT][MAP_WIDTH], SDL_Point *player,
                         float *playerAngle, SDL_Point *point)
{
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0)
    {
        if (event.type == SDL_QUIT)
            return (1);
        else if (event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_a:
                if (player->x - TILE_SIZE >=
                        0 &&
                    map[player->y / TILE_SIZE]
                       [(player->x - (TILE_SIZE / 3)) / TILE_SIZE] != 1)
                {
                    *playerAngle -= 0.1;
                    if (*playerAngle < 0)
                        *playerAngle += 2 * PI;
                    point->x = cos(*playerAngle) * (TILE_SIZE / 3);
                    point->y = sin(*playerAngle) * (TILE_SIZE / 3);
                }
                break;
            case SDLK_d:
                if (player->x + TILE_SIZE <
                        (TILE_SIZE * MAP_HEIGHT) - (TILE_SIZE / 3) &&
                    map[player->y / TILE_SIZE]
                       [(player->x + (TILE_SIZE / 3)) / TILE_SIZE] != 1)
                {
                    *playerAngle += 0.1;
                    if (*playerAngle > 2 * PI)
                        *playerAngle -= 2 * PI;
                    point->x = cos(*playerAngle) * (TILE_SIZE / 3);
                    point->y = sin(*playerAngle) * (TILE_SIZE / 3);
                }
                break;
            case SDLK_w:
                if (player->y - TILE_SIZE >= 0 &&
                    map[(player->y - (TILE_SIZE / 3)) / TILE_SIZE]
                       [player->x / TILE_SIZE] != 1)
                {
                    player->x += point->x;
                    player->y += point->y;
                }
                break;
            case SDLK_s:
                if (player->y < (TILE_SIZE * MAP_HEIGHT) -
                                    (TILE_SIZE / 3) &&
                    map[(player->y + (TILE_SIZE / 3)) / TILE_SIZE]
                       [player->x / TILE_SIZE] != 1)
                {
                    player->x -= point->x;
                    player->y -= point->y;
                }
                break;
            }
        }
    }
    return (0);
}
