#include "../header/client.h"

int	key_press(int key_code, t_game *game)
{
	if (game->die != 0)
		return (0);
	if (key_code == KEY_W || key_code == KEY_UP)
		game->key[0] = 1;
	if (key_code == KEY_A || key_code == KEY_LEFT)
		game->key[1] = 1;
	if (key_code == KEY_S || key_code == KEY_DOWN)
		game->key[2] = 1;
	if (key_code == KEY_D || key_code == KEY_RIGHT)
		game->key[3] = 1;
	return (0);
}

int	key_release(int key_code, t_game *game)
{
	if (game->die != 0)
		return (0);
	if (key_code == KEY_W || key_code == KEY_UP)
		game->key[0] = 0;
	if (key_code == KEY_A || key_code == KEY_LEFT)
		game->key[1] = 0;
	if (key_code == KEY_S || key_code == KEY_DOWN)
		game->key[2] = 0;
	if (key_code == KEY_D || key_code == KEY_RIGHT)
		game->key[3] = 0;
	return (0);
}

void	characterMove(t_game *game)
{
	// wa
	if (game->key[0] == 1 && game->key[1] == 1 && game->my_character.x > 2 && game->my_character.y > 2)
	{
		game->my_character.x -= sqrt((Player_speed * Player_speed ) / 2);
		game->my_character.y -= sqrt((Player_speed * Player_speed ) / 2);
	}
	// as
	else if (game->key[1] == 1 && game->key[2] == 1 && game->my_character.x > 2 && game->my_character.y < Window_y)
	{
		game->my_character.x -= sqrt((Player_speed * Player_speed ) / 2);
		game->my_character.y += sqrt((Player_speed * Player_speed ) / 2);
	}
	// sd
	else if (game->key[2] == 1 && game->key[3] == 1 && game->my_character.x < Window_x && game->my_character.y < Window_y)
	{
		game->my_character.x += sqrt((Player_speed * Player_speed ) / 2);
		game->my_character.y += sqrt((Player_speed * Player_speed ) / 2);
	}
	// wd
	else if (game->key[3] == 1 && game->key[0] == 1 && game->my_character.x < Window_x && game->my_character.y > 2)
	{
		game->my_character.x += sqrt((Player_speed * Player_speed ) / 2);
		game->my_character.y -= sqrt((Player_speed * Player_speed ) / 2);
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

int	bullet_init_c_d_m_p(void *ptr)
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
	usleep(10000);
	return (0);
}

void all_free(char **results) {
    if (results) {
        for (int i = 0; results[i] != NULL; i++) {
            free(results[i]); // 각 문자열 메모리 해제
        }
        free(results); // 결과 배열 메모리 해제
    }
}

int		calculate_score(t_game *game)
{
	float result;
	
	result = game->endTime - game->startTime;

	// printf("%f\n", result);
	if (game->mode == 1)
		result *= 11;
	if (game->mode == 2)
		result *= 15;
	if (game->mode == 3)
		result *= 19;
	return ((int)result);
}

void	score_LOAD_SAVE_view(int key_code, t_game *game)
{
	char	**str;
	// char	*response;
	int		score;
	static char name[MAX_STRING_LENGTH] = "         ";
	static int	idx = 0;

	if (idx < MAX_STRING_LENGTH - 1)
	{
		if (key_code == KEY_Q)
			name[idx++] = 'Q';
		if (key_code == KEY_W)
			name[idx++] = 'W';
		if (key_code == KEY_E)
			name[idx++] = 'E';
		if (key_code == KEY_R)
			name[idx++] = 'R';
		if (key_code == KEY_T)
			name[idx++] = 'T';
		if (key_code == KEY_Y)
			name[idx++] = 'Y';
		if (key_code == KEY_U)
			name[idx++] = 'U';
		if (key_code == KEY_I)
			name[idx++] = 'I';
		if (key_code == KEY_O)
			name[idx++] = 'O';
		if (key_code == KEY_P)
			name[idx++] = 'P';
		if (key_code == KEY_A)
			name[idx++] = 'A';
		if (key_code == KEY_S)
			name[idx++] = 'S';
		if (key_code == KEY_D)
			name[idx++] = 'D';
		if (key_code == KEY_F)
			name[idx++] = 'F';
		if (key_code == KEY_G)
			name[idx++] = 'G';
		if (key_code == KEY_H)
			name[idx++] = 'H';
		if (key_code == KEY_J)
			name[idx++] = 'J';
		if (key_code == KEY_K)
			name[idx++] = 'K';
		if (key_code == KEY_L)
			name[idx++] = 'L';
		if (key_code == KEY_Z)
			name[idx++] = 'Z';
		if (key_code == KEY_X)
			name[idx++] = 'X';
		if (key_code == KEY_C)
			name[idx++] = 'C';
		if (key_code == KEY_V)
			name[idx++] = 'V';
		if (key_code == KEY_B)
			name[idx++] = 'B';
		if (key_code == KEY_N)
			name[idx++] = 'N';
		if (key_code == KEY_M)
			name[idx++] = 'M';
	}
	if (idx > 0 && key_code == KEY_BACK)
		name[--idx] = ' ';
	if (idx > 0 && key_code == KEY_ENTER)
	{
    	idx = 0;
    	while (idx < game->size)
    	{
	        pthread_mutex_unlock(game->bullets[idx].bullet_mutex);
    	    pthread_mutex_destroy(game->bullets[idx].bullet_mutex);
        	free(game->bullets[idx].bullet_mutex);
        	idx++;
    	}
	    free(game->bullets);
		score = calculate_score(game);
		str = add_and_sort("localdata/ranklist.txt", name, score);
		if (game->wlmode == 1)
		{
			all_free(str);
			str = web_ranking_Load(name, score, game);
			// response = web_ranking_Load(name, score, game);
			// str = split_response(response, '\n');
		}
		rankingPut(str, game);
		game->die = 3;
		idx = 0;
		while (idx < MAX_STRING_LENGTH - 1)
			name[idx++] = ' ';
		idx = 0;
		all_free(str);
		game->die = 3;
	}
	else
		strPut(name, game);
}

void exit_game(t_game *game)
{
	if (game->sockfd != -1)
		close(game->sockfd);
	mlx_destroy_image(game->mlx, game->bulletimage);
	mlx_destroy_image(game->mlx, game->characterImages[0]);
	mlx_destroy_image(game->mlx, game->characterImages[1]);
	mlx_destroy_image(game->mlx, game->characterImages[2]);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	mlxstart(int key_code, t_game *game)
{
	// char	**data;

	// printf("Key_code = %d\n", key_code);
	if (key_code == KEY_ESC)
	{
		exit_game(game);
	}
	if(game->wlmode == 0)
		wlmodeChoice(key_code, game);
	else if(game->my_character.num == -1)
		airplainChoice(key_code, game);
	else if(game->mode == 0)
		modeChoice(key_code, game);
	else if(game->die == 0)
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