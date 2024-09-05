/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   mlxmon.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hojsong <hojsong@student.42seoul.k>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/12/21 17:21:21 by hojsong		   #+#	#+#			 */
/*   Updated: 2022/12/22 15:43:23 by hojsong		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../head/sl_bonus.h"

int	mo_m_mv(t_game *game)
{
	time_t		mt;
	clock_t		mc;
	static int	rd;

	while (!mv_avail(game, rd))
		rd = rand() % 4;
	mc = clock();
	mt = time(0);
	if (mc % 20000 < 10000 && (mt - game->mlxtime) / 1)
	{
		game->mlxtime = time(0);
		if (game->mons > 0)
			mv(game, rd);
		mlx_put_map(game, game->mlx, game->win, 0);
	}
	else if (mc % 20000 >= 10000 && (mt - game->mlxtime) / 1)
		mlx_put_map(game, game->mlx, game->win, 1);
	return (0);
}

int	mv_avail(t_game *game, int rd)
{
	if (rd == 0)
	{
		if (game->map[game->mon.y_p - 1][game->mon.x_p] == '0'\
				|| game->map[game->mon.y_p - 1][game->mon.x_p] == 'P')
			return (1);
	}
	else if (rd == 1)
	{
		if (game->map[game->mon.y_p][game->mon.x_p - 1] == '0'\
				|| game->map[game->mon.y_p][game->mon.x_p - 1] == 'P')
			return (1);
	}
	else if (rd == 2)
	{
		if (game->map[game->mon.y_p + 1][game->mon.x_p] == '0'\
				|| game->map[game->mon.y_p + 1][game->mon.x_p] == 'P')
			return (1);
	}
	else if (rd == 3)
	{
		if (game->map[game->mon.y_p][game->mon.x_p + 1] == '0'\
				|| game->map[game->mon.y_p][game->mon.x_p + 1] == 'P')
			return (1);
	}
	return (0);
}

void	mv(t_game *game, int rd)
{
	if (rd == 0)
		mon_mv_w(game);
	else if (rd == 1)
		mon_mv_a(game);
	else if (rd == 2)
		mon_mv_s(game);
	else if (rd == 3)
		mon_mv_d(game);
}
