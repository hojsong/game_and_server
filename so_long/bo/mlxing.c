/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:29:08 by hojsong           #+#    #+#             */
/*   Updated: 2024/09/02 12:38:06 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/sl_bonus.h"

int	press_key(int key_code, t_game *game)
{
	clock_t	kc;

	printf("%d\n", key_code);
	kc = clock();
	if (key_code == KEY_ESC)
		exit_game(game, 1);
	else if (key_code == KEY_W)
		move_w(game);
	else if (key_code == KEY_A)
		move_a(game);
	else if (key_code == KEY_S)
		move_s(game);
	else if (key_code == KEY_D)
		move_d(game);
	game_end_chk(game);
	if (kc % 10000 >= 500)
		mlx_put_map(game, game->mlx, game->win, 1);
	else
		mlx_put_map(game, game->mlx, game->win, 0);
	return (0);
}

void	move_w(t_game *game)
{
	int	i;
	int	i2;

	i = game->chr.y_p;
	i2 = game->chr.x_p;
	if (game->map[i - 1][i2] == '1')
		return ;
	if (game->map[i - 1][i2] == 'C')
		game->call--;
	if (i == game->dore.y_p && i2 == game->dore.x_p)
		game->map[i][i2] = 'E';
	else
		game->map[i][i2] = '0';
	game->map[i - 1][i2] = 'P';
	game->chr.y_p--;
	game->move++;
	chrimg_set(game, 'w');
	move_count_print(game->move);
}

void	move_a(t_game *game)
{
	int	i;
	int	i2;

	i = game->chr.y_p;
	i2 = game->chr.x_p;
	if (game->map[i][i2 - 1] == '1')
		return ;
	if (game->map[i][i2 - 1] == 'C')
		game->call--;
	if (i == game->dore.y_p && i2 == game->dore.x_p)
		game->map[i][i2] = 'E';
	else
		game->map[i][i2] = '0';
	game->map[i][i2 - 1] = 'P';
	game->chr.x_p--;
	game->move++;
	chrimg_set(game, 'a');
	move_count_print(game->move);
}

void	move_s(t_game *game)
{
	int	i;
	int	i2;

	i = game->chr.y_p;
	i2 = game->chr.x_p;
	if (game->map[i + 1][i2] == '1')
		return ;
	if (game->map[i + 1][i2] == 'C')
		game->call--;
	if (i == game->dore.y_p && i2 == game->dore.x_p)
		game->map[i][i2] = 'E';
	else
		game->map[i][i2] = '0';
	game->map[i + 1][i2] = 'P';
	game->chr.y_p++;
	game->move++;
	chrimg_set(game, 's');
	move_count_print(game->move);
}

void	move_d(t_game *game)
{
	int	i;
	int	i2;

	i = game->chr.y_p;
	i2 = game->chr.x_p;
	if (game->map[i][i2 + 1] == '1')
		return ;
	if (game->map[i][i2 + 1] == 'C')
		game->call -= 1;
	if (i == game->dore.y_p && i2 == game->dore.x_p)
		game->map[i][i2] = 'E';
	else
		game->map[i][i2] = '0';
	game->map[i][i2 + 1] = 'P';
	game->chr.x_p++;
	game->move++;
	chrimg_set(game, 'd');
	move_count_print(game->move);
}
