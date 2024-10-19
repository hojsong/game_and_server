#include "../header/client.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void game_image_sdl_init(t_game *game)
{
    int img_width, img_height;

    SDL_Surface *temp_surface;

    // Load bullet image
    temp_surface = IMG_Load("./source/image/png/bullet.png"); // XPM 대신 PNG 사용
    if (!temp_surface)
    {
        printf("Error loading bullet image: %s\n", IMG_GetError());
        return;
    }
    game->bulletimage = SDL_CreateTextureFromSurface(game->renderer, temp_surface);
    SDL_FreeSurface(temp_surface);

    // Load arrow images
    temp_surface = IMG_Load("./source/image/png/UpArrow.png"); // XPM 대신 PNG 사용
    if (!temp_surface)
    {
        printf("Error loading UpArrow image: %s\n", IMG_GetError());
        return;
    }
    game->arrow[0] = SDL_CreateTextureFromSurface(game->renderer, temp_surface);
    SDL_FreeSurface(temp_surface);

    temp_surface = IMG_Load("./source/image/png/DownArrow.png"); // XPM 대신 PNG 사용
    if (!temp_surface)
    {
        printf("Error loading DownArrow image: %s\n", IMG_GetError());
        return;
    }
    game->arrow[1] = SDL_CreateTextureFromSurface(game->renderer, temp_surface);
    SDL_FreeSurface(temp_surface);

    // Load character images
    temp_surface = IMG_Load("./source/image/png/Space1_Small.png"); // XPM 대신 PNG 사용
    if (!temp_surface)
    {
        printf("Error loading character image 1: %s\n", IMG_GetError());
        return;
    }
    game->characterImages[0] = SDL_CreateTextureFromSurface(game->renderer, temp_surface);
    SDL_QueryTexture(game->characterImages[0], NULL, NULL, &img_width, &img_height);
    game->character_x[0] = img_width;
    game->character_y[0] = img_height;
    SDL_FreeSurface(temp_surface);

    temp_surface = IMG_Load("./source/image/png/Space2_Small.png"); // XPM 대신 PNG 사용
    if (!temp_surface)
    {
        printf("Error loading character image 2: %s\n", IMG_GetError());
        return;
    }
    game->characterImages[1] = SDL_CreateTextureFromSurface(game->renderer, temp_surface);
    SDL_QueryTexture(game->characterImages[1], NULL, NULL, &img_width, &img_height);
    game->character_x[1] = img_width;
    game->character_y[1] = img_height;
    SDL_FreeSurface(temp_surface);

    temp_surface = IMG_Load("./source/image/png/Space3_Small.png"); // XPM 대신 PNG 사용
    if (!temp_surface)
    {
        printf("Error loading character image 3: %s\n", IMG_GetError());
        return;
    }
    game->characterImages[2] = SDL_CreateTextureFromSurface(game->renderer, temp_surface);
    SDL_QueryTexture(game->characterImages[2], NULL, NULL, &img_width, &img_height);
    game->character_x[2] = img_width;
    game->character_y[2] = img_height;
    SDL_FreeSurface(temp_surface);

    // Initialize other game variables
    game->wlmode = 0;
    game->my_character.num = -1;
    game->mode = 0;
    game->die = -1;
    game->sockfd = -1;
}
