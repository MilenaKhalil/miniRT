# Detect architecture
ARCH := $(shell uname -m)

# Install GLFW if not found
GLFW_CHECK := $(shell pkg-config --exists glfw3 || echo "MISSING")
ifeq ($(GLFW_CHECK),MISSING)
HOMEBREW_PREFIX := $(shell brew --prefix)
GLFW_PATH := $(HOMEBREW_PREFIX)/opt/glfw
GLFW_INC := $(GLFW_PATH)/include
GLFW_LIB := $(GLFW_PATH)/lib

else
GLFW_PATH := $(shell pkg-config --variable=prefix glfw3)
GLFW_INC := $(GLFW_PATH)/include
GLFW_LIB := $(GLFW_PATH)/lib
endif



CC = cc
DEBUG = -fsanitize=address
FLAGS = -Wall -Wextra -Werror
FRAMEWORKS = -L$(GLFW_LIB) -lglfw -framework Cocoa -framework Metal -framework QuartzCore -lm
ALL_INC = -I $(INC_DIR) -I libft -I MLX42/include/MLX42 -I$(GLFW_INC)
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

INC_DIR = include/

SRC_DIR = src/
SRC_PARSER_DIR = src/parser/
OBJ_DIR = obj/

SRC = $(addprefix $(SRC_DIR), $(SRCS))
OBJ = $(addprefix $(OBJ_DIR), $(notdir $(SRCS:.c=.o)))
INC = $(addprefix $(INC_DIR), $(INCS))
ALL_INC = -I $(INC_DIR) -I libft -I MLX42/include/MLX42

all: glfw $(NAME)

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

.PHONY: glfw
glfw:
	@echo "pkg-config not found, installing via Homebrew..."
	brew install pkg-config
	@echo "GLFW not found, installing via Homebrew..."
	brew install glfw
 