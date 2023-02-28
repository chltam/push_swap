/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:39:02 by htam              #+#    #+#             */
/*   Updated: 2023/02/24 22:56:18 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_stack *stack)
{
	t_stack	*temp;
	int		max;

	temp = stack;
	max = 1;
	while (temp->next != stack)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	if (temp->index > max)
		max = temp->index;
	return (max);
}

int	is_rotate(t_info *info_a, t_info *info_b)
{
	t_stack	*temp;
	int		fern;

	fern = 0;
	temp = info_b->head;
	while (temp->next != info_b->head && temp->index != info_a->head->index - 1
		&& temp->index < info_a->head->previous->index)
	{
		temp = temp->next;
		fern++;
	}
	if (temp->index != info_a->head->index - 1
		&& temp->index < info_a->head->previous->index)
		fern++;
	return (fern);
}

void	reverse_or_not(t_info *info_a, t_info *info_b)
{
	if (is_rotate(info_a, info_b) <= info_b->size / 2)
	{
		rotate_action(info_a, info_b, 'b');
		if (info_a->head->previous->index == info_a->head->index - 1)
			re_rotate_action(info_a, info_b, 'a');
	}
	else
	{
		re_rotate_action(info_a, info_b, 'b');
		if (info_a->head->previous->index == info_a->head->index - 1)
			re_rotate_action(info_a, info_b, 'a');
	}
}

void	make_block(t_info *info_a, t_info *info_b, int limit)
{
	int	size;
	int	n;

	size = info_a->size + info_b->size;
	n = 0;
	while (info_a->size > 0)
	{	
		n += limit;
		while (info_a->head && info_b->size < n * 2)
		{
			if (info_a->head->index <= n)
				push_action(info_a, info_b, 'b');
			else if (info_a->head->index > size - n)
			{
				push_action(info_a, info_b, 'b');
				rotate_action(info_a, info_b, 'b');
			}
			else
				rotate_action(info_a, info_b, 'a');
		}
	}
	while (info_b->head->index != find_max(info_b->head))
		rotate_action(info_a, info_b, 'b');
	push_action(info_a, info_b, 'a');
}

void	sort_more(t_info *info_a, t_info *info_b, int limit)
{	
	make_block(info_a, info_b, limit);
	while (info_b->size > 0 || !is_sorted(info_a->head))
	{	
		if (info_a->head->previous->index == info_a->size + info_b->size)
		{
			push_action(info_a, info_b, 'a');
			if (info_a->head->index != info_a->head->next->index - 1)
				rotate_action(info_a, info_b, 'a');
		}
		if (info_a->head->previous->index == info_a->head->index - 1)
			re_rotate_action(info_a, info_b, 'a');
		if (!info_b->head)
			break ;
		if (info_b->head->index == info_a->head->index - 1
			|| info_b->head->index > info_a->head->previous->index)
		{
			push_action(info_a, info_b, 'a');
			if (info_a->head->index != info_a->head->next->index - 1)
				rotate_action(info_a, info_b, 'a');
		}
		else
			reverse_or_not(info_a, info_b);
	}
}
