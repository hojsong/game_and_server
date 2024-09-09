#pragma once

# include "../mlx/mlx.h"
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <math.h>
# include <time.h> 

# define PI 3.14159265358979323846
# define FRAME 16660
# define DISTANCE 16
# define WHITE_COLOR 	16777215
# define Player_speed	3
# define Window_x		400
# define Window_y 		400

# define Charactet_x	16
# define Charactet_y	16
# define ARROW_X 		36
# define ARROW_Y 		47

# define EASY_MODE				20
# define NORMAL_MODE			30
# define HARD_MODE				40

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3

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
	double	x;
	double	y;
	double	angle;
	double	speed;
	pthread_mutex_t	*bullet_mutex;
} t_bullet;

typedef struct m_game{
	int				mode;
	int				wlmode;
	int				die;
	int				size;
	pthread_mutex_t	player_mutex;
	t_character 	my_character;
	struct timeval	startTime;
	time_t	frameTime;
	void			*win;
	void			*mlx;
	pthread_mutex_t	*die_mutex;
	pthread_t		*thread;
	// pthread_t		collision_decision;
	t_bullet		*bullets;
	int				key[4];
	int				character_x[3];
	int				character_y[3];
	void			*characterImages[3];
	void			*arrow[2];
	void			*bulletimage;
	// void		*characterImages[6];
	// void		*characterImages[5];
	// void		*backgraunbd;
} t_game;

void		choiceImagesPut(char *str, t_game *game);
void		airPlainChoicePut(int result, t_game *game);

int			modeChoice(int key_code, t_game *game);
int			wlmodeChoice(int key_code, t_game *game);
int			airplainChoice(int key_code, t_game *game);
int			continue_or_exit(int key_code, t_game *game);

char		**servDataLoad(t_game game);
char		**localDataLoad(t_game game);

void		mapinit(t_game *game);
void		game_image_xpm_init(t_game *game);

int			mlxstart(int key_code, t_game *game);

void	*bullet_init_c_d_m_p(void *ptr);

int     bulletOfMode(t_game *game);
void	*bullets_create_destroy(void *ptr);

void	*bullets_movement(void *ptr);

void	*space_bullets_collision_decision(void *ptr);

void    *put_game_ing_image(void *ptr);


int	key_release(int key_code, t_game *game);

int	key_press(int key_code, t_game *game);
