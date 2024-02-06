#include "INC/media.h"
/**
 * loadTexture - This function permit to load an image like texture
 * @renderer: The render to load the image on
 * @path: The path to the file
 * \param renderer The renderer to load the image on
 * \param path The path to the file to load.
 * Return: An texture
 * \returns A loaded texture
*/
SDL_Texture *loadTexture(SDL_Renderer *renderer, const char *path)
{
    SDL_Texture *texture = IMG_LoadTexture(renderer, path);
    if (texture == NULL)
    {
        fprintf(stderr, "Unable to load texture! SDL_Error: %s\n",
                SDL_GetError());
    }
    return (texture);
}
