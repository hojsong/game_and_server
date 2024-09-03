/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:17:42 by hojsong           #+#    #+#             */
/*   Updated: 2022/12/22 15:35:09 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/sl.h"

void	exit_game(t_game *game, int i)
{
	if (i == 1)
		write(1, "Game Over\n", 10);
	if (i == 2)
		write(1, "Game Clear\n", 11);
	mlx_destroy_window(game->mlx, game->win);
	exit(1);
}

int	exit_game2(t_game *game)
{
	write(1, "Game EXIT\n", 10);
	mlx_destroy_window(game->mlx, game->win);
	exit(1);
}

void	move_count_print(int i)
{
	write(1, "Move count : ", 13);
	move_count(i);
	write(1, "\n", 1);
}

void	move_count(int i)
{
	char	a;

	if (i > 9)
	{
		move_count(i / 10);
		a = (i % 10) + '0';
		write(1, &a, 1);
	}
	else
	{
		a = i + '0';
		write(1, &a, 1);
	}
}
