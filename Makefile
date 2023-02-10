# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htam <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 16:50:55 by htam              #+#    #+#              #
#    Updated: 2023/02/09 16:50:58 by htam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME := push_swap
LIBRARY := ./libft/libft.a
CFLAGS := -Wall -Werror -Wextra
CC := cc
SCRS := push_swap.c init_stack.c stack_operation.c validation.c

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