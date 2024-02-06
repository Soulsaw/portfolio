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
void renderMap(SDL_Renderer *renderer, int map[MAP_HEIGHT][MAP_WIDTH])
{
    for (int y = 0; y < MAP_HEIGHT; ++y)
    {
        for (int x = 0; x < MAP_WIDTH; ++x)
        {
            if (map[y][x] == 1)
            {
                SDL_SetRenderDrawColor(renderer, 0XFF, 0XFF, 0XFF,
                                       SDL_ALPHA_OPAQUE);
                SDL_Rect wallRect = {x * TILE_SIZE, y * TILE_SIZE,
                                     TILE_SIZE - 1, TILE_SIZE - 1};
                SDL_RenderFillRect(renderer, &wallRect);
            }
            else
            {
                SDL_SetRenderDrawColor(renderer, 0X00, 0X00, 0X00, 255);
                SDL_Rect floorRect = {x * TILE_SIZE, y * TILE_SIZE,
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
void renderMapTexture(SDL_Renderer *renderer, int map[MAP_HEIGHT][MAP_WIDTH],
                      SDL_Texture *wallTexture, SDL_Texture *floorTexture)
{
    for (int y = 0; y < MAP_HEIGHT; ++y)
    {
        for (int x = 0; x < MAP_WIDTH; ++x)
        {
            if (map[y][x] == 1)
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
