INC=/usr/include

INCLIB=$(INC)/../lib

LMLX = minilibx-linux
MLX_DIR = libs/minilibx
LIBFT_DIR = libs/libft

UNAME := $(shell uname)

CFLAGS= -I$(INC) -O3 -I.. -g -Iinc -Ilibs/libft

NAME= so_long
SRC = $(wildcard srcs/*.c)
OBJ = $(SRC:%.c=%.o)

LFLAGS = -L.. -lmlx -L$(INCLIB) -lXext -lX11 -lm -L$(LMLX) -L$(LIBFT_DIR) -lft

ifeq ($(UNAME), Darwin)
	# mac
	CC = gcc
	LFLAGS = -L$(MLX_DIR) -lmlx -L$(MLX_DIR) -framework OpenGL -framework AppKit -L$(LIBFT_DIR) -lft
else ifeq ($(UNAME), FreeBSD)
	# FreeBSD
	CC = clang
else
	#Linux and others...
	CC	= gcc
	LFLAGS += -lbsd
endif

# Colors #
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
RED			=	\033[0;31m
RESET       =   \033[0m

all: $(NAME)

.SILENT: $(OBJ)

$(NAME): show norm runlibft $(OBJ)
	@echo "$(YELLOW)[      Compiling so_long ...     ]$(RESET)"	
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LFLAGS)
	@mkdir -p build \build/objs
	@mv $(OBJ) build/objs
	@mkdir -p build/bin
	@mv $(NAME) build/bin
	@cp img/*/*.xpm ./
	@echo "$(GREEN)[    So_long is ready to play!   ]$(RESET)"

show:
	@cat mkart
	@echo " [  OS : $(YELLOW)$(UNAME)$(RESET)  ]\n"
	@echo "[  NAME : $(YELLOW)$(NAME)$(RESET)  ]\n"
	@echo "$(YELLOW)[    Initializing so_long ...    ]$(RESET)"

runlibft:
	@make -s -C libs/libft

norm:
	@echo "$(GREEN)[           Norminette           ]$(RESET)"
	norminette -R CheckForbiddenSourceHeader $(SRC)
	norminette -R CheckDefine inc/so_long.h

clean:
	@rm -rf build/objs
	@make -s clean -C $(LIBFT_DIR)
	@echo "\n$(YELLOW)[      objects were removed      ]$(RESET)"

fclean: clean
	@make -s fclean -C $(LIBFT_DIR)
	@rm -rf build
	@rm -rf *.xpm
	@echo "$(RED)[    So_long has been removed!   ]$(RESET)"

re: fclean all

exe: all
	@build/bin/./so_long map2.ber
