#include "../header/client.h"

// void	f()
// {
// 	system("Leaks ./Dodge");
// }

int main()
{
	// atexit(f);
	t_game game;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, Window_x, Window_y, "Dodge Bullets");
	game_image_xpm_init(&game);
    pthread_mutex_init(&game.player_mutex, NULL);
	choiceImagesPut("WebMode", &game);
	mlx_hook(game.win, 2, 1L << 0, &mlxstart, &game);
	mlx_hook(game.win, 3, 1L << 1, &key_release, &game);
	// mlx_key_hook(game.win, &mlxstart, &game);
	mlx_loop_hook(game.mlx, bullet_init_c_d_m_p, &game);
	mlx_loop(game.mlx);
}