/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   check2.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hojsong <hojsong@student.42seoul.k>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/12/19 19:41:22 by hojsong		   #+#	#+#			 */
/*   Updated: 2022/12/20 21:50:17 by hojsong		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../head/sl.h"

void	map_check(char **map)
{
	int	i;
	int	i2;
	int	size;

	i = 0;
	size = (int)ft_strlen(map[i]);
	while (map[i])
	{
		if (i == 0 || map[i + 1] == 0)
		{
			i2 = -1;
			while (++i2 < size)
				if (map[i][i2] != '1')
					ft_error(3);
		}
		else
		{
			if (map[i][0] != '1' || map[i][size - 1] != '1')
				ft_error(3);
		}
		if (map[i][size] != '\0')
			ft_error(3);
		i++;
	}
}

t_c	exit_check(char **map)
{
	t_c	dore;
	int	i;
	int	i2;
	int	e;

	e = 0;
	i = -1;
	while (map[++i])
	{
		i2 = -1;
		while (map[i][++i2])
		{
			if (map[i][i2] == 'E')
			{
				playing_dfs(map, i, i2);
				dore.x_p = i2;
				dore.y_p = i;
				e++;
			}
		}
	}
	if (e != 1)
		ft_error(3);
	return (dore);
}

int	call_check(char **map)
{
	int	i;
	int	i2;
	int	c;

	c = 0;
	i = 0;
	while (map[i])
	{
		i2 = 0;
		while (map[i][i2])
		{
			if (map[i][i2] == 'C')
			{
				playing_dfs(map, i, i2);
				c++;
			}
			i2++;
		}
		i++;
	}
	if (c == 0)
		ft_error(3);
	return (c);
}

void	playing_dfs(char **map, int i, int i2)
{
	int		x;
	char	**smap;

	smap = dfs_mapinit(map);
	x = wasd_dfs(smap, i, i2);
	allfree(smap);
	if (x == 0)
		ft_error(3);
}

int	wasd_dfs(char **map, int i, int i2)
{
	int	x;

	x = 0;
	map[i][i2] = '1';
	if (map[i - 1][i2] == 'P')
		return (1);
	else if (map[i][i2 - 1] == 'P')
		return (1);
	else if (map[i + 1][i2] == 'P')
		return (1);
	else if (map[i][i2 + 1] == 'P')
		return (1);
	if (map[i - 1][i2] != '1' && x == 0)
		x = wasd_dfs(map, i - 1, i2);
	if (map[i][i2 - 1] != '1' && x == 0)
		x = wasd_dfs(map, i, i2 - 1);
	if (map[i + 1][i2] != '1' && x == 0)
		x = wasd_dfs(map, i + 1, i2);
	if (map[i][i2 + 1] != '1' && x == 0)
		x = wasd_dfs(map, i, i2 + 1);
	if (x == 1)
		return (1);
	return (0);
}
