#include the mlx header which in my linux computer is located here...(also in 42 coputers...)
INC = libs/minilibx

LIBFT_DIR = libs/libft #include the library libft path for linking later with -L

LIBFT_SRC = $(LIBFT_DIR) $(wildcard src/*.c)

MLX_DIR = $(INC) #include the mlx lib which in my linux computer is located here... (also in 42 computers...)

INCS = inc #so_long "include" folder, which is the standard but in your project is "inc"... so you might want to change either this var or your folder name

OS := $(shell uname)

CFLAGS= -Wall -Werror -Wextra -I$(INC) -O3 -I.. -I$(INCS) -g #Here I link the mlx header and the the so_long project header

NAME= so_long

SRC = srcs/main.c srcs/init.c srcs/moving.c \
srcs/paint.c srcs/init_player.c srcs/animation_player.c \
srcs/init_map.c srcs/map_checker.c 

OBJ = $(SRC:%.c=%.o)

LFLAGS = -L$(MLX_DIR) -lmlx -L$(MLX_DIR) -lXext -lX11 -lm -L$(LIBFT_DIR) -lft #Link the mlx Library and the Libft and standard GC libraries for linux and FreeSBD

# Colors #
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
RED			=	\033[0;31m
CYAN		=	\033[4;33m
RESET       =   \033[0m

ifeq ($(OS), Darwin)
	# mac
	CC = gcc
	LFLAGS = -L$(MLX_DIR) -lmlx -L$(MLX_DIR) -framework OpenGL -framework AppKit -L${LIBFT_DIR} -lft #Link the mlx Library and the Libft and the graphic Frameworks for Dawrin (iMac)
else ifeq ($(OS), FreeBSD)
	# FreeBSD
	CC = clang
else
	#Linux and others...
	CC	= gcc
	LFLAGS += -lbsd
endif

all: $(NAME)

.SILENT: $(OBJ)

$(NAME): show runlibft $(OBJ)
	@echo "$(YELLOW)[      Compiling so_long ...     ]$(RESET)"
	@$(CC) -o $(NAME) $(OBJ) $(LFLAGS)
	@mkdir -p build \build/objs
	@mv $(OBJ) build/objs
	@mkdir -p build/bin
	@mv $(NAME) build/bin
	@cp img/*/*.xpm ./
	@echo "$(GREEN)[ Success! so_long is ready play ]$(RESET)"


show:
	@cat mkart
	@echo " [  OS : $(CYAN)$(OS)$(RESET)  ]\n"
	@echo "[  NAME : $(CYAN)$(NAME)$(RESET)  ]\n"
	@echo "$(YELLOW)[    Initializing so_long ...    ]$(RESET)"

runlibft:
	@echo "$(YELLOW)[       Compiling libft ...      ]$(RESET)"
	@make -s -C $(LIBFT_DIR) all

norm:
	norminette -R CheckForbiddenSourceHeader $(SRC)
	norminette -R CheckDefine inc/so_long.h
	norminette -R CheckForbiddenSourceHeader $(LIBFT_SRC)

clean:
	@rm -rf build/objs
	@make -s clean -C $(LIBFT_DIR)
	@echo "\n$(YELLOW)[      objects were removed      ]$(RESET)"

fclean: clean
	@make -s fclean -C $(LIBFT_DIR)
	@rm -rf build
	@rm -rf *.xpm
	@echo "$(RED)[    So_long has been removed!   ]$(RESET)"

exe: all
	@build/bin/./so_long map2.ber

re: fclean all
