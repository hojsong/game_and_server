#include "../header/client.h"



int main()
{
	t_game game;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, Window_x, Window_y, "Dodge Bullets");
	game_image_xpm_init(&game);
    pthread_mutex_init(&game.player_mutex, NULL);
	// pthread_create(&game.thread[3], NULL, \
	// 		put_game_ing_image, (void *)&game);
	choiceImagesPut("WebMode", &game);
	// mlx_hook(&game.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	// mlx_hook(&game.win, X_EVENT_KEY_RELEASE, 0, &key_release, & game);
	mlx_key_hook(game.win, &mlxstart, &game);
	mlx_loop_hook(game.mlx, bullet_init_c_d_m_p, &game);
	mlx_loop(game.mlx);
}