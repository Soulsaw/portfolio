#include "../headers/map.h"
#include "../headers/player.h"
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
	int x, y;

	for (y = 0; y < MAP_HEIGHT; ++y)
	{
		for (x = 0; x < MAP_WIDTH; ++x)
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
 * drawRays2d - This function draw a map using the RGBA color
 * to fill the rectangle
 * @renderer: The renderer to draw the map on
 * \param renderer The renderer to draw the map on
 * @map: The map the Matrix of `X` column and `Y` row
 * \param map The map the Matrix of `X` column and `Y` row
 * @playerAngle: The texture to use
 * \param playerAngle The texture using for drawing
 * @player: The player current position
 * \param player The player current position
 * Return: Nothing
 * \returns Nothing
 */
void drawRays2d(SDL_Renderer *renderer, float playerAngle, SDL_Point player, int map[])
{
    int r, mx, my, mp, dof, disT;
    float rx, ry, ra, xo, yo;

    ra = playerAngle - DR * 30;
    if (ra < 0)
    {
        ra += 2 * PI;
    }
    if (ra > 2 * PI)
    {
        ra -= 2 * PI;
    }
    for (r = 0; r < 60; r++)
    {
        // Check Horizontal lines
        dof = 0;
        float distH = 1000000, hx = player.x, hy = player.y;
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
                hx = rx;
                hy = ry;
                distH = dist(player.x, player.y, hx, hy);
                dof = 8;
            }
            else
            {
                rx += xo;
                ry += yo;
                dof += 1;
            }
        }
        /* Check Vertical lines */
        dof = 0;
        float distV = 1000000, vx = player.x, vy = player.y;
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
                vx = rx;
                vy = ry;
                distV = dist(player.x, player.y, vx, vy);
                dof = 8;
            }
            else
            {
                rx += xo;
                ry += yo;
                dof += 1;
            }
        }
        if (distV < distH)
        {
            rx = vx;
            ry = vy;
            disT = distV;
        }
        if (distH < distV)
        {
            rx = hx;
            ry = hy;
            disT = distH;
        }

        SDL_SetRenderDrawColor(renderer, 113, 113, 113, 255);
        SDL_RenderDrawLine(renderer, player.x + 4, player.y + 4, rx, ry);
        /* Draw the 3D walls */
        float ca = playerAngle - ra;
        if (ca < 0)
        {
            ca += 2 * PI;
        }
        if (ca > 2 * PI)
        {
            ca -= 2 * PI;
        }
        disT = disT * cos(ca); /* fix fisheye */
        float lineH = (TILE_SIZE * 320) / disT;
        if (lineH > 320)
        {
            lineH = 320;
        }                              /* Line heigth */
        float lineO = 160 - lineH / 2; /* Line offsets */
		SDL_Rect sky = {r * 8 + 530, 2, 10, lineH + lineO};
        SDL_SetRenderDrawColor(renderer, 0, 153, 219, 255);
		SDL_RenderFillRect(renderer, &sky);
        SDL_SetRenderDrawColor(renderer, 113, 113, 113, 255);
        drawThickLine(renderer, r * 8 + 530, lineO, r * 8 + 530, lineH + lineO, 8);
		SDL_Rect floor = {r * 8 + 530, lineH + lineO, 10, lineH + lineO};
        SDL_SetRenderDrawColor(renderer, 34, 177, 76, 255);
		SDL_RenderFillRect(renderer, &floor);
       SDL_SetRenderDrawColor(renderer, 33, 171, 74, SDL_ALPHA_OPAQUE);
        ra += DR;
        if (ra < 0)
        {
            ra += 2 * PI;
        }
        if (ra > 2 * PI)
        {
            ra -= 2 * PI;
        }
    }
}
