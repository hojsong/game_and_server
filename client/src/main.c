#include "../header/client.h"



int main()
{
	t_game game;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, Window_x, Window_y, "Dodge Bullets");
	game_image_xpm_init(&game);
	mapinit(&game);
	choiceImagesPut("WebMode", &game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &mlxstart, &game);
	mlx_loop(game.mlx);
}