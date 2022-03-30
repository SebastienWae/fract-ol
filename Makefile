# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seb <seb@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 13:49:18 by swaegene          #+#    #+#              #
#    Updated: 2022/03/30 22:27:31 by seb              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

UNAME_S := $(shell uname -s)

RM = rm -f
MKDIR = mkdir

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
CPPFLAGS += -I./include

ifeq ($(UNAME_S),Linux)
LDFLAGS += -lmlx -lXext -lX11 -lm
endif
ifdef ($(UNAME_S),Darwin)
LDFLAGS += -lmlx -framework OpenGL -framework AppKit -lz -lm
endif

SRCS = main.c mlx.c state.c hooks.c fractals.c complex.c
OBJS = $(addprefix $(OUT_DIR),$(SRCS:%.c=%.o))

$(NAME): $(DIRS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

$(OUT_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -c -o $@

$(DIRS):
	$(MKDIR) "$@"

all: $(NAME)

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

