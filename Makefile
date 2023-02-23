# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htam <htam@student.42berlin.de>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 16:50:55 by htam              #+#    #+#              #
#    Updated: 2023/02/23 22:34:29 by htam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
LIBRARY := ./libft/libft.a
CFLAGS := -Wall -Werror -Wextra
CC := cc
SCRS := push_swap.c init_stack.c \
		basic_operation.c validation.c indexing.c \
		push.c swap.c rotate.c \
		sort_small.c sort_big.c sort_bigger.c

$(NAME) : $(SCRS)
	@make -C libft
	$(CC) $(SCRS) $(LIBRARY) -o $(NAME)

all : $(NAME)

clean:
	rm -f $(NAME)

fclean:
	make fclean -C libft
	rm -f $(NAME)

re: fclean all