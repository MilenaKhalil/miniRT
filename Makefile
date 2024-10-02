CC = cc
DEBUG = -fsanitize=address
FLAGS = -Wall -Wextra -Werror
NAME = miniRT

SRCS = parser/error_handling.c \
	   parser/open_file.c		\
	   parser/parser.c			\
	   parser/parser_utilities.c \
	   parser/elements_parser.c \
	   camera.c 	\
	   color.c 		\
	   info.c 		\
	   light.c 		\
	   main.c 		\
	   plane.c 		\
	   point.c 		\
	   print.c 		\
	   ray_tracing.c \
	   scene.c 		\
	   sphere.c 	\
	   sphere_coordinate.c \
	   utils.c 		\
	   vector.c 	

INCS =	parser.h \
		camera.h \
		color.h \
		coordinate.h \
		light.h 	\
		miniRT.h \
		plane.h \
		ray_tracing.h \
		scene.h \
		sphere.h \
		utils.h

LIBFT = libft/libft.a
MLX = MLX42/libmlx42.a

FRAMEWORKS = -lglfw -lm
INC_DIR = include/

SRC_DIR = src/
SRC_PARSER_DIR = src/parser/
OBJ_DIR = obj/

SRC = $(addprefix $(SRC_DIR), $(SRCS))
OBJ = $(addprefix $(OBJ_DIR), $(notdir $(SRCS:.c=.o)))
INC = $(addprefix $(INC_DIR), $(INCS))
ALL_INC = -I $(INC_DIR) -I libft -I MLX42/include/MLX42

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(INC) $(LIBFT) $(MLX)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(MLX) $(FRAMEWORKS)  -o $(NAME)

$(LIBFT): 
	$(MAKE) bonus -C libft

$(MLX):
	$(MAKE) -C MLX42

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC) 
	$(CC) $(FLAGS) $(ALL_INC) -c $< -o $@

$(OBJ_DIR)%.o: $(SRC_PARSER_DIR)%.c $(INC) 
	$(CC) $(FLAGS) $(ALL_INC) -c $< -o $@ 

clean:
	$(MAKE) clean -C libft
	$(MAKE) clean -C MLX42
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C libft
	$(MAKE) fclean -C MLX42
	rm -f $(NAME)

re: fclean all

 