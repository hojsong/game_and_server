#include "../header/client.h"

double calculate_distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void	*space_bullets_collision_decision(void *ptr){
	t_game *game = (t_game *)ptr;
	int	size, idx;
	double distance;

	size = bulletOfMode(game);
	idx = 0;
	while (1)
	{
	    pthread_mutex_lock(game->bullets[idx].bullet_mutex);
		distance = calculate_distance(game->my_character.x, \
			game->my_character.y, game->bullets->x, game->bullets->y);
	    pthread_mutex_unlock(game->bullets[idx].bullet_mutex);
		if (distance < 10)
		{
			printf("die\n");
			game->die = 1;
			choiceImagesPut("EXIT", game);
			break;
		}
		idx++;
		if (idx >= size)
			idx = 0;
		usleep(1000);
	}
	return (0);
}