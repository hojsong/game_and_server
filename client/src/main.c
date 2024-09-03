#include "../header/client.h"

int main()
{
	g_game.mlx = mlx_init();
	g_game.win = mlx_new_window(g_game.mlx, Window_x, Window_y, "Dodge Bullets");
	game_image_xpm_init();
	while(1)
	{
		mapinit();
		mlxstart();
	}
}