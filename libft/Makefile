CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS =	ft_isalpha.c		\
		ft_isdigit.c		\
		ft_isalnum.c		\
		ft_isascii.c		\
		ft_isprint.c		\
		ft_toupper.c		\
		ft_tolower.c		\
		ft_strlen.c			\
		ft_strchr.c			\
		ft_strrchr.c		\
		ft_strncmp.c		\
		ft_memset.c			\
		ft_bzero.c			\
		ft_memcpy.c			\
		ft_memmove.c		\
		ft_memchr.c			\
		ft_memcmp.c			\
		ft_strlcpy.c		\
		ft_strlcat.c		\
		ft_strnstr.c		\
		ft_atoi.c			\
		ft_strdup.c			\
		ft_calloc.c			\
		ft_substr.c			\
		ft_strjoin.c		\
		ft_strtrim.c		\
		ft_split.c			\
		ft_itoa.c			\
		ft_strmapi.c		\
		ft_striteri.c		\
		ft_putchar_fd.c		\
		ft_putstr_fd.c		\
		ft_putendl_fd.c		\
		ft_putnbr_fd.c 		\
		ft_recursive_power.c\
		ft_get_next_line.c	\
		ft_get_next_line_utils.c \
		ft_count_words.c \
		ft_arrlen.c		\
		ft_arrfree.c	\
		ft_atod.c		

BONUS_SRC =	ft_lstnew_bonus.c			\
			ft_lstadd_front_bonus.c		\
			ft_lstsize_bonus.c			\
			ft_lstlast_bonus.c			\
			ft_lstadd_back_bonus.c		\
			ft_lstdelone_bonus.c		\
			ft_lstclear_bonus.c			\
			ft_lstiter_bonus.c			\
			ft_lstmap_bonus.c

INC = libft.h
OBJ_DIR = obj/
SRC_DIR = src/
#SRC = $(addprefix $(SRC_DIR), $(SRCS:.c=.o))
OBJ = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
BONUS_OBJ = $(addprefix $(OBJ_DIR), $(BONUS_SRC:.c=.o))

ifdef BONUS
OBJ_FILES = $(OBJ) $(BONUS_OBJ)
else
OBJ_FILES = $(OBJ)
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@ar rcs $@ $^

bonus : 
	@$(MAKE) BONUS=1 all

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -c -o $@ $<

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
