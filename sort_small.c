/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:28:14 by htam              #+#    #+#             */
/*   Updated: 2023/02/22 14:39:52 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_info *info_a, t_info *info_b, char flag)
{
	t_stack	**stack;

	if (flag == 'a')
		stack = &info_a->head;
	else if (flag == 'b')
		stack = &info_b->head;
	while (!is_sorted(*stack))
	{
		if ((*stack)->index > (*stack)->next->index
			&& (*stack)->index > (*stack)->previous->index)
			rotate_action(info_a, info_b, flag);
		else if ((*stack)->previous->index > (*stack)->index
			&& (*stack)->previous->index > (*stack)->next->index)
			swap_action(info_a, info_b, flag);
		else if ((*stack)->next->index > (*stack)->index
			&& (*stack)->next->index > (*stack)->previous->index)
			re_rotate_action(info_a, info_b, flag);
	}
}

void	sort_four(t_info *info_a, t_info *info_b)
{
	t_stack **stack;

	stack = &info_a->head;
	if ((*stack)->index == 3)
		swap_action(info_a, info_b, 'a');
	push_action(info_a, info_b, 'b');
	sort_three(info_a, info_b, 'a');
	push_action(info_a, info_b, 'a');
	if ((*stack)->index == 2)
		swap_action(info_a, info_b, 'a');
	else if ((*stack)->index == 4)
		rotate_action(info_a, info_b, 'a');
}

void	sort_five(t_info *info_a, t_info *info_b)
{
	t_stack **stack;

	stack = &info_a->head;
	while ((*stack)->index != 5)
	{
		if ((*stack)->next->index == 5 || (*stack)->next->next->index == 5)
			rotate_action(info_a, info_b, 'a');
		if ((*stack)->previous->index == 5 || (*stack)->previous->previous->index == 5)
			re_rotate_action(info_a, info_b, 'a');
	}
	push_action(info_a, info_b, 'b');
	sort_four(info_a, info_b);
	push_action(info_a, info_b, 'a');
	rotate_action(info_a, info_b, 'a');
}
