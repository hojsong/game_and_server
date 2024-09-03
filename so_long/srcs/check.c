/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:21:10 by hojsong           #+#    #+#             */
/*   Updated: 2022/12/20 21:50:38 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/sl.h"

void	check(t_game *game)
{
	map_check(game->map);
	game->chr = play_check(game->map);
	game->dore = exit_check(game->map);
	game->call = call_check(game->map);
}

t_c	play_check(char **map)
{
	t_c	chr;
	int	i;
	int	i2;
	int	p;

	p = 0;
	i = 0;
	while (map[i])
	{
		i2 = 0;
		while (map[i][i2])
		{
			if (map[i][i2] == 'P')
			{
				chr.x_p = i2;
				chr.y_p = i;
				p++;
			}
			i2++;
		}
		i++;
	}
	if (p != 1)
		ft_error(3);
	return (chr);
}

char	**dfs_mapinit(char **map)
{
	char	**smap;
	int		ai;
	int		ai2;
	int		i;
	int		i2;

	i = 0;
	i2 = (int)ft_strlen(map[0]);
	while (map[i])
		i++;
	smap = (char **)malloc(sizeof(char *) * (i + 1));
	ai = -1;
	while (++ai < i)
	{
		ai2 = -1;
		smap[ai] = malloc(sizeof(char) * (i2 + 1));
		while (++ai2 < i2)
			smap[ai][ai2] = map[ai][ai2];
		smap[ai][ai2] = '\0';
	}
	smap[ai] = 0;
	return (smap);
}

void	allfree(char **smap)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	while (smap[i2])
		i2++;
	while (i < i2)
	{
		free(smap[i]);
		i++;
	}
	free(smap);
}
