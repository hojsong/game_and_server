#include "../header/client.h"
#include <SDL2/SDL.h>

int key_press(int key_code, t_game *game)
{
    if (game->die != 0)
        return (0);
    if (key_code == SDL_SCANCODE_W || key_code == SDL_SCANCODE_UP)
        game->key[0] = 1;
    if (key_code == SDL_SCANCODE_A || key_code == SDL_SCANCODE_LEFT)
        game->key[1] = 1;
    if (key_code == SDL_SCANCODE_S || key_code == SDL_SCANCODE_DOWN)
        game->key[2] = 1;
    if (key_code == SDL_SCANCODE_D || key_code == SDL_SCANCODE_RIGHT)
        game->key[3] = 1;
    return (0);
}

int key_release(int key_code, t_game *game)
{
    if (game->die != 0)
        return (0);
    if (key_code == SDL_SCANCODE_W || key_code == SDL_SCANCODE_UP)
        game->key[0] = 0;
    if (key_code == SDL_SCANCODE_A || key_code == SDL_SCANCODE_LEFT)
        game->key[1] = 0;
    if (key_code == SDL_SCANCODE_S || key_code == SDL_SCANCODE_DOWN)
        game->key[2] = 0;
    if (key_code == SDL_SCANCODE_D || key_code == SDL_SCANCODE_RIGHT)
        game->key[3] = 0;
    return (0);
}

void characterMove(t_game *game)
{
    // wa
    if (game->key[0] == 1 && game->key[1] == 1 && game->my_character.x > 2 && game->my_character.y > 2)
    {
        game->my_character.x -= sqrt((Player_speed * Player_speed) / 2);
        game->my_character.y -= sqrt((Player_speed * Player_speed) / 2);
    }
    // as
    else if (game->key[1] == 1 && game->key[2] == 1 && game->my_character.x > 2 && game->my_character.y < Window_y)
    {
        game->my_character.x -= sqrt((Player_speed * Player_speed) / 2);
        game->my_character.y += sqrt((Player_speed * Player_speed) / 2);
    }
    // sd
    else if (game->key[2] == 1 && game->key[3] == 1 && game->my_character.x < Window_x && game->my_character.y < Window_y)
    {
        game->my_character.x += sqrt((Player_speed * Player_speed) / 2);
        game->my_character.y += sqrt((Player_speed * Player_speed) / 2);
    }
    // wd
    else if (game->key[3] == 1 && game->key[0] == 1 && game->my_character.x < Window_x && game->my_character.y > 2)
    {
        game->my_character.x += sqrt((Player_speed * Player_speed) / 2);
        game->my_character.y -= sqrt((Player_speed * Player_speed) / 2);
    }
    else if (game->key[0] == 1 && game->my_character.y > 2)
        game->my_character.y -= Player_speed;
    else if (game->key[1] == 1 && game->my_character.x > 2)
        game->my_character.x -= Player_speed;
    else if (game->key[2] == 1 && game->my_character.y < Window_y)
        game->my_character.y += Player_speed;
    else if (game->key[3] == 1 && game->my_character.x < Window_x)
        game->my_character.x += Player_speed;
}

int bullet_init_c_d_m_p(void *ptr)
{
    t_game *game;
    time_t now;

    game = (t_game *)ptr;
    if (game->die != 0)
        return (0);
    now = time(NULL);
    if (now - game->frameTime > 0.1)
    {
        game->frameTime += 0.1;
        characterMove(game);
        bullets_create_destroy(game);
        bullets_movement(game);
    }
    space_bullets_collision_decision(game);
    put_game_ing_image(game);
#ifndef __APPLE__
    SDL_Delay(10); // SDL usleep 대체
#endif
    return (0);
}

void exit_game(t_game *game)
{
    if (game->sockfd != -1)
        close(game->sockfd);

    // SDL 관련 자원 해제
    SDL_DestroyTexture(game->bulletimage);
    SDL_DestroyTexture(game->characterImages[0]);
    SDL_DestroyTexture(game->characterImages[1]);
    SDL_DestroyTexture(game->characterImages[2]);
    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(game->window);

    SDL_Quit();
    exit(0);
}

int sdl_start(int key_code, t_game *game)
{
    if (key_code == SDL_SCANCODE_ESCAPE)
    {
        exit_game(game);
    }

    if (game->wlmode == 0)
        wlmodeChoice(key_code, game);
    else if (game->my_character.num == -1)
        airplainChoice(key_code, game);
    else if (game->mode == 0)
        modeChoice(key_code, game);
    else if (game->die == 0)
    {
        key_press(key_code, game);
    }
    else if (game->die == 1)
    {
        score_LOAD_SAVE_view(key_code, game);
    }
    else if (game->die == 3)
    {
        choiceImagesPut("Continue", game);
        game->die = 2;
    }
    else
    {
        continue_or_exit(key_code, game);
    }
    return (0);
}
