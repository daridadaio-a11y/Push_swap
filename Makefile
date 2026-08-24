# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkitagaw <mkitagaw@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/03 22:36:16 by mkitagaw          #+#    #+#              #
#    Updated: 2026/01/06 22:04:02 by mkitagaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME    = push_swap
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

# ここに君の持っているすべての .c ファイルを書くんだ
SRCS    = main.c \
          free_stack.c \
		  stack.c \
		  error.c \
          swap.c \
          push.c \
          rotate.c \
          reverse_rotate.c \
		  pa_sort.c\
          t_sort.c \
          sort.c \
          print_ops_by_count.c \
          ft_atoi.c \
          ft_split.c

OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re