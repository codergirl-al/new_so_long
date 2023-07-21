CC=cc
CFLAGS=-Wall -Wextra -Werror

CFILES=main.c utils.c map_utils.c map_validation.c ft_error_handling.c ft_is_map_winnable.c mlx_init.c mlx_move.c ft_hooks.c ft_move_functionalities.c
OFILES=main.o utils.o map_utils.o map_validation.o ft_error_handling.o ft_is_map_winnable.o mlx_init.o mlx_move.o ft_hooks.o ft_move_functionalities.o

LIBFT=./libft/libft.a
MLX=./mlx/libmlx.a

NAME=so_long

MAKE=make

all:$(NAME)

$(NAME): $(MLX) $(OFILES) $(LIBFT)
	$(CC) $(CFLAGS) $(OFILES) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	clear

$(LIBFT): 
	cd ./libft && $(MAKE)

$(MLX):
	cd ./mlx && $(MAKE)

%.o:%.c
	$(CC) $(CFLAGS) -Imlx -c -o $@ $^

clean:
	rm -f $(OFILES)
	cd ./libft && $(MAKE) clean
	cd ./mlx && $(MAKE) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

norm:
	norminette ./libft/* $(CFILES) ./include/so_long.h

bonus: all































# AUTHORS		=	apeposhi
# DATE		=	$$(date +%Y/%m/%d)
# BUSER 		=	~/.brew/opt/glfw/lib/

# CC			=	cc
# CFLAGS		=	-Werror -Wextra -Wall

# NAME 		=	so_long

# SRC_DIR		=	src/
# OBJ_DIR		=	obj/
# INC_DIR		=	include/
# LIBA 		=	MLX42/build/libmlx42.a
# LIBFT		=	libft/libft.a

# SRC_NAME	=	main
# INC_NAME	=	so_long

# SRC_FILES	=	$(addsuffix .c, $(addprefix $(SRC_DIR), $(SRC_NAME)))
# OBJ_FILES	=	$(addsuffix .o, $(addprefix $(OBJ_DIR), $(SRC_NAME)))
# INC_FILES	=	$(addsuffix .h, $(addprefix $(INC_DIR), $(INC_NAME)))

# ifeq ($(shell uname -s),Linux)
# 	OS := Linux
# 	LIB	=	-ldl -lglfw -pthread -lm
# else ifeq ($(shell uname -s),Darwin)
# 	OS := MacOS
# 	LIB		=	-framework Cocoa -framework OpenGL -framework IOKit -lglfw -L ~/.brew/opt/glfw/lib/
# else
# 	OS := Unknown
# 	exit 1
# endif

# $(info Compiling for $(OS))

# all : $(NAME)

# $(OBJ_DIR):
# 	@mkdir -p $(OBJ_DIR)

# $(OBJ_DIR)%.o : $(SRC_DIR)%.c
# 	$(CC) $(CFLAGS) -c $< -I$(INC_DIR) -o $@ -IMLX42/include
# #
# $(NAME) : $(OBJ_DIR) $(OBJ_FILES) $(INC_FILES) 
# 	@make -C ./libft
# 	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME) $(LIBA) $(LIB) -I$(INC_DIR)

# clean:
# 	cd libft && make clean
# 	@rm -rf $(OBJ_DIR)

# fclean: clean
# 	cd libft && make fclean
# 	@rm -f $(NAME) .header

# re: fclean all