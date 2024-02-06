#include "INC/map.h"
/**
 * renderMap - This function draw a map using the RGBA color
 * to fill the rectangle
 * @renderer: The renderer to draw the map on
 * \param renderer The renderer to draw the map on
 * @map: The map the Matrix of `X` column and `Y` row
 * \param map The map the Matrix of `X` column and `Y` row
 * Return: Nothing
 * \returns Nothing
 */
void renderMap(SDL_Renderer *renderer, int map[TILE_SIZE])
{
    for (int y = 0; y < MAP_HEIGHT; ++y)
    {
        for (int x = 0; x < MAP_WIDTH; ++x)
        {
            if (map[y * MAP_HEIGHT + x] == 1)
            {
                SDL_SetRenderDrawColor(renderer, 0XFF, 0XFF, 0XFF,
                                       SDL_ALPHA_OPAQUE);
                SDL_Rect wallRect = {x * TILE_SIZE + 1, y * TILE_SIZE + 1,
                                     TILE_SIZE - 1, TILE_SIZE - 1};
                SDL_RenderFillRect(renderer, &wallRect);
            }
            else
            {
                SDL_SetRenderDrawColor(renderer, 0X00, 0X00, 0X00, 255);
                SDL_Rect floorRect = {x * TILE_SIZE + 1, y * TILE_SIZE + 1,
                                      TILE_SIZE - 1, TILE_SIZE - 1};
                SDL_RenderFillRect(renderer, &floorRect);
            }
        }
    }
}
/**
 * renderMap - This function draw a map using the RGBA color
 * to fill the rectangle
 * @renderer: The renderer to draw the map on
 * \param renderer The renderer to draw the map on
 * @map: The map the Matrix of `X` column and `Y` row
 * \param map The map the Matrix of `X` column and `Y` row
 * @wallTexture: The texture to use
 * \param wallTexture The texture using for drawing
 * Return: Nothing
 * \returns Nothing
 */
void renderMapTexture(SDL_Renderer *renderer, int map[TILE_SIZE],
                      SDL_Texture *wallTexture, SDL_Texture *floorTexture)
{
    for (int y = 0; y < MAP_HEIGHT; ++y)
    {
        for (int x = 0; x < MAP_WIDTH; ++x)
        {
            if (map[y * MAP_HEIGHT + x] == 1)
            {
                SDL_Rect wallRect = {x * TILE_SIZE, y * TILE_SIZE,
                                     TILE_SIZE - 1, TILE_SIZE - 1};
                SDL_RenderCopy(renderer, wallTexture, NULL, &wallRect);
            }
            else
            {
                SDL_Rect floorRect = {x * TILE_SIZE, y * TILE_SIZE,
                                      TILE_SIZE - 1, TILE_SIZE - 1};
                SDL_RenderCopy(renderer, floorTexture, NULL, &floorRect);
            }
        }
    }
    SDL_DestroyTexture(floorTexture);
}
void drawRays3d(SDL_Renderer *renderer, float playerAngle, SDL_Point player, int map[])
{
    int r, mx, my, mp, dof;
    float rx, ry, ra, xo, yo;

    ra = playerAngle;
    for (r = 0; r < 1; r++)
    {
        // Check Horizontal lines
        dof = 0;
        float aTan = -1 / tan(ra);
        if (ra > PI)
        {
            ry = (((int)player.y >> 6) << 6) - 0.0001;
            rx = (player.y - ry) * aTan + player.x;
            yo = -64;
            xo = -yo * aTan;
        } // Looking up
        if (ra < PI)
        {
            ry = (((int)player.y >> 6) << 6) + 64;
            rx = (player.y - ry) * aTan + player.x;
            yo = 64;
            xo = -yo * aTan;
        } // Looking down
        if (ra == 0 || ra == PI)
        {
            rx = player.x;
            ry = player.y;
            dof = 8;
        } // looking straigth left or right
        while (dof < 8)
        {
            mx = (int)(rx) >> 6;
            my = (int)(ry) >> 6;
            mp = my * MAP_HEIGHT + mx;
            if (mp > 0 && mp < TILE_SIZE && map[mp] == 1)
            {
                dof = 8;
            }
            else
            {
                rx += xo;
                ry += yo;
                dof += 1;
            }
        }
        SDL_SetRenderDrawColor(renderer, 0, 255, 128, 255);
        SDL_RenderDrawLine(renderer, player.x + 4, player.y + 4, rx, ry);
        SDL_SetRenderDrawColor(renderer, 0X7F, 0X7F, 0X7F, SDL_ALPHA_OPAQUE);

        // Check Vertical lines
        dof = 0;
        float nTan = -tan(ra);
        if (ra > P2 && ra < P3)
        {
            rx = (((int)player.x >> 6) << 6) - 0.0001;
            ry = (player.x - rx) * nTan + player.y;
            xo = -64;
            yo = -xo * nTan;
        } // Looking left
        if (ra < P2 || ra > P3)
        {
            rx = (((int)player.x >> 6) << 6) + 64;
            ry = (player.x - rx) * nTan + player.y;
            xo = 64;
            yo = -xo * nTan;
        } // Looking rigth
        if (ra == 0 || ra == PI)
        {
            rx = player.x;
            ry = player.y;
            dof = 8;
        } // looking straigth up or down
        while (dof < 8)
        {
            mx = (int)(rx) >> 6;
            my = (int)(ry) >> 6;
            mp = my * MAP_HEIGHT + mx;
            if (mp > 0 && mp < TILE_SIZE && map[mp] == 1)
            {
                dof = 8;
            }
            else
            {
                rx += xo;
                ry += yo;
                dof += 1;
            }
        }
        SDL_SetRenderDrawColor(renderer, 237, 28, 36, 255);
        SDL_RenderDrawLine(renderer, player.x + 4, player.y + 4, rx, ry);
        SDL_SetRenderDrawColor(renderer, 0X7F, 0X7F, 0X7F, SDL_ALPHA_OPAQUE);
    }
}
