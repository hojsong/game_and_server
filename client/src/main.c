#include "../header/client.h"

int main()
{
	t_game game;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, Window_x, Window_y, "Dodge Bullets");
	game_image_xpm_init(&game);
	while(1)
	{
		mapinit(&game);
		mlxstart(game);
	}
}