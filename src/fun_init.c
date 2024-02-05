#include "INC/header.h"
int initInstance(SDL_Instance *instance){
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_Log("Erreur: Initialisation de la SDL > %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    instance->window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!instance->window)
        SDL_ExitWithError("SDL_CreateWindow");
    instance->renderer = SDL_CreateRenderer(instance->window, -1, 0);
    if (!instance->renderer)
    {
        SDL_DestroyWindow(instance->window);
        SDL_ExitWithError("SDL_CreateRenderer");
    }
    return (0);
}
/**
 * SDL_ExitWithError - Exit the SDL with the giving error message
 * @message: The message to printout
 * Return: 0 on success and 1 on failure
*/
int SDL_ExitWithError(const char *message)
{
    SDL_Log("Error: %s > %s\n", message, SDL_GetError());
    SDL_Quit();
    return (1);
}

int handleEvent(int map[MAP_HEIGHT][MAP_WIDTH],  SDL_Point *player)
{
    SDL_Event event;
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                return (1);
            }
            else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_LEFT:
                        if (player->x - TILE_SIZE >= 0 && map[player->y / TILE_SIZE][player->x / TILE_SIZE - 1] != 1) {
                            player->x -= TILE_SIZE / 3;
                        }
                        break;
                    case SDLK_RIGHT:
                        if (player->x + TILE_SIZE < (TILE_SIZE * MAP_HEIGHT) && map[player->y / TILE_SIZE][player->x / TILE_SIZE + 1] != 1) {
                            player->x += TILE_SIZE / 3;
                        }
                        break;
                    case SDLK_UP:
                        if (player->y - TILE_SIZE >= 0 && map[player->y / TILE_SIZE - 1][player->x / TILE_SIZE] != 1) {
                            player->y -= TILE_SIZE / 3;
                        }
                        break;
                    case SDLK_DOWN:
                        if (player->y + TILE_SIZE < (TILE_SIZE * MAP_HEIGHT) && map[player->y / TILE_SIZE + 1][player->x / TILE_SIZE] != 1) {
                            player->y += TILE_SIZE / 3;
                        }
                        break;
                }
            }
        }
        return (0);
}

SDL_Renderer* initializeSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return NULL;
    }

    SDL_Window* window = SDL_CreateWindow("SDL Player Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        fprintf(stderr, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return NULL;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        fprintf(stderr, "Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return NULL;
    }

    return renderer;
}

SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* path) {
    SDL_Texture* texture = IMG_LoadTexture(renderer, path);
    if (texture == NULL) {
        fprintf(stderr, "Unable to load texture! SDL_Error: %s\n", SDL_GetError());
    }
    return texture;
}

void renderMap(SDL_Renderer* renderer, int map[MAP_HEIGHT][MAP_WIDTH], SDL_Texture* wallTexture) {
    SDL_Texture *floorTexture = loadTexture(renderer, "assets/floortile.png");
    if (wallTexture == NULL || floorTexture == NULL) {
        SDL_DestroyRenderer(renderer);
        return;
    }
    for (int y = 0; y < MAP_HEIGHT; ++y) {
        for (int x = 0; x < MAP_WIDTH; ++x) {
            if (map[y][x] == 1) {
                SDL_Rect wallRect = { x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE - 1, TILE_SIZE - 1 };
                SDL_RenderCopy(renderer, wallTexture, NULL, &wallRect);
            }
            else
            {
                SDL_Rect floorRect = { x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE - 1, TILE_SIZE - 1 };
                SDL_RenderCopy(renderer, floorTexture, NULL, &floorRect);
            }
        }
    }
}

void renderPlayer(SDL_Renderer* renderer, SDL_Texture* playerTexture, int playerX, int playerY) {
    SDL_Rect playerRect = { playerX, playerY, TILE_SIZE / 3, TILE_SIZE / 3 };
    SDL_RenderCopy(renderer, playerTexture, NULL, &playerRect);
}