CXX = c++
CXXFLAG = -Wall -Wextra -Werror -std=c++2a -MMD -MP

HEAD = header
NAME = DodgeServer

SRC_DIR = ./src
SRC_FILES = main.cpp \
			client.cpp \
			server.cpp \
			ranking.cpp \
			sql_Integration.cpp

SRC = $(addprefix $(SRC_DIR)/,$(SRC_FILES))
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

.cpp.o :
	$(CXX) $(CXXFLAG) -I $(HEAD) -I/usr/local/opt/libpq/include -c $< -o $@

$(NAME) : $(OBJ) 
	$(CXX) $(CXXFLAG) -I $(HEAD) -I/usr/local/opt/libpq/include -L/usr/local/opt/libpq/lib -lpq -o $(NAME) $(OBJ)

# 오타 수정: $(OBJS)를 $(OBJ)로 수정
clean :
	rm -rf $(SRC_DIR)/*.o $(SRC_DIR)/*.d

fclean : clean
	rm -rf $(NAME) src/*.o

re : fclean all

.PHONY : all re clean fclean bonus
