#include "../header/client.h"

static char	*xpm_dir_sum(char *dir, char *src_name, char *expr)
{
	char	*result;
	int	 i, len, dir_len, src_name_len, expr_len;

	dir_len = strlen(dir);
	src_name_len = strlen(src_name);
	expr_len = strlen(expr);
	len = dir_len + src_name_len + expr_len;
	i = 0;
	result = malloc(sizeof(char) * (len + 1));
	while (i < dir_len)
	{
		result[i] = dir[i];
		i++;
	}
	while (i - dir_len < src_name_len)
	{
		result[i] = src_name[i - dir_len];
		i++;
	}
	while (i - dir_len - src_name_len < expr_len)
	{
		result[i] = expr[i - dir_len - src_name_len];
		i++;
	}
	result[i] = '\0';
	return (result);
}

void	choiceImagesPut(char *str, t_game *game)
{
	int	 img_width, img_height;
	int	 x0, x1, y0 , y1, y3;
	char	*resource;
	void	*modexpmimage;

	resource = xpm_dir_sum("./source/image/xpm/", str, ".xpm");
	modexpmimage = mlx_xpm_file_to_image(game->mlx, \
			resource, &img_width, &img_height);
	x0 = (Window_x - ARROW_X) / 2;
	x1 = (Window_x / 2) - (img_width / 2);

	y3 = (Window_y / 2) - (img_height / 2);
	y0 = (Window_y / 2) + (img_height / 2) + 20;
	y1 = (Window_y / 2) - (img_height / 2) - 20 - ARROW_Y;
	free(resource);
	// mlx_put_image_to_window(game->mlx, game->win, game->backgraunbd, 0, 0);
	mlx_clear_window(game->mlx, game->win);
	mlx_put_image_to_window(game->mlx, game->win, game->arrow[1], x0, y0);
	mlx_put_image_to_window(game->mlx, game->win, game->arrow[0], x0, y1);
	if (modexpmimage)
	{
		mlx_put_image_to_window(game->mlx, game->win, modexpmimage, x1, y3);
		mlx_destroy_image(game->mlx, modexpmimage);
	}
}

void	airPlainChoicePut(int result, t_game *game)
{
	int	 x0, x1, y0 , y1, y3;

	x0 = (Window_x - ARROW_X) / 2;
	x1 = (Window_x - Charactet_x) / 2;

	y0 = (Window_y / 2) + 200;
	y1 = (Window_y / 2) - 200 - ARROW_Y;
	y3 = (Window_y - Charactet_y) / 2;
	
	// mlx_put_image_to_window(game->mlx, game->win, game->backgraunbd, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->arrow[1], x0, y0);
	mlx_put_image_to_window(game->mlx, game->win, game->arrow[0], x0, y1);
	if (game->characterImages[result])
		mlx_put_image_to_window(game->mlx, game->win, game->characterImages[result * 2], x1, y3);
}

void	strPut(char *str, t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	mlx_string_put(game->mlx, game->win, 10 , (Window_y / 2) + 90, 16777215, "Please enter your nickname");
	mlx_string_put(game->mlx, game->win, 10 , (Window_y / 2) - 10 , 16777215, str);
	mlx_string_put(game->mlx, game->win, 10 , (Window_y / 2) - 110, 16777215, "When finished entering, please press Enter.");
}

void	rankingPut(char **str, t_game *game)
{
	int idx;

	mlx_clear_window(game->mlx, game->win);
	mlx_string_put(game->mlx, game->win, (Window_x / 2) - (7 * 3) , 10, 16777215, "Ranking");
	idx = 0;
	while (idx < MAX_LINES && str[idx])
	{
		mlx_string_put(game->mlx, game->win, 10 , 20 + (idx * 15) , 16777215, str[idx]);
		idx++;
	}
	mlx_string_put(game->mlx, game->win, (Window_x / 2) - ((35 * 3) + 20) , Window_y - 10, 16777215, "If confirmed, please enter any key.");
}