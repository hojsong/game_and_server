#pragma once

//Header
# include "../mlx/mlx.h"
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <math.h>
# include <time.h> 
# include <sys/socket.h>
# include <netinet/in.h>
# include <netinet/ip.h>
// # ifdef __APPLE__
    # include <netinet/ip_var.h> // macOS에서 사용할 수 있는 헤더
// # endif
# include <netinet/ip_icmp.h>
# include <arpa/inet.h>
# include <signal.h>
# include <netdb.h>
# include <regex.h>
# include <ctype.h>

//key and define
# define DEST_PORT 0
# define PACKET_SIZE 64
# define TIMEOUT 1
# define BUF_SIZE 512

# define MAX_LINES 10
# define MAX_STRING_LENGTH 10

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

# define EASY_MODE				30
# define NORMAL_MODE			40
# define HARD_MODE				50

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3

# define KEY_ESC				53

# define KEY_ENTER				36
# define KEY_UP	 				126
# define KEY_LEFT				123
# define KEY_DOWN				125
# define KEY_RIGHT	 			124

# define KEY_BACK				51

# define KEY_Q					12
# define KEY_W					13
# define KEY_E					14
# define KEY_R					15
# define KEY_T					16
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2
# define KEY_F					3
# define KEY_H					4
# define KEY_G					5
# define KEY_Z					6
# define KEY_X					7
# define KEY_C					8
# define KEY_V					9
# define KEY_B					11
# define KEY_N					45
# define KEY_M					56
# define KEY_L					37
# define KEY_K					40
# define KEY_J					38
# define KEY_Y					16
# define KEY_U					32
# define KEY_I					34
# define KEY_O					31
# define KEY_P					35

// struct
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

typedef struct {
    char name[MAX_STRING_LENGTH];
    int score;
} Entry;

typedef struct m_game{
    int             sockfd;
    struct addrinfo *res;
	int				mode;
	int				wlmode;
	int				die;
	int				size;
	pthread_mutex_t	player_mutex;
	t_character 	my_character;
	time_t			startTime;
	time_t			endTime;
	time_t			frameTime;
	void			*win;
	void			*mlx;
	pthread_mutex_t	*die_mutex;
	// pthread_t		*thread;
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
