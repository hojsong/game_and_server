/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:30:35 by hojsong           #+#    #+#             */
/*   Updated: 2022/12/21 18:46:27 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/sl_bonus.h"

void	chrimg_set(t_game *game, char s)
{
	if (s == 'w')
		chrimg_w(game);
	else if (s == 'a')
		chrimg_a(game);
	else if (s == 's')
		chrimg_s(game);
	else if (s == 'd')
		chrimg_d(game);
}

void	chrimg_w(t_game *game)
{
	int	img_width;
	int	img_height;

	game->chrimg[0] = mlx_xpm_file_to_image(game->mlx, \
			"./images/userw.xpm", &img_width, &img_height);
	game->chrimg[1] = mlx_xpm_file_to_image(game->mlx, \
			"./images/userw2.xpm", &img_width, &img_height);
}

void	chrimg_a(t_game *game)
{
	int	img_width;
	int	img_height;

	game->chrimg[0] = mlx_xpm_file_to_image(game->mlx, \
			"./images/usera.xpm", &img_width, &img_height);
	game->chrimg[1] = mlx_xpm_file_to_image(game->mlx, \
			"./images/usera2.xpm", &img_width, &img_height);
}

void	chrimg_s(t_game *game)
{
	int	img_width;
	int	img_height;

	game->chrimg[0] = mlx_xpm_file_to_image(game->mlx, \
			"./images/users.xpm", &img_width, &img_height);
	game->chrimg[1] = mlx_xpm_file_to_image(game->mlx, \
			"./images/users2.xpm", &img_width, &img_height);
}

void	chrimg_d(t_game *game)
{
	int	img_width;
	int	img_height;

	game->chrimg[0] = mlx_xpm_file_to_image(game->mlx, \
			"./images/userd.xpm", &img_width, &img_height);
	game->chrimg[1] = mlx_xpm_file_to_image(game->mlx, \
			"./images/userd2.xpm", &img_width, &img_height);
}
