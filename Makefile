# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seb <seb@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 13:49:18 by swaegene          #+#    #+#              #
#    Updated: 2022/04/02 11:10:40 by seb              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

UNAME_S := $(shell uname -s)

RM = rm -f
MKDIR = mkdir
MINILIBX_DIR = ./minilibx/
MINILIBX = minilibx.a

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
CPPFLAGS += -I./include -I./minilibx

ifeq ($(UNAME_S),Linux)
LDFLAGS += -lmlx -lXext -lX11 -lm
endif
ifeq ($(UNAME_S),Darwin)
LDFLAGS += -L./minilibx -lmlx -framework OpenGL -framework AppKit -lz -lm 
endif

SRCS = main.c mlx.c state.c handlers.c fractals.c complex.c zoom.c colors.c
OBJS = $(addprefix $(OUT_DIR),$(SRCS:%.c=%.o))

$(NAME): $(DIRS) $(OBJS) $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

$(OUT_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -c -o $@

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)

$(DIRS):
	$(MKDIR) "$@"

all: $(NAME)

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

