# CC = cc
# CFLAGS = -Wall -Wextra -Werror -MMD -MP
# ADDFLAGS = 
# # -fsanitize=address -g3
# # -DGL_SILENCE_DEPRECATION -Wno-unused-parameter -Wno-unused-but-set-variable

# HEAD = header
# NAME = Dodge

# # OS 감지
# OS := $(shell uname)
# SRC_DIR = ./src_window
# MLX_DIR = ./mlx_linuxwindow
# MLX_NAME = libmlx.a

# # MacOS 환경
# ifeq ($(OS), Darwin)
#     SRC_DIR = ./src_macos
#     MLX_DIR = ./mlx_macos
#     ADDFLAGS += -framework OpenGL -framework AppKit
# # Windows 환경 (uname이 Windows를 감지 못하는 경우에 대비)
# else ifdef ComSpec
#     SRC_DIR = ./src_window
#     MLX_DIR = ./mlx_windows
#     ADDFLAGS += -lopengl32 -lgdi32
# # Linux 환경
# else ifeq ($(OS), Linux)
#     SRC_DIR = ./src_window
#     MLX_DIR = ./mlx_linuxwindow
#     ADDFLAGS += -lGL -lGLU
# endif

# SRC_FILES = choice.c \
#             gamelogic.c \
#             imagePut.c \
#             init.c \
#             local.c \
#             main.c \
#             web.c \
#             response.c \
#             thread.c \
#             thread2.c \
#             thread3.c \
#             thread4.c 

# SRC = $(addprefix $(SRC_DIR)/,$(SRC_FILES))
# OBJ = $(SRC:.c=.o)

# all: $(MLX_NAME) $(NAME)

# .c.o:
# 	$(CC) $(CFLAGS) -I $(HEAD) -c $< -o $@ 

# $(MLX_NAME):
# 	$(MAKE) -C $(MLX_DIR)

# $(NAME): $(OBJ) $(MLX_DIR)/$(MLX_NAME)
# 	$(CC) $(CFLAGS) -I $(HEAD) -L$(MLX_DIR) -lmlx $(ADDFLAGS) -lm -o $(NAME) $(OBJ)

# clean:
# 	rm -rf $(OBJ) $(SRC_DIR)/*.d
# 	$(MAKE) -C $(MLX_DIR) clean

# fclean: clean
# 	rm -rf $(NAME) $(SRC_DIR)/*.o
# 	$(MAKE) -C $(MLX_DIR) clean

# re: fclean all

# .PHONY: all re clean fclean

CC = cc
CFLAG = -Wall -Wextra -Werror -MMD -MP
ADDFLAG = 
ADDFLAG2 = 
# -fsanitize=address -g3
#  -DGL_SILENCE_DEPRECATION -Wno-unused-parameter -Wno-unused-but-set-variable

HEAD = header
NAME = Dodge

OS := $(shell uname)

ifeq ($(OS), Darwin)
    # macOS
    SRC_DIR = ./src_macos
	MLX_DIR = ./mlx_macos
	ADDFLAG += -framework OpenGL -framework AppKit
# else ifeq ($(OS), Windows_NT)
#     # Windows
#     SRC_DIR = ./src_window
# 	MLX_DIR = ./mlx_linux
# 	ADDFLAG += -lGL -lGLU
# 	ADDFLAG2 += -lX11 -lXext -lXrandr -lXrender -lm
else ifeq ($(OS), Linux)
    # Linux
	SRC_DIR = ./src_linux
	MLX_DIR = ./mlx_linux
	ADDFLAG += -lGL -lGLU
	ADDFLAG2 += -lX11 -lXext -lXrandr -lXrender -lm
endif

# SRC_DIR = ./src
SRC_FILES = choice.c \
            gamelogic.c \
            imagePut.c \
            init.c \
            local.c \
            main.c \
            web.c \
			response.c \
			thread.c \
			thread2.c \
			thread3.c \
			thread4.c 

# MLX_DIR = ./mlx
MLX_NAME = libmlx.a

# MLX_SRC는 이제 필요하지 않으므로 제거
SRC = $(addprefix $(SRC_DIR)/,$(SRC_FILES))
OBJ = $(SRC:.c=.o)

# 모든: 명령어는 libmlx.a를 빌드하기 위해 mlx 폴더의 Makefile을 실행
all : $(MLX_NAME) $(NAME)

.c.o :
	$(CC) $(CFLAG) -I $(HEAD) -c $< -o $@

$(MLX_NAME):
	$(MAKE) -C $(MLX_DIR)

$(NAME) : $(OBJ) $(MLX_DIR)/$(MLX_NAME)
	$(CC) $(CFLAG) -I $(HEAD) -L$(MLX_DIR) $(ADDFLAG) -o $(NAME) $(OBJ) -lmlx $(ADDFLAG2)

# 오타 수정: $(OBJS)를 $(OBJ)로 수정
clean :
	rm -rf $(OBJ) $(SRC_DIR)/*.d $(SRC_DIR)/*.o
	$(MAKE) -C $(MLX_DIR) clean

fclean : clean
	rm -rf $(NAME)
	$(MAKE) -C $(MLX_DIR) clean

re : fclean all


.PHONY : all re clean fclean bonus