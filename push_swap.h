/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:38:20 by htam              #+#    #+#             */
/*   Updated: 2023/02/24 19:09:23 by htam             ###   ########.fr       */
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

typedef struct s_info
{
	t_stack	*head;
	size_t	size;
}	t_info;

t_stack		*init_stack(char **argv);
void		ft_error(char *str);
void		free_stack(t_stack **stack);
long int	ft_atol(const char *nptr);
int			valid_input(char *str);
void		valid_number(t_stack **stack);
void		make_circle(t_stack **stack);
size_t		set_index(t_stack *stack);
t_stack		*last_node(t_stack *stack);
void		add_to_stack_bot(t_stack **stack, t_stack *new);
size_t		count_node(t_stack *stack);
void		push_action(t_info *info_a, t_info *info_b, char flag);
void		rotate_action(t_info *info_a, t_info *info_b, char flag);
void		re_rotate_action(t_info *info_a, t_info *info_b, char flag);
void		swap_action(t_info *info_a, t_info *info_b, char flag);
void		sort_three(t_info *info_a, t_info *info_b, char flag);
void		sort_four(t_info *info_a, t_info *info_b);
void		sort_five(t_info *info_a, t_info *info_b);
int			is_sorted(t_stack *stack);
void		sort_more(t_info *info_a, t_info *info_b, int limit);
void		radix_sort(t_info *info_a, t_info *info_b);
int			find_max(t_stack *stack);

/*print*/
void		print_stack(t_stack *stack_a, t_stack *stack_b);

#endif