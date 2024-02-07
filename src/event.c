#include "../headers/event.h"
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
int handleEvent(SDL_Point *player)
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
                player->x -= 5;
                break;
            case SDLK_d:
                player->x += 5;
                break;
            case SDLK_w:
                player->y -= 5;
                break;
            case SDLK_s:
                player->y += 5;
                break;
            }
        }
    }
    return (0);
}

int handleEventWithAngle(SDL_Point *player, float *playerAngle,
                         SDL_Point *playerDirection)
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
                *playerAngle -= 0.1;
                if (*playerAngle < 0)
                    *playerAngle += 2 * PI;
                playerDirection->x = cos(*playerAngle) * 5;
                playerDirection->y = sin(*playerAngle) * 5;
                break;
            case SDLK_d:
                *playerAngle += 0.1;
                if (*playerAngle > 2 * PI)
                    *playerAngle -= 2 * PI;
                playerDirection->x = cos(*playerAngle) * 5;
                playerDirection->y = sin(*playerAngle) * 5;
                break;
            case SDLK_w:
                player->x += playerDirection->x;
                player->y += playerDirection->y;
                break;
            case SDLK_s:
                player->x -= playerDirection->x;
                player->y -= playerDirection->y;
                break;
            }
        }
    }
    return (0);
}
