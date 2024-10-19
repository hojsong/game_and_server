#include "../header/client.h"

double calculate_distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void	*space_bullets_collision_decision(void *ptr){
	t_game *game = (t_game *)ptr;
	int idx;
	double distance;

	idx = 0;
	while (idx < game->size)
	{
	    pthread_mutex_lock(game->bullets[idx].bullet_mutex);
		distance = calculate_distance(game->my_character.x, \
			game->my_character.y, game->bullets[idx].x, game->bullets[idx].y);
	    pthread_mutex_unlock(game->bullets[idx].bullet_mutex);
		if (distance <= DISTANCE)
		{
			// printf("die\n");
			game->endTime = time(NULL);
			game->die = 1;
			strPut("", game);
			// print Save Data
			break;
		}
		idx++;
	}
	return (0);
}