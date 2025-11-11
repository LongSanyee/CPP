NAME = Fixed

SRC = main.cpp Fixed.cpp

C++ = c++

OBJ = $(SRC:.cpp=.o)

CFLAGS = -Wall -Wextra -Werror

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