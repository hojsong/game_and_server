#include "../header/client.h"

static void    distroy_of_bullets(t_bullet *bullet)
{
    if (bullet->angle == -1)
        return;
    else if (bullet->x < 2 || bullet->x > Window_x - 2 || bullet->y < 2 || bullet->y > Window_y - 2)
    {
        bullet->x = -1;
        bullet->y = -1;
        bullet->angle = -1;
    }
}

static double get_speed_of_mode(int mode, int ran)
{
	double 	result;

	if (mode == 1)
		result = 1 + (double)((ran % 3) / 10);
	if (mode == 2)
		result = 1 + (double)((ran % 6) / 10);
	if (mode == 3)
		result = 1 + (double)((ran % 11) / 10);
	return result;
}

static void     bullet_positioning(t_bullet *bullet, int mode, int ran, int ran2)
{
    if (ran % 4 == 0)
    {
        bullet->x = (double)((ran2 % (Window_x - 4)) + 2);
        bullet->y = (double)2;
    }
    else if (ran % 4 == 1)
    {
        bullet->x = (double)(Window_x - 2);
        bullet->y = (double)((ran2 % (Window_y - 4)) + 2);
    }
    else if (ran % 4 == 2)
    {
        bullet->x = (double)((ran2 % (Window_x - 4)) + 2);
        bullet->y = (double)(Window_y - 2);
    }
    else if (ran % 4 == 3)
    {
        bullet->x = (double)2;
        bullet->y = (double)(((ran2 % (Window_x - 4)) + 2));
    }
    bullet->speed = get_speed_of_mode(mode, ran);
}

static void bullet_angle_calculate(t_character player, t_bullet *bullet, int ran) {
    double angle;

    // atan2를 사용하여 각도를 계산
    angle = atan2(player.y - bullet->y, player.x - bullet->x);
    angle = angle * (180.0 / PI); // 라디안에서 도로 변환
    angle += ran; // 랜덤 각도 추가

    // 각도 범위 조정
    if (angle < 0) {
        angle += 360;
    } else if (angle >= 360) {
        angle -= 360;
    }

    bullet->angle = angle;
}


static void    create_of_bullets(t_bullet *bullet, t_character player, int mode, int ran, int ran2)
{

    distroy_of_bullets(bullet);
    if (bullet->x >= 0 || bullet->y >= 0)
        return;
    bullet_positioning(bullet, mode, ran, ran2);
    bullet_angle_calculate(player, bullet, (ran % 5) - 2);
}

int     bulletOfMode(t_game *game)
{
    if (game->mode == 1)
        return (EASY_MODE);
    else if (game->mode == 2)
        return (NORMAL_MODE);
    else if (game->mode == 3)
        return (HARD_MODE);
    else
        return (0);
}

void	*bullets_create_destroy(void *ptr){
	t_game          *game = (t_game *)ptr;
    int             idx;

    srand(time(NULL));
    idx = 0;
    while (idx < game->size)
    {
        if (game->die == 1)
            break ;
        pthread_mutex_lock(game->bullets[idx].bullet_mutex);
        create_of_bullets(&game->bullets[idx], game->my_character, game->mode, rand(), rand());
        distroy_of_bullets(&game->bullets[idx]);
        pthread_mutex_unlock(game->bullets[idx].bullet_mutex);
        idx++;
        if (game->die == 1)
            break ;
        usleep(1);
    }
    return (0);
}