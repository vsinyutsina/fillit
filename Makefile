NAME = fillit

CC = gcc
#CC_FLAGS = -Wall -Wextra -Werror

# sources files
SRC_NAME = map_size.c	\
	main.c				\
	print.c				\
	initialization.c	\
	solve.c 			\
	support.c			\
	map_size_extended.c	\
	solve_extended.c
SRC_PATH = ./srcs/
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

# includes files
INC_NAME = fillit.h
INC_PATH = ./includes/
INC = $(addprefix -I, $(INC_PATH))

# libft library
LFT_PATH = ./libft/

# object file
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = ./obj/
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

# color
GREEN = \033[0;32m
WHITE = \033[m
RED = \033[0;31m

.PHONY: all clean fclean re

.SUFFIXES: .c .o

all: $(NAME)

$(NAME): $(LFT_PATH) $(OBJ)
	@make -C $(LFT_PATH)
	@$(CC) $(CC_FLAGS) $(OBJ) -o $(NAME) ./libft/libft.a
	@echo "$(GREEN)✓ Building $(NAME)$(WHITE)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<

clean:
	@make -C $(LFT_PATH) clean
	@/bin/rm -rf $(OBJ_PATH)
	@echo "$(RED)✗ Deletion of object files$(WHITE)"

fclean: clean
	@make -C $(LFT_PATH) fclean
	@/bin/rm -f $(NAME)
	@echo "$(RED)✗ Deletion of $(NAME)$(WHITE)"

re: fclean all