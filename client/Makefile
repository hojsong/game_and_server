CC = cc
CFLAG = -Wall -Wextra -Werror -MMD -MP
ADDFLAG = 
ADDFLAG2 = 
# -fsanitize=address -g3
#  -DGL_SILENCE_DEPRECATION -Wno-unused-parameter -Wno-unused-but-set-variable

HEAD = header
NAME = Dodge

OS := Windows_NT
# OS := $(shell uname)

ifeq ($(OS), Darwin)
    # macOS
    SRC_DIR = ./src
	MLX_DIR = ./mlx_macos
	ADDFLAG += -framework OpenGL -framework AppKit
else ifeq ($(OS), Linux)
    # Linux
	SRC_DIR = ./src
	MLX_DIR = ./mlx_linux
	ADDFLAG += -lGL -lGLUma
	ADDFLAG2 += -lX11 -lXext -lXrandr -lXrender -lm
else ifeq ($(OS), Windows_NT)
    # Windows
	CC = gcc
    SRC_DIR = ./src_window
	MLX_DIR = ./mlx_linux
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
ifeq ($(OS), Darwin)
    # macOS
all : $(MLX_NAME) $(NAME)
else ifeq ($(OS), Linux)
    # Linux
all : $(MLX_NAME) $(NAME)
else ifeq ($(OS), Windows_NT)
    # Windows
all : $(NAME)
ADDFLAG = "C:\Program Files (x86)\GnuWin32\include\SDL2"
endif

ifeq ($(OS), Windows_NT)
    # Windows
.c.o :
	$(CC) $(CFLAG) -I $(HEAD) -I $(ADDFLAG) -c $< -o $@
else
.c.o :
	$(CC) $(CFLAG) -I $(HEAD) -c $< -o $@
endif

$(MLX_NAME):
	$(MAKE) -C $(MLX_DIR)

ifeq ($(OS), Darwin)
    # macOS
$(NAME) : $(OBJ) $(MLX_DIR)/$(MLX_NAME)
	$(CC) $(CFLAG) -I $(HEAD) -L$(MLX_DIR) $(ADDFLAG) -o $(NAME) $(OBJ) -lmlx $(ADDFLAG2)all : $(MLX_NAME) $(NAME)
else ifeq ($(OS), Linux)
    # Linux
$(NAME) : $(OBJ) $(MLX_DIR)/$(MLX_NAME)
	$(CC) $(CFLAG) -I $(HEAD) -L$(MLX_DIR) $(ADDFLAG) -o $(NAME) $(OBJ) -lmlx $(ADDFLAG2)
else ifeq ($(OS), Windows_NT)
    # Windows
$(NAME) : $(OBJ) 
	$(CC) $(CFLAG) -I $(HEAD) -I $(ADDFLAG) -o $(NAME) $(OBJ) 
endif

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