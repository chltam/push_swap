/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:38:20 by htam              #+#    #+#             */
/*   Updated: 2023/02/07 16:38:21 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	long int		number;
	int				index;
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;

t_stack	*init_stack(char **argv);
void	ft_error(char *str);
void	free_stack(t_stack **stack);
long int	ft_atol(const char *nptr);
int		valid_input(char *str);
void	valid_number(t_stack **stack);
void	make_circle(t_stack **stack);
t_stack	*last_node(t_stack *stack);
void	add_to_stack_bot(t_stack **stack, t_stack *new);
void	add_to_stack_top(t_stack **stack, t_stack *new);
void	swap_node(t_stack **head);
void	push_stack(t_stack **stack_out, t_stack **stack_in);
void	push_action(t_stack **stack_a, t_stack **stack_b, char flag);
void	swap_action(t_stack **stack_a, t_stack **stack_b, char flag);
void	rotate_action(t_stack **stack_a, t_stack **stack_b, char flag);
void	re_rotate_action(t_stack **stack_a, t_stack **stack_b, char flag);

#endif