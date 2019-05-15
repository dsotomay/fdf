NAME = my_math.a
HEADER = -c
CONFIG = gcc $(HEADER) -Wall -Wextra -Werror $(SRC)
CONFIG2 = ar rc $(NAME) $(OBJ)
CONFIG3 = ranlib $(NAME)
SRC = matrix.c\
      matrix_trans.c
      
OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME):
	$(CONFIG)
	$(CONFIG2)
	$(CONFIG3)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
