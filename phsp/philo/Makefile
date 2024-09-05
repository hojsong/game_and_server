CC = cc
CFLAG = -Wall -Wextra -Werror
FFLAG = -fsanitize=thread
NAME = philosopher
HEAD = ./php.h
SRCS = main.c process.c src1.c src2.c src3.c thread1.c action.c src4.c
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
