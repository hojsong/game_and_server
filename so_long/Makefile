# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 16:08:11 by hojsong           #+#    #+#              #
#    Updated: 2022/12/22 16:02:56 by hojsong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAG = -Wall -Wextra -Werror
CLIB = -I -Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx
HEAD = head/
NAME = so_long
NAME_BO = so_long_bonus
SRCS = srcs/ft_split.c srcs/get_next_line.c srcs/get_next_line_utils.c\
	   srcs/main.c srcs/check.c srcs/check2.c srcs/mlxstart.c srcs/mlxing.c\
	   srcs/mlx_util.c
SRCS_BO = bo/ft_split.c bo/get_next_line.c bo/get_next_line_utils.c\
	   bo/main.c bo/check.c bo/check2.c bo/mlxstart.c bo/mlxing.c\
	   bo/mlx_util.c bo/image_util.c bo/image_util2.c \
	   bo/mlxmon.c bo/mlx_monmv.c bo/mlx_util2.c
OBJS = $(SRCS:.c=.o)
OBJS_BO = $(SRCS_BO:.c=.o)

ifdef BONUS
	OBJ_CUR = $(OBJS_BO)
	NAME_CUR = $(NAME_BO)
else
	OBJ_CUR = $(OBJS)
	NAME_CUR = $(NAME)
endif

all : $(NAME_CUR)
	
.c.o :
	$(CC) $(CFLAG) -I $(HEAD) -c $< -o $@
$(NAME_CUR) : $(OBJ_CUR)
	$(CC) $(CFLAG) $(CLIB) -o $(NAME_CUR) $(OBJ_CUR)
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME_CUR)
clean :
	rm -rf $(OBJS) $(OBJS_BO)
fclean : clean
	rm -rf $(NAME) $(NAME_BO)
re : fclean all

bonus :
	make BONUS=1 $(NAME_BO)

.PHONY : all re clean fclean bonus
