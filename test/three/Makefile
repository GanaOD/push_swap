# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/22 14:02:17 by go-donne          #+#    #+#              #
#    Updated: 2025/02/22 14:32:54 by go-donne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test

# Source directories
SRC_DIR = ../../src
STACK_DIR = $(SRC_DIR)/stack
OPS_DIR = $(SRC_DIR)/ops
SORT_DIR = $(SRC_DIR)/sort

# Source files with full paths
SRCS = $(STACK_DIR)/ops.c \
       $(SORT_DIR)/small.c \
       $(OPS_DIR)/push.c \
       $(OPS_DIR)/swap.c \
       $(OPS_DIR)/rot.c \
       $(OPS_DIR)/rev.c \
       test.c \
       main.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I../../inc -I.

# Make sure the object directory structure exists
$(shell mkdir -p $(dir $(OBJS)))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re