#include "../header/client.h"

void	game_image_xpm_init(void)
{
	int	img_width;
	int	img_height;

	g_game.bullets = mlx_xpm_file_to_image(g_game.mlx, \
			"./source/image/xpm/bullet.xpm", &img_width, &img_height);
	g_game.arrow[0] = mlx_xpm_file_to_image(g_game.mlx, \
			"./source/image/xpm/UpArrow.xpm", &img_width, &img_height);
	g_game.arrow[1] = mlx_xpm_file_to_image(g_game.mlx, \
			"./source/image/xpm/DownArrow.xpm", &img_width, &img_height);
	g_game.characterImages[0] = mlx_xpm_file_to_image(g_game.mlx, \
			"./source/image/xpm/airplane1.xpm", &img_width, &img_height);
	g_game.characterImages[1] = mlx_xpm_file_to_image(g_game.mlx, \
			"./source/image/xpm/airplane2.xpm", &img_width, &img_height);
	g_game.characterImages[2] = mlx_xpm_file_to_image(g_game.mlx, \
			"./source/image/xpm/airplane3.xpm", &img_width, &img_height);
	g_game.characterImages[3] = mlx_xpm_file_to_image(g_game.mlx, \
			"./source/image/xpm/airplane4.xpm", &img_width, &img_height);
	g_game.characterImages[4] = mlx_xpm_file_to_image(g_game.mlx, \
			"./source/image/xpm/airplane5.xpm", &img_width, &img_height);
	g_game.backgraunbd = mlx_xpm_file_to_image(g_game.mlx, \
			"./source/image/xpm/universeBG.xpm", &img_width, &img_height);	
}

void	mapinit(void)
{
	int	x, y;

	while (g_game.map == NULL)
		g_game.map = malloc(sizeof(char *) * (Window_y + 1));
	y = 0;
	while (y < Window_y)
	{
		while (g_game.map[y] == NULL)
			g_game.map[y] = malloc(sizeof(char) * (Window_x + 1));
		x = 0;
		while (x < Window_x)
		{
			g_game.map[y][x] = '\0';
			x++;
		}
		y++;
	}
}