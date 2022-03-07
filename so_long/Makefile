NAME = so_long

CC = gcc

CFLAGS	= -Wall -Wextra -Werror -fsanitize=address -g

LIBFT_DIR = libs/libft
LIBFT_EXE = libs/libft/libft.a

MLX_DIR = libs/minilibx
MLX_LINUX_DIR = libs/minilibx-linux

SRC = srcs/main.c srcs/init.c

OBJ = $(SRC:.c=.o)

INC = -I $(LIBFT_DIR) -L $(LIBFT_DIR) \
	  -I $(MLX_LINUX_DIR) -L $(MLX_LINUX_DIR) \
	  #-I $(MLX_DIR) -L $(MLX_DIR) \
	  #-l mlx -framework OpenGL -framework Appkit

# Colors #
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
RED			=	\033[0;31m
RESET       =   \033[0m

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I$(MLX_LINUX_DIR) -Imlx_linux -O3 -c $< -o $@

all: $(NAME)

.SILENT: $(OBJS)

$(NAME): $(LIBFT_EXEC) $(OBJ)
	@cat mkart
	@echo "$(YELLOW)[Initializing so_long ...]$(RESET)"
	@echo "$(YELLOW)[Compiling libft ...]$(RESET)"
	@make -C $(LIBFT_DIR)
	@echo "$(YELLOW)[Compiling so_long ...]$(RESET)"
	#@$(CC) $(CFLAGS) $(LIBFT_EXE) $(OBJ) -o $(NAME) $(INC)
	@$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L $(MLX_LINUX_DIR) -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	@echo "$(YELLOW)[Creating build dir ...]$(RESET)"
	@mkdir -p build \build/objs
	@echo "$(YELLOW)[Creating .o files ...]$(RESET)"
	@mv $(OBJ) build/objs
	@mkdir -p build/bin
	@mv $(NAME) build/bin
	@echo "$(GREEN)[Success! so_long is ready to use]$(RESET)"

clean:
	@rm -rf obj $(OBJS) $(NAME)
	@make -s clean -C $(LIBFT_DIR)
	@echo "$(YELLOW)[.o files were removed]$(RESET)"

fclean: clean
	@rm -rf build $(NAME)
	@make -s fclean -C $(LIBFT_DIR)
	@echo "$(RED)[so_long has been removed!]$(RESET)"

re: fclean all

exe: all
	@build/bin/./so_long

.PHONY: all clean fclean re
