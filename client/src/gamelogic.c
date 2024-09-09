#include "../header/client.h"

int	key_press(int key_code, t_game *game)
{
	if (game->die != 0)
		return (0);
	if (key_code == KEY_W || key_code == KEY_W2)
		game->key[0] = 1;
	if (key_code == KEY_A || key_code == KEY_A2)
		game->key[1] = 1;
	if (key_code == KEY_S || key_code == KEY_S2)
		game->key[2] = 1;
	if (key_code == KEY_D || key_code == KEY_D2)
		game->key[3] = 1;
	return (0);
}

int	key_release(int key_code, t_game *game)
{
	if (game->die != 0)
		return (0);
	if (key_code == KEY_W || key_code == KEY_W2)
		game->key[0] = 0;
	if (key_code == KEY_A || key_code == KEY_A2)
		game->key[1] = 0;
	if (key_code == KEY_S || key_code == KEY_S2)
		game->key[2] = 0;
	if (key_code == KEY_D || key_code == KEY_D2)
		game->key[3] = 0;
	return (0);
}

void	characterMove(t_game *game)
{
	// wa
	if (game->key[0] == 1 && game->key[1] == 1)
	{
		game->my_character.x -= Player_speed/2;
		game->my_character.y -= Player_speed/2;
	}
	// as
	else if (game->key[1] == 1 && game->key[2] == 1)
	{
		game->my_character.x -= Player_speed/2;
		game->my_character.y += Player_speed/2;
	}
	// sd
	else if (game->key[2] == 1 && game->key[3] == 1)
	{
		game->my_character.x += Player_speed/2;
		game->my_character.y += Player_speed/2;
	}
	// wd
	else if (game->key[3] == 1 && game->key[0] == 1)
	{
		game->my_character.x += Player_speed/2;
		game->my_character.y -= Player_speed/2;
	}
	else if (game->key[0] == 1)
		game->my_character.y -= Player_speed;
	else if (game->key[1] == 1)
		game->my_character.x -= Player_speed;
	else if (game->key[2] == 1)
		game->my_character.y += Player_speed;
	else if (game->key[3] == 1)
		game->my_character.x += Player_speed;
}


void	*bullet_init_c_d_m_p(void *ptr)
{
	t_game	*game;
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
	return (0);
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
	{
		// key_press(key_code, game);
		// mlx_hook(game->win, X_EVENT_KEY_PRESS, 0, &key_press, game);
		// mlx_hook(game->win, X_EVENT_KEY_RELEASE, 0, &key_release, game);
	}
	else
	{
		// if (game->wlmode == 1)
		// 	data = servDataLoad(game);
		// else if (game->wlmode == 2)
		// 	data = localDataLoad(game);
		continue_or_exit(key_code, game);
	}
	return (0);
}