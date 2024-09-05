#include "../header/client.h"

int	wlmodeChoice(int key_code, t_game *game)
{
	static int  result = 1;
	if (key_code == KEY_W || key_code == KEY_W2)
		result++;
	else if (key_code == KEY_S || key_code == KEY_S2)
		result--;
	else if (key_code == KEY_ENTER)
	{
		game->wlmode = result;
		choiceImagesPut("Space1_Big", game);
		// airPlainChoicePut(0, game);
		result = 1;
		return (0);
	}
	else
		return (0);
	if (result < 1)
		result += 2;
	else if (result > 2)
		result -= 2;
	if (result == 1)
		choiceImagesPut("WebMode", game);
	else if (result == 2)
		choiceImagesPut("LocalMode", game);
	return (0);
}

int	airplainChoice(int key_code, t_game *game)
{
	static int  result = 0;

	if (key_code == KEY_W || key_code == KEY_W2)
		result++;
	else if (key_code == KEY_S || key_code == KEY_S2)
		result--;
	else if (key_code == KEY_ENTER)
	{
		game->my_character.x = Window_x / 2;
		game->my_character.y = Window_y / 2;
		game->my_character.num = result;
		choiceImagesPut("EASY", game);
		result = 0;
		return (0);
	}
	else
		return (0);
	if (result < 0)
		result += 3;
	else if (result > 2)
		result -= 3;
	if (result == 0)
		choiceImagesPut("Space1_Big", game);
	if (result == 1)
		choiceImagesPut("Space2_Big", game);
	if (result == 2)
		choiceImagesPut("Space3_Big", game);
	// airPlainChoicePut(result, game);
	return (0);
}

int	modeChoice(int key_code, t_game *game)
{
	static int  result = 1;
	int	idx;
	if (key_code == KEY_W || key_code == KEY_W2)
		result++;
	else if (key_code == KEY_S || key_code == KEY_S2)
		result--;
	else if (key_code == KEY_ENTER)
	{
		// game->die = 1;
		// choiceImagesPut("EXIT", game);
		gettimeofday(&game->startTime, NULL);
		game->mode = result;
		result = 1;
		game->size = bulletOfMode(game);
		game->bullets = malloc(sizeof(t_bullet) * (game->size + 1));
    	idx = 0;
    	while (idx < game->size)
    	{
        	game->bullets[idx].bullet_mutex = malloc(sizeof(pthread_mutex_t));
        	pthread_mutex_init(game->bullets[idx].bullet_mutex, NULL);
        	game->bullets[idx].x = -1;
        	game->bullets[idx].y = -1;
        	game->bullets[idx].angle = -1;
        	idx++;
    	}
		pthread_create(&game->thread[0], NULL,
				bullets_create_destroy, (void *)game);
		usleep(100);
		pthread_create(&game->thread[1], NULL,
				bullets_movement, (void *)game);
		pthread_create(&game->thread[2], NULL, \
				space_bullets_collision_decision, (void *)game);
		game->die = 0;
		return (0);
	}
	else
		return(0);
	if (result < 1)
		result += 3;
	else if (result > 3)
		result -= 3;
	if (result == 1)
		choiceImagesPut("EASY", game);
	else if (result == 2)
		choiceImagesPut("NORMAL", game);
	else if (result == 3)
		choiceImagesPut("HARD", game);
	return (0);
}

int	continue_or_exit(int key_code, t_game *game)
{
	int idx;

	if (game->die == 1)
	{
    	idx = 0;
    	while (idx < game->size)
    	{
	        pthread_mutex_unlock(game->bullets[idx].bullet_mutex);
    	    pthread_mutex_destroy(game->bullets[idx].bullet_mutex);
        	free(game->bullets[idx].bullet_mutex);
        	idx++;
    	}
		pthread_join(game->thread[0], NULL);
		pthread_join(game->thread[1], NULL);
		pthread_join(game->thread[2], NULL);
		pthread_join(game->thread[3], NULL);
		free(game->thread);
	    free(game->bullets);
		game->die = 2;
	}
	static int  result = 1;
	if (key_code == KEY_W || key_code == KEY_W2)
		result++;
	else if (key_code == KEY_S || key_code == KEY_S2)
		result--;
	else if (key_code == KEY_ENTER)
	{
		if (result == 1)
		{
			mlx_destroy_window(game->mlx, game->win);
			exit(0);
		}
		else
		{
			game->wlmode = 0;
			game->mode = 0;
			game->die = -1;
			game->my_character.num = -1;
			choiceImagesPut("WebMode", game);
		}
		result = 1;
		return (0);
	}
	else
		return (0);
	if (result < 1)
		result += 2;
	else if (result > 2)
		result -= 2;
	if (result == 1)
		choiceImagesPut("EXIT", game);
	else if (result == 2)
		choiceImagesPut("Continue", game);
	return (0);
}
