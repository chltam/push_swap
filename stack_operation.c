/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:25:22 by htam              #+#    #+#             */
/*   Updated: 2023/02/09 21:25:23 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	add_to_stack_bot(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (*stack == NULL)
		*stack = new;
	else
	{
		last = *stack;
		while (last && last->next)
			last = last->next;
		last->next = new;
		new->next = NULL;
	}
}

void	add_to_stack_top(t_stack **stack, t_stack *new)
{
	if (*stack == NULL)
		*stack = new;
	else
	{
		new->next = *stack;
		*stack = new;
	}
}

void	swap_node(t_stack **head, t_stack *second)
{
	if (!*head || !(*head)->next)
	{
		write(1, "here\n", 5);
		return ;
	}
	(*head)->next = second->next;
	second->next = *head;
	*head = second;

}