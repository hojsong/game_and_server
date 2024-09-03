#pragma once

#include "../mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

# define WHITE_COLOR 	16777215

# define Window_x		860
# define Window_y 		860

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

# define KEY_ENTER		36
# define KEY_W2	 126
# define KEY_A2	 123
# define KEY_S2	 125
# define KEY_D2	 124

typedef struct m_character{
	int		x;
	int		y;
	void	*image;
} t_character;

typedef struct m_bullet{
	int		x;
	int		y;
	int		angle;
} t_bullet;

typedef struct m_game{
	int			mode;
	int	wlmode;
	int	die;
	t_character *my_character;
	void		*win;
	void		*mlx;
	t_bullet	*bullets;
	void		*characterImages[5];
	void		*arrow[2];
	void		*bulletimage;
	void		*backgraunbd;
	char		**map;
} t_game;

t_game g_game;

void    	choiceImagesPut(char *str);
void    	airPlainChoicePut(int result);

void		modeChoice(int key_code);
void		wlmodeChoice(int key_code);
void		airplainChoice(int key_code);
void		continue_or_exit(int key_code);

char		**servDataLoad(void);
char		**localDataLoad(void);

void	mapinit(void);
void	game_image_xpm_init(void);
