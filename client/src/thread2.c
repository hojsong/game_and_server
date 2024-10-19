#include "../header/client.h"

void move_point(t_bullet *bullet) {
	if (bullet->angle == -1)
		return ;
	else if (bullet->x < 0 || bullet->x > Window_x)
		return ;
	else if (bullet->y < 0 || bullet->y > Window_x)
		return ;
	
    double rad_angle = bullet->angle * (PI / 180.0);

    bullet->x += bullet->speed * cos(rad_angle);
    bullet->y += bullet->speed * sin(rad_angle);
}

void	*bullets_movement(void *ptr){
	t_game 	*game = (t_game *)ptr;
	int		idx;

	idx = 0;
	while (idx < game->size)
	{
		if (game->die)
			break;
	    pthread_mutex_lock(game->bullets[idx].bullet_mutex);
		move_point(&game->bullets[idx]);

	    pthread_mutex_unlock(game->bullets[idx].bullet_mutex);
		idx++;
		if (game->die)
			break;
	}
	return (0);
}