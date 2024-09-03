/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxstart.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 21:57:14 by hojsong           #+#    #+#             */
/*   Updated: 2022/12/22 15:38:50 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/sl_bonus.h"

void	mlxstart(t_game *game)
{
	int		*i;

	if (game->map == NULL)
		return ;
	game->mlxtime = time(0);
	i = size_of_window(game->map);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, i[1] * 32, i[0] * 32, "so_long");
	mlx_game_init(game);
	mlx_put_map(game, game->mlx, game->win, 0);
	mlx_hook(game->win, X_EVENT_KET_RELEASE, 0, &press_key, game);
	mlx_hook(game->win, 17, 0, &exit_game2, game);
	mlx_loop_hook(game->mlx, mo_m_mv, game);
	mlx_loop(game->mlx);
	return ;
}

void	mlx_game_init(t_game *game)
{
	int	img_width;
	int	img_height;

	game->images = malloc(sizeof(void *) * 5);
	game->images[0] = mlx_xpm_file_to_image(game->mlx, \
			"./images/tail.xpm", &img_width, &img_height);
	game->images[1] = mlx_xpm_file_to_image(game->mlx, \
			"./images/wall.xpm", &img_width, &img_height);
	game->images[2] = mlx_xpm_file_to_image(game->mlx, \
			"./images/key.xpm", &img_width, &img_height);
	game->images[3] = mlx_xpm_file_to_image(game->mlx, \
			"./images/box1.xpm", &img_width, &img_height);
	game->images[4] = mlx_xpm_file_to_image(game->mlx, \
			"./images/box2.xpm", &img_width, &img_height);
	game->chrimg = malloc(sizeof(void *) * 2);
	game->chrimg[0] = mlx_xpm_file_to_image(game->mlx, \
			"./images/users.xpm", &img_width, &img_height);
	game->chrimg[1] = mlx_xpm_file_to_image(game->mlx, \
			"./images/users2.xpm", &img_width, &img_height);
	game->monimg = malloc(sizeof(void *) * 2);
	game->monimg[0] = mlx_xpm_file_to_image(game->mlx, \
			"./images/enemys.xpm", &img_width, &img_height);
	game->monimg[1] = mlx_xpm_file_to_image(game->mlx, \
			"./images/enemys2.xpm", &img_width, &img_height);
}

void	mlx_put_map(t_game *game, void *mlx, void *win, int mi)
{
	int		i;
	int		i2;
	void	*img;

	i = 0;
	while (game->map[i])
	{
		i2 = 0;
		while (game->map[i][i2])
		{
			mlx_put_image_to_window(mlx, win, game->images[0], i2 * 32, i * 32);
			if (game->map[i][i2] != '0')
			{
				img = img_check(game->map[i][i2], game, mi);
				mlx_put_image_to_window(mlx, win, img, i2 * 32, i * 32);
			}
			i2++;
		}
		i++;
	}
	str_put(game);
}

void	*img_check(char c, t_game *game, int i)
{
	if (c == '1')
		return (game->images[1]);
	else if (c == 'C')
		return (game->images[2]);
	else if (c == 'E' && game->call != 0)
		return (game->images[3]);
	else if (c == 'E' && game->call == 0)
		return (game->images[4]);
	else if (c == 'P')
	{
		if (i == 0)
			return (game->chrimg[0]);
		else
			return (game->chrimg[1]);
	}
	else if (c == 'M')
	{
		if (i == 0)
			return (game->monimg[0]);
		else
			return (game->monimg[1]);
	}
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
