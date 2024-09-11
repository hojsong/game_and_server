CC = cc
CFLAG = -Wall -Wextra -Werror
NAME = ft_ping
HEAD = header
SRCS = src/main.c src/util.c src/sig.c src/libft.c
OBJS = $(SRCS:.c=.o)

OS := $(shell uname)

ifeq ($(OS), Darwin)
    # macOS
    SRCS += src/macPrint.c
else ifeq ($(OS), Linux)
    # Linux
    SRCS += src/linuxPrint.c
endif

all : $(NAME) $(HEAD)
	
.c.o : $(HEAD)
	$(CC) $(CFLAG) -I $(HEAD) -c $< -o $@ 

$(NAME) : $(OBJS) $(HEAD)
	$(CC) $(CFLAG) -I $(HEAD) -o $(NAME) $(OBJS)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all re clean fclean bonus