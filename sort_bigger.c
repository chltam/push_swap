/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bigger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:31:53 by htam              #+#    #+#             */
/*   Updated: 2023/02/24 18:52:57 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_clear(t_stack *stack, int n)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next != stack)
	{
		if (!((temp->index >> n) & 1))
			return (0);
		else
			temp = temp->next;
	}
	if (!((temp->index >> n) & 1))
		return (0);
	return (1);
}

int	pick_bit(t_info *info_a, t_info *info_b, int n)
{
	int	offset;

	offset = 0;
	while (!is_clear(info_a->head, n))
	{
		if (!((info_a->head->index >> n) & 1))
			push_action(info_a, info_b, 'b');
		else
		{
			rotate_action(info_a, info_b, 'a');
			offset++;
		}
	}
	return (offset);
}

void	radix_sort(t_info *info_a, t_info *info_b)
{
	int	count;
	int	n;
	int	offset;

	count = 0;
	while (find_max(info_a->head) >> count)
		count++;
	n = 0;
	while (n < count)
	{	
		offset = pick_bit(info_a, info_b, n);
		while (offset > 0)
		{
			re_rotate_action(info_a, info_b, 'a');
			offset--;
		}
		while (info_b->size > 0)
			push_action(info_a, info_b, 'a');
		n++;
	}
}
