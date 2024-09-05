/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   mlx_monmv.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hojsong <hojsong@student.42seoul.k>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/12/21 18:58:07 by hojsong		   #+#	#+#			 */
/*   Updated: 2022/12/21 19:23:22 by hojsong		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../head/sl_bonus.h"

void	mon_mv_w(t_game *game)
{
	int	x;
	int	y;

	x = game->mon.x_p;
	y = game->mon.y_p;
	if (x == game->chr.x_p && y - 1 == game->chr.y_p)
		exit_game(game, 1);
	game->map[y][x] = '0';
	game->map[y - 1][x] = 'M';
	monimg_set(game, 'w');
	game->mon.y_p--;
}

void	mon_mv_a(t_game *game)
{
	int	x;
	int	y;

	x = game->mon.x_p;
	y = game->mon.y_p;
	if (x - 1 == game->chr.x_p && y == game->chr.y_p)
		exit_game(game, 1);
	game->map[y][x] = '0';
	game->map[y][x - 1] = 'M';
	monimg_set(game, 'a');
	game->mon.x_p--;
}

void	mon_mv_s(t_game *game)
{
	int	x;
	int	y;

	x = game->mon.x_p;
	y = game->mon.y_p;
	if (x == game->chr.x_p && y + 1 == game->chr.y_p)
		exit_game(game, 1);
	game->map[y][x] = '0';
	game->map[y + 1][x] = 'M';
	monimg_set(game, 's');
	game->mon.y_p++;
}

void	mon_mv_d(t_game *game)
{
	int	x;
	int	y;

	x = game->mon.x_p;
	y = game->mon.y_p;
	if (x + 1 == game->chr.x_p && y == game->chr.y_p)
		exit_game(game, 1);
	game->map[y][x] = '0';
	game->map[y][x + 1] = 'M';
	monimg_set(game, 'd');
	game->mon.x_p++;
}
