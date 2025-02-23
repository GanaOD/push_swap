NAME = test

SRC_DIR = ../../src
INPUT_DIR = $(SRC_DIR)/input
STACK_DIR = $(SRC_DIR)/stack
LIBFT_DIR = ../../libft

SRCS = $(INPUT_DIR)/parse.c \
       $(STACK_DIR)/ops.c \
       test.c \
       main.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror \
         -I../../inc \
         -I../../libft \
         -I.

# Add -g for debugging
CFLAGS += -g

# First build libft
$(NAME): $(LIBFT_DIR)/libft.a $(OBJS)
	$(CC) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT_DIR)/libft.a:
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re