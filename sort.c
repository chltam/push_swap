/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:28:14 by htam              #+#    #+#             */
/*   Updated: 2023/02/20 23:17:29 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	sort_three(t_stack **stack_a, t_stack **stack_b)
// {
// 	while (!is_sorted(*stack_a))
// 	{
// 		if ((*stack_a)->index == 3)
// 			rotate_action(stack_a, stack_b, 'a');
// 		else if ((*stack_a)->previous->index == 3)
// 			swap_action(stack_a, stack_b, 'a');
// 		else if ((*stack_a)->next->index == 3)
// 			re_rotate_action(stack_a, stack_b, 'a');
// 	}
// }

// void	sort_three(t_stack **stack_a, t_stack **stack_b)
// {
// 	while (!is_sorted(*stack_a))
// 	{
// 		if ((*stack_a)->index > (*stack_a)->next->index
// 			&& (*stack_a)->index > (*stack_a)->previous->index)
// 			rotate_action(stack_a, stack_b, 'a');
// 		else if ((*stack_a)->previous->index > (*stack_a)->index
// 			&& (*stack_a)->previous->index > (*stack_a)->next->index)
// 			swap_action(stack_a, stack_b, 'a');
// 		else if ((*stack_a)->next->index > (*stack_a)->index
// 			&& (*stack_a)->next->index > (*stack_a)->previous->index)
// 			re_rotate_action(stack_a, stack_b, 'a');
// 	}
// }


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

void	sort_more(t_info *info_a, t_info *info_b)
{
	// if (info_a->head->index <= (info_a->size + info_b->size) / 2)
	// 	push_action(info_a, info_b, 'b');
	// else
	// 	rotate_action(info_a, info_b, 'a');
	// if (info_a->size > info_b->size)
	// 	sort_more(info_a, info_b);
	
	size_t	size = info_a->size + info_b->size;
	t_stack *temp;
	int	n;

	while (info_a->size > 3)
	{
		while (info_a->size > size / 2)
		{
			
			if (info_a->head->index <= info_a->size + info_b->size - size / 2)
				push_action(info_a, info_b, 'b');
			else
				rotate_action(info_a, info_b, 'a');
		}

		size = info_a->size;
	}
	sort_three(info_a, info_b, 'a');
	// while(info_b->size > 0)
	// {
	// 	n = 0;
	// 	while (info_b->head->index != info_b->size)
	// 	{
	// 		rotate_action(info_a, info_b, 'b');
	// 		n++;
	// 	}
	// 	if (info_b->head->index == info_b->size)
	// 	{
	// 		push_action(info_a, info_b, 'a');

	// 	}
	// 	while (n > 0)
	// 	{
	// 		re_rotate_action(info_a, info_b, 'b');
	// 		n--;
	// 	}
	// }
	int	fern = 0;
	while (info_b->size > 0)
	{
		fern = 0;
		temp = info_b->head;
		while (temp->index != info_b->size)
		{
			temp = temp->next;
			fern++;
		}
		if (fern < info_b->size / 2)
		{
			while (info_b->head->index != info_b->size)
				rotate_action(info_a, info_b, 'b');
			push_action(info_a, info_b, 'a');
		}
		else
		{
			while (info_b->head->index != info_b->size)
				re_rotate_action(info_a, info_b, 'b');
			push_action(info_a, info_b, 'a');
		}
	}


	


}