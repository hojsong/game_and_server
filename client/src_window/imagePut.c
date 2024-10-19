#include "../header/client.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

static char *xpm_dir_sum(char *dir, char *src_name, char *expr)
{
    char *result;
    int i, len, dir_len, src_name_len, expr_len;

    dir_len = strlen(dir);
    src_name_len = strlen(src_name);
    expr_len = strlen(expr);
    len = dir_len + src_name_len + expr_len;
    i = 0;
    result = malloc(sizeof(char) * (len + 1));
    while (i < dir_len)
    {
        result[i] = dir[i];
        i++;
    }
    while (i - dir_len < src_name_len)
    {
        result[i] = src_name[i - dir_len];
        i++;
    }
    while (i - dir_len - src_name_len < expr_len)
    {
        result[i] = expr[i - dir_len - src_name_len];
        i++;
    }
    result[i] = '\0';
    return (result);
}

void choiceImagesPut(char *str, t_game *game)
{
    int img_width, img_height;
    int x0, x1, y0, y1, y3;
    char *resource;
    SDL_Texture *modexpmimage;

    resource = xpm_dir_sum("./source/image/png/", str, ".png");
    SDL_Surface *image_surface = IMG_Load(resource);
    if (!image_surface)
    {
        printf("IMG_Load Error: %s\n", IMG_GetError());
        free(resource);
        return;
    }
    modexpmimage = SDL_CreateTextureFromSurface(game->renderer, image_surface);
    SDL_FreeSurface(image_surface);
    free(resource);

    SDL_QueryTexture(modexpmimage, NULL, NULL, &img_width, &img_height);

    x0 = (Window_x - ARROW_X) / 2;
    x1 = (Window_x / 2) - (img_width / 2);
    y3 = (Window_y / 2) - (img_height / 2);
    y0 = (Window_y / 2) + (img_height / 2) + 20;
    y1 = (Window_y / 2) - (img_height / 2) - 20 - ARROW_Y;

    SDL_RenderClear(game->renderer);
    SDL_RenderCopy(game->renderer, game->arrow[1], NULL, &(SDL_Rect){x0, y0, ARROW_X, ARROW_Y});
    SDL_RenderCopy(game->renderer, game->arrow[0], NULL, &(SDL_Rect){x0, y1, ARROW_X, ARROW_Y});
    if (modexpmimage)
    {
        SDL_RenderCopy(game->renderer, modexpmimage, NULL, &(SDL_Rect){x1, y3, img_width, img_height});
        SDL_DestroyTexture(modexpmimage);
    }
    SDL_RenderPresent(game->renderer);
}

void airPlainChoicePut(int result, t_game *game)
{
    int x0, x1, y0, y1, y3;

    x0 = (Window_x - ARROW_X) / 2;
    x1 = (Window_x - Charactet_x) / 2;

    y0 = (Window_y / 2) + 200;
    y1 = (Window_y / 2) - 200 - ARROW_Y;
    y3 = (Window_y - Charactet_y) / 2;

    SDL_RenderClear(game->renderer);
    SDL_RenderCopy(game->renderer, game->arrow[1], NULL, &(SDL_Rect){x0, y0, ARROW_X, ARROW_Y});
    SDL_RenderCopy(game->renderer, game->arrow[0], NULL, &(SDL_Rect){x0, y1, ARROW_X, ARROW_Y});
    if (game->characterImages[result])
    {
        SDL_RenderCopy(game->renderer, game->characterImages[result * 2], NULL, &(SDL_Rect){x1, y3, Charactet_x, Charactet_y});
    }
    SDL_RenderPresent(game->renderer);
}

void strPut(char *str, t_game *game)
{
    SDL_RenderClear(game->renderer);
    TTF_Font *font = TTF_OpenFont("path/to/font.ttf", 24); // 폰트 파일 경로 수정 필요
    if (!font)
    {
        printf("TTF_OpenFont Error: %s\n", TTF_GetError());
        return;
    }

    SDL_Color color = {255, 255, 255, 255};

    SDL_Surface *surface_message = TTF_RenderText_Solid(font, "Please enter your nickname", color);
    SDL_Texture *message_texture = SDL_CreateTextureFromSurface(game->renderer, surface_message);
    SDL_RenderCopy(game->renderer, message_texture, NULL, &(SDL_Rect){10, (Window_y / 2) + 90, 500, 50});

    SDL_FreeSurface(surface_message);
    SDL_DestroyTexture(message_texture);

    surface_message = TTF_RenderText_Solid(font, str, color);
    message_texture = SDL_CreateTextureFromSurface(game->renderer, surface_message);
    SDL_RenderCopy(game->renderer, message_texture, NULL, &(SDL_Rect){10, (Window_y / 2) - 10, 500, 50});

    surface_message = TTF_RenderText_Solid(font, "When finished entering, please press Enter.", color);
    message_texture = SDL_CreateTextureFromSurface(game->renderer, surface_message);
    SDL_RenderCopy(game->renderer, message_texture, NULL, &(SDL_Rect){10, (Window_y / 2) - 110, 500, 50});

    SDL_RenderPresent(game->renderer);

    SDL_FreeSurface(surface_message);
    SDL_DestroyTexture(message_texture);
    TTF_CloseFont(font);
}

void rankingPut(char **str, t_game *game)
{
    SDL_RenderClear(game->renderer);
    TTF_Font *font = TTF_OpenFont("path/to/font.ttf", 24); // 폰트 파일 경로 수정 필요
    if (!font)
    {
        printf("TTF_OpenFont Error: %s\n", TTF_GetError());
        return;
    }

    SDL_Color color = {255, 255, 255, 255};
    SDL_Surface *surface_message;
    SDL_Texture *message_texture;
    int idx = 0;

    surface_message = TTF_RenderText_Solid(font, "Ranking", color);
    message_texture = SDL_CreateTextureFromSurface(game->renderer, surface_message);
    SDL_RenderCopy(game->renderer, message_texture, NULL, &(SDL_Rect){(Window_x / 2) - (7 * 3), 10, 200, 50});
    SDL_FreeSurface(surface_message);
    SDL_DestroyTexture(message_texture);

    while (idx < MAX_LINES && str[idx])
    {
        surface_message = TTF_RenderText_Solid(font, str[idx], color);
        message_texture = SDL_CreateTextureFromSurface(game->renderer, surface_message);
        SDL_RenderCopy(game->renderer, message_texture, NULL, &(SDL_Rect){10, 20 + (idx * 15), 500, 30});
        SDL_FreeSurface(surface_message);
        SDL_DestroyTexture(message_texture);
        idx++;
    }

    surface_message = TTF_RenderText_Solid(font, "If confirmed, please enter any key.", color);
    message_texture = SDL_CreateTextureFromSurface(game->renderer, surface_message);
    SDL_RenderCopy(game->renderer, message_texture, NULL, &(SDL_Rect){(Window_x / 2) - ((35 * 3) + 20), Window_y - 10, 500, 50});

    SDL_RenderPresent(game->renderer);

    SDL_FreeSurface(surface_message);
    SDL_DestroyTexture(message_texture);
    TTF_CloseFont(font);
}
