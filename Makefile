NAME = fdf
LIBFT = libft/libft.a
MLX = minilibx/libmlx.a
MY_MATH = my_math/my_math.a
INCLUDES = -I libft/ minilibx/ my_math/
CONFIG = gcc -Wall -Wextra -Werror $(SRC) $(CONFIG2) $(CONFIG3) $(CONFIG4)
CONFIG2 = -L libft -lft -o $(NAME)
CONFIG3 = -L minilibx -lmlx -framework OpenGL -framework AppKit
CONFIG4 = -L my_math
SRC = fdf.c\
	  parse.c\
	  render.c\
	  draw.c

OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(MLX) $(LIBFT) $(MY_MATH) $(NAME)

$(MLX):
	make -C minilibx/

$(LIBFT):
	make -C libft/

$(MY_MATH):
	make -C my_math/

$(NAME):
	$(CONFIG)
	
clean:
	/bin/rm -f $(OBJ)
	make -C libft clean
	make -C my_math clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft fclean
	make -C my_math fclean

re: fclean all
