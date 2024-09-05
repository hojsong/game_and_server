/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   image_util.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hojsong <hojsong@student.42seoul.k>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/12/21 16:30:35 by hojsong		   #+#	#+#			 */
/*   Updated: 2022/12/21 19:46:36 by hojsong		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../head/sl_bonus.h"

void	monimg_set(t_game *game, char s)
{
	if (s == 'w')
		monimg_w(game);
	else if (s == 'a')
		monimg_a(game);
	else if (s == 's')
		monimg_s(game);
	else if (s == 'd')
		monimg_d(game);
}

void	monimg_w(t_game *game)
{
	int	img_width;
	int	img_height;

	game->monimg[0] = mlx_xpm_file_to_image(game->mlx, \
			"./images/enemyw.xpm", &img_width, &img_height);
	game->monimg[1] = mlx_xpm_file_to_image(game->mlx, \
			"./images/enemyw2.xpm", &img_width, &img_height);
}

void	monimg_a(t_game *game)
{
	int	img_width;
	int	img_height;

	game->monimg[0] = mlx_xpm_file_to_image(game->mlx, \
			"./images/enemya.xpm", &img_width, &img_height);
	game->monimg[1] = mlx_xpm_file_to_image(game->mlx, \
			"./images/enemya2.xpm", &img_width, &img_height);
}

void	monimg_s(t_game *game)
{
	int	img_width;
	int	img_height;

	game->monimg[0] = mlx_xpm_file_to_image(game->mlx, \
			"./images/enemys.xpm", &img_width, &img_height);
	game->monimg[1] = mlx_xpm_file_to_image(game->mlx, \
			"./images/enemys2.xpm", &img_width, &img_height);
}

void	monimg_d(t_game *game)
{
	int	img_width;
	int	img_height;

	game->monimg[0] = mlx_xpm_file_to_image(game->mlx, \
			"./images/enemyd.xpm", &img_width, &img_height);
	game->monimg[1] = mlx_xpm_file_to_image(game->mlx, \
			"./images/enemyd2.xpm", &img_width, &img_height);
}
