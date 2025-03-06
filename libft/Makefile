# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 12:35:30 by wbeschon          #+#    #+#              #
#    Updated: 2025/01/27 14:28:29 by wbeschon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c \
	  ft_bzero.c \
	  ft_calloc.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_isspace.c \
	  ft_itoa.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_putchar_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_putstr_fd.c \
	  ft_split.c \
	  ft_strchr.c \
	  ft_strcspn.c \
	  ft_strdup.c \
	  ft_striteri.c \
	  ft_strjoin.c \
	  ft_strlcat.c \
	  ft_strlcpy.c \
	  ft_strlen.c \
	  ft_strmapi.c \
	  ft_strncmp.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strspn.c \
	  ft_strtok.c \
	  ft_strtol.c \
	  ft_strtrim.c \
	  ft_substr.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  get_next_line.c \
	  get_next_line_utils.c

OBJ = $(SRC:.c=.o)

OBJBNS = $(SRCBNS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(OBJBNS)
	ar rcs $(NAME) $(OBJBNS) 

$(SRC):
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJ)

$(SRCBNS):
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJ)

clean:
	rm -f $(OBJ) $(OBJBNS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
