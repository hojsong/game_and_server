#include "../header/client.h"

// static int	num_check(unsigned long num)
// {
// 	unsigned long  x;
// 	int	result;

// 	x = num;
// 	result = 0;
// 	if (x == 0)
// 		return (1);
// 	else if (x < 0)
// 		x *= -1;
// 	while (x)
// 	{
// 		x /= 10;
// 		result++;
// 	}
// 	return (result);
// }

// void	str_put_time(char *str, unsigned long num, int end, int start)
// {
// 	unsigned long 	x;
// 	int				idx;
	
// 	idx = start;
// 	x = num;
// 	if (num < 0)
// 		num *= -1;
// 	while(num != 0 && idx >= 0)
// 	{
// 		str[idx--] = (num % 10) + '0';
// 		num /= 10;
// 	}
// 	while (idx > end && idx >= 0)
// 	{
// 		str[idx--] = '0';
// 	}
// }

// static char	*getStrOfTimegap(unsigned long sec, unsigned long usec, int size)
// {
// 	char	*result;
// 	int		idx;

// 	result = malloc(sizeof(char) * (size + 2));
// 	if (result == NULL)
// 		return (NULL);
// 	idx = num_check(sec);
// 	str_put_time(result, sec, 0, idx);
// 	result[idx++] = '.';
// 	str_put_time(result, usec, idx, size);	
// 	result[size] = 'S';
// 	result[size + 1] = '\0';
// 	return (result);
// }

// static void	time_check(t_game *game, struct timeval now_time)
// {
// 	// char			*str;
// 	int				size;
// 	unsigned long	sec_gap;
// 	unsigned long	usec_gap;

// 	sec_gap = (now_time.tv_sec - game->startTime.tv_sec);
// 	usec_gap = (now_time.tv_usec - game->startTime.tv_usec) / 1000;
// 	size = num_check(sec_gap) + 3;
// 	// str = getStrOfTimegap(sec_gap, usec_gap, size);
// 	// if (str)
// 	// {
// 		// mlx_string_put(game->mlx, game->win, Window_x - (size * 10) , 0, 16777215, str);
// 		// free(str);
// 	// }
// }

static void putGame_view(t_game *game){
	int 			idx;
	// struct timeval	now_time;

	mlx_clear_window(game->mlx, game->win);
	idx = 0;
	while (idx < game->size)
	{
		if (game->bulletimage && game->bullets[idx].x - 2 > 0 && game->bullets[idx].x + 2 < Window_x && game->bullets[idx].y - 2 > 0 && game->bullets[idx].y + 2 < Window_y)
			mlx_put_image_to_window(game->mlx, game->win, game->bulletimage, game->bullets[idx].x - 2, game->bullets[idx].y + 2);
		idx++;
	}
	mlx_put_image_to_window(game->mlx, game->win, \
		game->characterImages[game->my_character.num], \
		game->my_character.x - (game->character_x[game->my_character.num] / 2), \
		game->my_character.y - (game->character_y[game->my_character.num] / 2));
	// gettimeofday(&now_time, NULL);
	// time_check(game, now_time);
}

void    *put_game_ing_image(void *ptr)
{
    t_game *game = (t_game *)ptr;

	if (game->die == 0)
    	putGame_view(game);
    return (0);
}