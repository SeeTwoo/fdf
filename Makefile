CC = cc
CFLAGS = -Wall -Wextra -Werror -g

IFLAGS = -I/usr/include -lXext -Iminilibx-linux -lX11 -lm -lz

LIBFT_DIR = libft
LIBFT_MAKEFILE = $(LIBFT_DIR)/Makefile
LIBFT_NAME = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX_MAKEFILE = $(MLX_DIR)/Makefile
MLX_NAME = $(MLX_DIR)/libmlx.a

PROGRAM_SRC = draw_line.c \
			  get_coordinates.c \
			  main.c \
			  math.c \
			  parsing.c \
			  put_tab.c \
			  tabfunc.c

PROGRAM_OBJ = $(PROGRAM_SRC:%.c=%.o)
NAME = fdf

all: $(LIBFT_NAME) $(MLX_NAME) $(NAME)

$(LIBFT_NAME):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_NAME):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(PROGRAM_OBJ) $(LIBFT_NAME) $(MLX_NAME)
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f *.o

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
