#pragma once

# include "config.h"

void		game_image_xpm_init(t_game *game);
// void		mapinit(t_game *game);
char	    **split_response(char const *s, char c);
void        exit_game(t_game *game);

void		choiceImagesPut(char *str, t_game *game);
void		airPlainChoicePut(int result, t_game *game);
void		strPut(char *str, t_game *game);
void		rankingPut(char **str, t_game *game);

int			modeChoice(int key_code, t_game *game);
int			wlmodeChoice(int key_code, t_game *game);
int			airplainChoice(int key_code, t_game *game);
int			continue_or_exit(int key_code, t_game *game);

int			mlxstart(int key_code, t_game *game);
int			bullet_init_c_d_m_p(void *ptr);
int     	bulletOfMode(t_game *game);
void		*bullets_create_destroy(void *ptr);
void		*bullets_movement(void *ptr);
void		*space_bullets_collision_decision(void *ptr);
void    	*put_game_ing_image(void *ptr);

int		key_release(int key_code, t_game *game);
int		key_press(int key_code, t_game *game);

char**	add_and_sort(const char *file_path, const char *name, int score);

void    socket_create(t_game *game);
char**  web_ranking_Load(char *name, int score, t_game *game);
