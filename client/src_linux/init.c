#include "../header/client.h"

void	game_image_xpm_init(t_game *game)
{
	int	img_width, img_height;

	game->bulletimage = mlx_xpm_file_to_image(game->mlx, \
			"./source/image/xpm/bullet.xpm", &img_width, &img_height);
	game->arrow[0] = mlx_xpm_file_to_image(game->mlx, \
			"./source/image/xpm/UpArrow.xpm", &img_width, &img_height);
	game->arrow[1] = mlx_xpm_file_to_image(game->mlx, \
			"./source/image/xpm/DownArrow.xpm", &img_width, &img_height);

	game->characterImages[0] = mlx_xpm_file_to_image(game->mlx, \
			"./source/image/xpm/Space1_Small.xpm", &img_width, &img_height);
	game->character_x[0] = img_width;
	game->character_y[0] = img_height;

	game->characterImages[1] = mlx_xpm_file_to_image(game->mlx, \
			"./source/image/xpm/Space2_Small.xpm", &img_width, &img_height);
	game->character_x[1] = img_width;
	game->character_y[1] = img_height;
	
	game->characterImages[2] = mlx_xpm_file_to_image(game->mlx, \
			"./source/image/xpm/Space3_Small.xpm", &img_width, &img_height);
	game->character_x[2] = img_width;
	game->character_y[2] = img_height;

	/* 
	game->characterImages[0] = mlx_xpm_file_to_image(game->mlx, \
			"./source/image/xpm/Space1_Big.xpm", &img_width, &img_height);
	game->characterImages[1] = mlx_xpm_file_to_image(game->mlx, \
			"./source/image/xpm/Space1_Small.xpm", &img_width, &img_height);
	game->characterImages[2] = mlx_xpm_file_to_image(game->mlx, \
			"./source/image/xpm/Space2_Big.xpm", &img_width, &img_height);
	game->characterImages[3] = mlx_xpm_file_to_image(game->mlx, \
			"./source/image/xpm/Space2_Small.xpm", &img_width, &img_height);
	game->characterImages[4] = mlx_xpm_file_to_image(game->mlx, \
			"./source/image/xpm/Space3_Big.xpm", &img_width, &img_height);
	game->characterImages[5] = mlx_xpm_file_to_image(game->mlx, \
			"./source/image/xpm/Space3_Small.xpm", &img_width, &img_height);

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
	*/

	game->wlmode = 0;
	game->my_character.num = -1;
	game->mode = 0;
	game->die = -1;
	game->sockfd = -1;
	// game->thread = malloc(sizeof(pthread_t) * 4);
}
