# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seb <seb@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 13:49:18 by swaegene          #+#    #+#              #
#    Updated: 2022/04/03 16:28:35 by seb              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

RM = rm -f
MKDIR = mkdir

MINILIBX_DIR = ./minilibx/
MINILIBX = minilibx.a

FT_PRINTF_DIR = ./ft_printf/
FT_PRINTF = libftprintf.a

LIBFT_DIR = ./libft/
LIBFT = libft.a

SRC_DIR = ./src/

ifdef MAKE_DEBUG
OUT_DIR = ./debug/
NAME := $(OUT_DIR)$(NAME)
DIRS = $(OUT_DIR)
CFLAGS = -g3 
else
OUT_DIR = ./
endif

CC = gcc
CFLAGS += -Wall -Wextra -Werror
CPPFLAGS += -I./include -I./$(MINILIBX_DIR) -I./$(FT_PRINTF_DIR)/include \
			-I./$(LIBFT_DIR)
LDFLAGS += -L./$(MINILIBX_DIR) -lmlx -framework OpenGL -framework AppKit -lz \
			-lm -L./$(FT_PRINTF_DIR) -L./$(LIBFT_DIR) -lftprintf -lft

SRCS = main.c mlx.c state.c handlers.c fractals.c complex.c zoom.c colors.c \
		params.c
OBJS = $(addprefix $(OUT_DIR),$(SRCS:%.c=%.o))

$(NAME): $(DIRS) $(OBJS) $(MINILIBX) $(FT_PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

$(OUT_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -c -o $@

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR) LIBFT_DIR=../$(LIBFT_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(DIRS):
	$(MKDIR) "$@"

bonus: $(NAME)

all: $(NAME)

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

