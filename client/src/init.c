#include "../header/client.h"

void	game_image_xpm_init(t_game *game)
{
	int	img_width, img_height, i;

	game->bullets = mlx_xpm_file_to_image(game->mlx, \
			"./source/image/xpm/bullet.xpm", &img_width, &img_height);
	game->arrow[0] = mlx_xpm_file_to_image(game->mlx, \
			"./source/image/xpm/UpArrow.xpm", &img_width, &img_height);
	game->arrow[1] = mlx_xpm_file_to_image(game->mlx, \
			"./source/image/xpm/DownArrow.xpm", &img_width, &img_height);
	game->characterImages[0] = mlx_xpm_file_to_image(game->mlx, \
			"./source/image/xpm/airplane1.xpm", &img_width, &img_height);
	game->characterImages[1] = mlx_xpm_file_to_image(game->mlx, \
			"./source/image/xpm/airplane2.xpm", &img_width, &img_height);
	game->characterImages[2] = mlx_xpm_file_to_image(game->mlx, \
			"./source/image/xpm/airplane3.xpm", &img_width, &img_height);
	game->characterImages[3] = mlx_xpm_file_to_image(game->mlx, \
			"./source/image/xpm/airplane4.xpm", &img_width, &img_height);
	game->characterImages[4] = mlx_xpm_file_to_image(game->mlx, \
			"./source/image/xpm/airplane5.xpm", &img_width, &img_height);
	game->backgraunbd = mlx_xpm_file_to_image(game->mlx, \
			"./source/image/xpm/universeBG.xpm", &img_width, &img_height);
	game->map = malloc(sizeof(char *) * (Window_y + 1));
	while (game->map == NULL)
		game->map = malloc(sizeof(char *) * (Window_y + 1));
	i = 0;
	while (i < Window_y)
	{
		game->map[i] = malloc(sizeof(char) * (Window_x + 1));
		while (game->map[i] == NULL)
			game->map[i] = malloc(sizeof(char) * (Window_x + 1));
		i++;
	}
	game->wlmode = 0;
	game->my_character.num = -1;
	game->mode = 0;
	game->die = 0;
}

void	mapinit(t_game *game)
{
	int	x, y;


	y = 0;
	while (y < Window_y)
	{
		x = 0;
		while (x < Window_x)
		{
			game->map[y][x] = '0';
			x++;
		}
		game->map[y][x] = '\0';
		y++;
	}
}