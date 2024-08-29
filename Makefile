SRC = $(wildcard *.c)

MLX = MLX42/libmlx42.a

OBJ = $(SRC:.c=.o)

CFLAGS = -Ofast #  -Wall -Werror -Wextra

NAME = miniRT

INCLUDE = -I ./

CC = cc

all: $(NAME)

$(MLX):
	$(MAKE) -C MLX42
	
$(NAME): $(OBJ) $(MLX)
	$(CC) $(CFLAGS) $^ -o $@ -lglfw -framework Cocoa -framework OpenGL -framework IOKit

%.o: %.c $(wildcard *.h)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C MLX42

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C MLX42

re: fclean all

.PHONY: all re fclean clean
