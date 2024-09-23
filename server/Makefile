CC = c++
CFLAG = -Wall -Wextra -Werror -std=c++2a

HEAD = header
NAME = Sever

SRC_DIR = ./src
SRC_FILES = main.c \

SRC = $(addprefix $(SRC_DIR)/,$(SRC_FILES))
OBJ = $(SRC:.c=.o)

all : $(NAME)

.c.o :
	$(CC) $(CFLAG) -I $(HEAD) -c $< -o $@

$(NAME) : $(OBJ) 
	$(CC) $(CFLAG) -I $(HEAD) -o $(NAME) $(OBJ)

# 오타 수정: $(OBJS)를 $(OBJ)로 수정
clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME) src/*.o

re : fclean all

.PHONY : all re clean fclean bonus
