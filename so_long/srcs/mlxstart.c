/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxstart.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 21:57:14 by hojsong           #+#    #+#             */
/*   Updated: 2024/09/02 12:32:28 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/sl.h"

void	mlxstart(t_game *game)
{
	int		*i;

	if (game->map == NULL)
		return ;
	i = size_of_window(game->map);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, i[1] * 32, i[0] * 32, "so_long");
	game->images = mlx_map_init(game->mlx);
	mlx_put_map(game, game->mlx, game->win);
	mlx_hook(game->win, X_EVENT_KET_RELEASE, 0, &press_key, game);
	mlx_hook(game->win, 17, 0, &exit_game2, game);
	mlx_loop(game->mlx);
	return ;
}

void	**mlx_map_init(void *mlx)
{
	void	**images;
	int		img_width;
	int		img_height;

	images = malloc(sizeof(void *) * 6);
	images[0] = mlx_xpm_file_to_image(mlx, "./images/tail.xpm", \
			&img_width, &img_height);
	images[1] = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", \
			&img_width, &img_height);
	images[2] = mlx_xpm_file_to_image(mlx, "./images/key.xpm", \
			&img_width, &img_height);
	images[3] = mlx_xpm_file_to_image(mlx, "./images/box1.xpm", \
			&img_width, &img_height);
	images[4] = mlx_xpm_file_to_image(mlx, "./images/box2.xpm", \
			&img_width, &img_height);
	images[5] = mlx_xpm_file_to_image(mlx, "./images/users.xpm", \
			&img_width, &img_height);
	return (images);
}

void	mlx_put_map(t_game *game, void *mlx, void *win)
{
	int	i;
	int	i2;
	int	a;

	i = 0;
	while (game->map[i])
	{
		i2 = 0;
		while (game->map[i][i2])
		{
			mlx_put_image_to_window(mlx, win, game->images[0], i2 * 32, i * 32);
			if (game->map[i][i2] != '0')
			{
				a = img_check(game->map[i][i2], game->call);
				mlx_put_image_to_window(mlx, win, \
						game->images[a], i2 * 32, i * 32);
			}
			i2++;
		}
		i++;
	}
}

int	img_check(char c, int call)
{
	if (c == '1')
		return (1);
	else if (c == 'C')
		return (2);
	else if (c == 'E' && call != 0)
		return (3);
	else if (c == 'E' && call == 0)
		return (4);
	else if (c == 'P')
		return (5);
	return (0);
}

int	*size_of_window(char **map)
{
	int	*i;

	i = malloc(sizeof(int) * 2);
	i[0] = 0;
	while (map[i[0]])
		i[0]++;
	i[1] = 0;
	while (map[0][i[1]])
		i[1]++;
	return (i);
}
