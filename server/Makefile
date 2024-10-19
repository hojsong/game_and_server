CXX = c++
CXXFLAG = -Wall -Wextra -Werror -MMD -MP
ADDFLAG =
ADDFLAG2 =

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

OS := $(shell uname)

ifeq ($(OS), Darwin)
    # macOS
	CXXFLAG += -std=c++2a
	ADDFLAG += -lpq
else ifeq ($(OS), Linux)
    # Linux
	CXXFLAG += -std=c++20 -I/usr/include/postgresql
	ADDFLAG2 += -lpq
# else ifeq ($(OS), Windows_NT)
#     # Windows
#     SRC_DIR = ./src_window
# 	MLX_DIR = ./mlx_linux
# 	ADDFLAG += -lGL -lGLU
# 	ADDFLAG2 += -lX11 -lXext -lXrandr -lXrender -lm
endif

all : $(NAME)

.cpp.o :
	$(CXX) $(CXXFLAG) -I $(HEAD) -I/usr/local/opt/libpq/include -c $< -o $@

$(NAME) : $(OBJ) 
	$(CXX) $(CXXFLAG) -I $(HEAD) -I/usr/local/opt/libpq/include -L/usr/local/opt/libpq/lib $(ADDFLAG) -o $(NAME) $(OBJ) $(ADDFLAG2)

# 오타 수정: $(OBJS)를 $(OBJ)로 수정
clean :
	rm -rf $(SRC_DIR)/*.o $(SRC_DIR)/*.d

fclean : clean
	rm -rf $(NAME) src/*.o

re : fclean all

.PHONY : all re clean fclean bonus
