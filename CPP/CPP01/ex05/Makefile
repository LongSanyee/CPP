NAME = Harl

SRC = main.cpp Harl.cpp

C++ = c++

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(C++) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp Harl.hpp
	$(C++) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all