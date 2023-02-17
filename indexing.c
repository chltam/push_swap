/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:49:28 by htam              #+#    #+#             */
/*   Updated: 2023/02/14 16:49:29 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	index_count(t_stack *temp)
{
	long int	number;
	t_stack		*current;
	int			n;

	current = temp;
	number = current->number;
	n = 1;
	while (current->next != temp)
	{
		if (current->number < number)
			n++;
		current = current->next;
		if (current->next == temp)
			if (current->number < number)
				n++;
	}
	return (n);
}

size_t	set_index(t_stack *stack)
{
	t_stack		*temp;
	size_t		count;

	temp = stack;
	count = 0;
	while (temp->next != stack)
	{
		temp->index = index_count(temp);
		if (temp->index > count)
			count = temp->index;
		temp = temp->next;
		if (temp->next == stack)
			temp->index = index_count(temp);
		if (temp->index > count)
			count = temp->index;
	}
	return (count);
}
