# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htam <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 19:12:42 by htam              #+#    #+#              #
#    Updated: 2022/12/28 19:12:44 by htam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME := libftprintf.a
CC := cc
CFLAGS := -Werror -Wextra -Wall
SRCS := ft_printf.c \
		print_char.c \
		print_number.c \
		print_hex.c
OBJS := $(SRCS:.c=.o)
$(NAME): $(OBJS)
		ar -rcs $(NAME) $(OBJS)
		@echo "\033[0;92mlibftprintf.a compiled.\033[0;039m"
		

all: $(NAME)
clean:
	rm -f $(OBJS)
fclean:
	rm -f $(OBJS)
	rm -f $(NAME)
	@echo "\033[0;92mft_printf object file cleaned\033[0;39m"
re: fclean all
