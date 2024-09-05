/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   sl.h											   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hojsong <hojsong@student.42seoul.k>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/12/15 21:01:24 by hojsong		   #+#	#+#			 */
/*   Updated: 2022/12/22 15:32:53 by hojsong		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef SL_H
# define SL_H

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KET_RELEASE	3

# define KEY_ESC				53
# define KEY_W					13
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "./get_next_line.h"
# include <mlx.h>

typedef struct s_cter
{
	int		x_p;
	int		y_p;
}	t_c;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_c		chr;
	t_c		dore;
	t_c		mon;
	void	**images;
	char	**map;
	int		call;
	int		move;
}	t_game;

void	map_check(char **map);
void	ft_error(int i);
char	**ft_map_create(int fd);

void	check(t_game *game);
t_c		play_check(char **map);
char	**dfs_mapinit(char **map);
void	allfree(char **smap);

t_c		exit_check(char **map);
int		call_check(char **map);
void	playing_dfs(char **map, int i, int i2);
void	map_check(char **map);
int		wasd_dfs(char **map, int i, int i2);

int		img_check(char c, int call);
void	mlxstart(t_game *game);
void	**mlx_map_init(void *mlx);
void	mlx_put_map(t_game *game, void *mlx, void *win);
int		*size_of_window(char **map);

int		press_key(int key_code, t_game *game);
void	move_w(t_game *game);
void	move_a(t_game *game);
void	move_s(t_game *game);
void	move_d(t_game *game);

void	exit_game(t_game *game, int i);
int		exit_game2(t_game *game);
void	move_count_print(int i);
void	move_count(int i);
#endif
