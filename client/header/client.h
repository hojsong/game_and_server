#pragma once

#include "../mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

# define WHITE_COLOR 	16777215

# define Window_x		600
# define Window_y 		600

# define Charactet_x	16
# define Charactet_y	16
# define ARROW_X 		36
# define ARROW_Y 		47

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KET_RELEASE	3

# define KEY_ESC				53
# define KEY_W					13
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2

# define KEY_ENTER				36
# define KEY_W2	 				126
# define KEY_A2					123
# define KEY_S2					125
# define KEY_D2	 				124

typedef struct m_character{
	int		x;
	int		y;
	int		num;
} t_character;

typedef struct m_bullet{
	int		x;
	int		y;
	int		angle;
} t_bullet;

typedef struct m_game{
	int			mode;
	int			wlmode;
	int			die;
	t_character my_character;
	void		*win;
	void		*mlx;
	t_bullet	*bullets;
	time_t		startTime;
	void		*characterImages[5];
	void		*arrow[2];
	void		*bulletimage;
	void		*backgraunbd;
	char		**map;
} t_game;

void    	choiceImagesPut(char *str, t_game *game);
void    	airPlainChoicePut(int result, t_game *game);

int			modeChoice(int key_code, t_game *game);
int			wlmodeChoice(int key_code, t_game *game);
int			airplainChoice(int key_code, t_game *game);
int			continue_or_exit(int key_code, t_game *game);

char		**servDataLoad(t_game game);
char		**localDataLoad(t_game game);

void		mapinit(t_game *game);
void		game_image_xpm_init(t_game *game);

int			mlxstart(int key_code, t_game *game);
