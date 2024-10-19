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

#ifdef __APPLE__
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <netinet/ip.h>
    #include "../mlx_macos/mlx.h"
	#include <arpa/inet.h>
	#include "key_mac.h"
	#include <netinet/ip_icmp.h>
	#include <netdb.h>
	#include <regex.h>
#elif defined(_WIN32) || defined(_WIN64)
	#include <SDL.h>
	// #include <SDL_image.h>
	// #include <SDL_ttf.h>
	// #include <SDL2/SDL.h>
	// #include <SDL2/SDL_image.h>
	// #include <SDL2/SDL_ttf.h>
	#include <winsock2.h> // Windows 소켓 헤더
	#include <ws2tcpip.h> // IP 주소 변환 함수
	#include <fcntl.h> // for _open
	#include <io.h> // for _setmode
#else
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <netinet/ip.h>
    #include "../mlx_linux/mlx.h"
	#include <netinet/ip_icmp.h>
	#include <netdb.h>
	#include <arpa/inet.h>
	#include "key_linux.h"
	#include <regex.h>
#endif

#include <signal.h>
#include <ctype.h>

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
#ifdef __APPLE__
	pthread_mutex_t	*bullet_mutex;
#elif defined(_WIN32) || defined(_WIN64)
	SDL_mutex *bullet_mutex;
#else
	pthread_mutex_t	*bullet_mutex;
#endif
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
#ifdef __APPLE__
	void			*win;
	void			*mlx;
#elif defined(_WIN32) || defined(_WIN64)
	SDL_Window *win;
	SDL_Renderer *renderer;
#else
	void			*win;
	void			*mlx;
#endif
	// void		*characterImages[6];
	// void		*characterImages[5];
	// void		*backgraunbd;
} t_game;
