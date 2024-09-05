/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   mlxing.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hojsong <hojsong@student.42seoul.k>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/12/20 18:29:08 by hojsong		   #+#	#+#			 */
/*   Updated: 2022/12/20 21:47:58 by hojsong		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../head/sl.h"

int	press_key(int key_code, t_game *game)
{
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
	if (game->chr.y_p == game->dore.y_p && \
			game->chr.x_p == game->dore.x_p && game->call == 0)
		exit_game(game, 2);
	mlx_put_map(game, game->mlx, game->win);
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
	move_count_print(game->move);
}
