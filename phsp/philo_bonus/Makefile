CC = cc
CFLAG = -Wall -Wextra -Werror
NAME = philosopher_bonus
HEAD = ./php.h
SRCS = main_bonus.c process_bonus.c src1_bonus.c src_bonus.c\
		src2_bonus.c src3_bonus.c thread1_bonus.c action_bonus.c src4_bonus.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(HAED)
	$(CC) $(CFLAG) -I $(HEAD) -o $(NAME) $(OBJS)

.c.o :
	$(CC) $(CFLAG) -I $(HEAD) -c $< -o $@

clean : 
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all re clean fclean
