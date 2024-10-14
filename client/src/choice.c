#include "../header/client.h"

int	wlmodeChoice(int key_code, t_game *game)
{
	static int  result = 1;
	if (key_code == KEY_W || key_code == KEY_UP)
		result++;
	else if (key_code == KEY_S || key_code == KEY_DOWN)
		result--;
	else if (key_code == KEY_ENTER)
	{
		if (result == 2 && game->sockfd != -1)
		{
			close(game->sockfd);
			game->sockfd = -1;
		}
		else if (result == 1 && game->sockfd == -1)
		{
			socket_create(game);
			if (game->sockfd == -1)
			{
				// Error();
				result = 2;
				choiceImagesPut("LocalMode", game);
				return (0);
			}
		}
		game->wlmode = result;
		choiceImagesPut("Space1_Big", game);
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

	if (key_code == KEY_W || key_code == KEY_UP)
		result++;
	else if (key_code == KEY_S || key_code == KEY_DOWN)
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
	return (0);
}

int	modeChoice(int key_code, t_game *game)
{
	static int  result = 1;
	int	idx;
	if (key_code == KEY_W || key_code == KEY_UP)
		result++;
	else if (key_code == KEY_S || key_code == KEY_DOWN)
		result--;
	else if (key_code == KEY_ENTER)
	{
		game->mode = result;
		game->key[0] = 0;
		game->key[1] = 0;
		game->key[2] = 0;
		game->key[3] = 0;
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
		game->startTime = time(NULL);
		game->frameTime = time(NULL);
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
	static int  result = 2;

	if (key_code == KEY_W || key_code == KEY_UP)
		result++;
	else if (key_code == KEY_S || key_code == KEY_DOWN)
		result--;
	else if (key_code == KEY_ENTER)
	{
		if (result == 1)
		{
			if (game->sockfd != -1)
				close(game->sockfd);
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
		result = 2;
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
