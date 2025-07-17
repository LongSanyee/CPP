NAME = Horde

SRC = zombieHorde.cpp Zombie.cpp main.cpp

C++ = c++

OBJ = $(SRC:.cpp=.o)

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(C++) $(CFLAGS) $(OBJ) -o $@

%.o: %.cpp Zombie.hpp
	$(C++) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all