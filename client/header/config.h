#pragma once

//Header

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

#ifdef __APPLE__
    #include "../mlx_macos/mlx.h"
	#include "key_mac.h"
// #elif defined(_WIN32) || defined(_WIN64)
//     #include "../mlx_window/mlx.h"
// 	#include "key_win.h"
#else
    #include "../mlx_linux/mlx.h"
	#include "key_linux.h"
#endif

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
