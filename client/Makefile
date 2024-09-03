CC = cc
CFLAG = -Wall -Wextra -Werror -fsanitize=address -g3
#  -DGL_SILENCE_DEPRECATION -Wno-unused-parameter -Wno-unused-but-set-variable

HEAD = header
NAME = Dodge

SRC_DIR = ./src
SRC_FILES = choice.c \
            gamelogic.c \
            imagePut.c \
            init.c \
            local.c \
            main.c \
            web.c 

MLX_DIR = ./mlx
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
	$(CC) $(CFLAG) -I $(HEAD) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJ)

# 오타 수정: $(OBJS)를 $(OBJ)로 수정
clean :
	rm -rf $(OBJ)
	$(MAKE) -C $(MLX_DIR) clean # mlx 폴더에서 clean 명령어 실행

fclean : clean
	rm -rf $(NAME)
	$(MAKE) -C $(MLX_DIR) clean # mlx 폴더에서 clean 명령어 실행

re : fclean all

bonus :
	make BONUS=1 $(NAME_BO)

.PHONY : all re clean fclean bonus $(MLX_NAME)

# CC = cc
# CFLAG = -Wall -Wextra -Werror

# HEAD = header
# NAME = Dodge

# SRC_DIR = ./src
# SRC_FILES = choice.c \
# 			gamelogic.c \
# 			imagePut.c \
# 			init.c \
# 			local.c \
# 			main.c \
# 			web.c 

# MLX_NAME = libmlx.a
# MLX_DIR = ./mlx
# MLX_FILES = mlx_shaders.c \
# 			mlx_new_window.m \
# 			mlx_init_loop.m \
# 			mlx_new_image.m \
# 			mlx_xpm.c \
# 			mlx_int_str_to_wordtab.c

# SRC = $(addprefix $(SRC_DIR)/,$(SRC_FILES))
# MLX_SRC = $(addprefix $(MLX_DIR)/,$(MLX_FILES))
# OBJ = $(SRC:.c=.o) $(MLX_SRC:.c=.o)

# all : $(NAME)
	
# .c.o :
# 	$(CC) $(CFLAG) -I $(HEAD) -c $< -o $@

# $(NAME) : $(OBJ)
# 	$(CC) $(CFLAG) $(CLIB) -o $(NAME) $(OBJ)

# clean :
# 	rm -rf $(OBJS)

# fclean : clean
# 	rm -rf $(NAME)

# re : fclean all

# bonus :
# 	make BONUS=1 $(NAME_BO)

# .PHONY : all re clean fclean bonus
