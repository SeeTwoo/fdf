CC = cc
CFLAGS = -Wall -Wextra -Werror
DFLAGS = $(CFLAGS) -g3

IFLAGS = -I/usr/include -Iminilibx-linux -Iincludes -Ilibft/includes
LDFLAGS = -lXext -lX11 -lm -lz

LIB_DIR = libft
LIB_NAME = $(LIB_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX_NAME = $(MLX_DIR)/libmlx.a

SRC_DIR = src
SRC_FILES = draw_line.c \
			get_coordinates.c \
			main.c \
			math.c \
			parsing.c \
			put_tab.c \
			tabfunc.c
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR = obj
OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
%.o = %.c

NAME = fdf

all: $(LIBFT_NAME) $(MLX_NAME) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(LIB_NAME):
	$(MAKE) -C $(LIB_DIR)

$(MLX_NAME):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJ) $(LIB_NAME) $(MLX_NAME)
	$(CC) $(CFLAGS) $(IFLAGS) $(LDFLAGS) -o $@ $^

clean:
	$(MAKE) -C $(LIB_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIB_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
