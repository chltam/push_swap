/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:28:14 by htam              #+#    #+#             */
/*   Updated: 2023/02/17 15:40:37 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a, t_stack **stack_b)
{
	while (!is_sorted(*stack_a))
	{
		if ((*stack_a)->index == 3)
			rotate_action(stack_a, stack_b, 'a');
		else if ((*stack_a)->previous->index == 3)
			swap_action(stack_a, stack_b, 'a');
		else if ((*stack_a)->next->index == 3)
			re_rotate_action(stack_a, stack_b, 'a');
	}
}
