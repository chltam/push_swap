/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:25:22 by htam              #+#    #+#             */
/*   Updated: 2023/02/13 20:18:01 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack	*last_node(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next != stack)
		temp = temp->next;
	return (temp);
}

void	add_to_stack_bot(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (*stack == NULL)
	{
		*stack = new;
		(*stack)->next = NULL;
	}
	else
	{
		last = *stack;
		while (last && last->next)
			last = last->next;
		last->next = new;
		new->next = NULL;
		new->previous = last;
	}
}
