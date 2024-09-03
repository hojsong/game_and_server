/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:01:24 by hojsong           #+#    #+#             */
/*   Updated: 2022/12/22 15:41:01 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_BONUS_H
# define SL_BONUS_H

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
# include <time.h>

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
	void	**chrimg;
	void	**monimg;
	char	**map;
	int		call;
	int		move;
	time_t	mlxtime;
	int		mons;
}	t_game;

void	map_check(char **map);
void	ft_error(int i);
char	**ft_map_create(int fd);

void	check(t_game *game);
t_c		mon_check(char **map, int *mons);
t_c		play_check(char **map);
char	**dfs_mapinit(char **map);
void	allfree(char **smap);

t_c		exit_check(char **map);
int		call_check(char **map);
void	playing_dfs(char **map, int i, int i2);
void	map_check(char **map);
int		wasd_dfs(char **map, int i, int i2);

void	*img_check(char c, t_game *game, int i);
void	mlxstart(t_game *game);
void	mlx_game_init(t_game *game);
void	mlx_put_map(t_game *game, void *mlx, void *win, int mi);
int		*size_of_window(char **map);

int		press_key(int key_code, t_game *game);
void	move_w(t_game *game);
void	move_a(t_game *game);
void	move_s(t_game *game);
void	move_d(t_game *game);

void	exit_game(t_game *game, int i);
int		exit_game2(t_game *game);
void	game_end_chk(t_game *game);
void	move_count_print(int i);
void	move_count(int i);

void	chrimg_set(t_game *game, char s);
void	chrimg_w(t_game *game);
void	chrimg_a(t_game *game);
void	chrimg_s(t_game *game);
void	chrimg_d(t_game *game);

void	monimg_set(t_game *game, char s);
void	monimg_w(t_game *game);
void	monimg_a(t_game *game);
void	monimg_s(t_game *game);
void	monimg_d(t_game *game);

int		mo_m_mv(t_game *game);
int		mv_avail(t_game *game, int rd);
void	mv(t_game *game, int rd);

void	mon_mv_w(t_game *game);
void	mon_mv_a(t_game *game);
void	mon_mv_s(t_game *game);
void	mon_mv_d(t_game *game);

char	*put_mv(t_game *game);
void	set_str(int i, char *str, int size);
int		mv_size(int i);
void	str_put(t_game *game);
#endif
