NAME = BSP

SRC = main.cpp Fixed.cpp  bsp.cpp Point.cpp

C++ = c++

OBJ = $(SRC:.cpp=.o)

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

all: $(NAME)

$(NAME): $(OBJ)
	$(C++) $(CFLAGS) $(OBJ) -o $@

%.o: %.cpp Fixed.hpp
	$(C++) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all