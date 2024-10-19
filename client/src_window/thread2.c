#include "../header/client.h"

void move_point(t_bullet *bullet) {
    if (bullet->angle == -1)
        return;
    else if (bullet->x < 0 || bullet->x > WINDOW_X)
        return;
    else if (bullet->y < 0 || bullet->y > WINDOW_Y)
        return;
    
    double rad_angle = bullet->angle * (PI / 180.0);

    bullet->x += bullet->speed * cos(rad_angle);
    bullet->y += bullet->speed * sin(rad_angle);
}

void *bullets_movement(void *ptr) {
    t_game *game = (t_game *)ptr;
    int idx;

    idx = 0;
    while (idx < game->size) {
        if (game->die)
            break;

        SDL_LockMutex(game->bullets[idx].bullet_mutex);
        move_point(&game->bullets[idx]);
        SDL_UnlockMutex(game->bullets[idx].bullet_mutex);

        idx++;
        if (game->die)
            break;
    }
    return NULL;
}