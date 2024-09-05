#include "../header/client.h"

void	gaming(int key_code, t_character *player, pthread_mutex_t *player_mutex)
{
	pthread_mutex_lock(player_mutex);
	if (player->y < Window_y && (key_code == KEY_W || key_code == KEY_W2))
		player->y += Player_speed;
	if (player->y > 0 && (key_code == KEY_S || key_code == KEY_S2))
		player->y -= Player_speed;
	if (player->x > 0 && (key_code == KEY_A || key_code == KEY_A2))
		player->x -= Player_speed;
	if (player->x < Window_x && (key_code == KEY_D || key_code == KEY_D2))
		player->x += Player_speed;
	pthread_mutex_unlock(player_mutex);
}


int	mlxstart(int key_code, t_game *game)
{
	// char	**data;

	if(game->wlmode == 0)
		wlmodeChoice(key_code, game);
	else if(game->my_character.num == -1)
		airplainChoice(key_code, game);
	else if(game->mode == 0)
		modeChoice(key_code, game);
	else if(game->die == 0)
		gaming(key_code, &game->my_character, &game->player_mutex);
	else
	{
		choiceImagesPut("EXIT", game);
		// if (game->wlmode == 1)
		// 	data = servDataLoad(game);
		// else if (game->wlmode == 2)
		// 	data = localDataLoad(game);
		continue_or_exit(key_code, game);
	}
	return (0);
}