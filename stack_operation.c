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


t_stack	*last_node(t_stack *stack)
{
	t_stack *temp;

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
		new->previous = last; //double circular
	}
}

void	single_to_stack(t_stack **stack_out, t_stack **stack_in)
{
	(*stack_out)->next = *stack_in;
	(*stack_out)->previous = (*stack_in)->previous;
	(*stack_in)->previous->next = *stack_out;
	(*stack_in)->previous = *stack_out;
	*stack_in = *stack_out;
	*stack_out = NULL;
}

void	swap_node(t_stack **head)
{
	t_stack	*second;

	if (!*head || (*head)->next == *head)
	{
		printf("do nothing\n");
		return ;
	}
	second = (*head)->next;

	(*head)->next = second->next;
	second->next->previous = *head;
	(*head)->previous->next = second;
	second->previous = (*head)->previous;
	second->next = *head;
	(*head)->previous = second;
	*head = second;
}

void	push_stack(t_stack **stack_out, t_stack **stack_in)
{
	t_stack	*stack_out_second;

	if (!*stack_out)
		return ;

	if (!*stack_in)
	{
		if ((*stack_out)->next == *stack_out)
		{
			*stack_in = *stack_out;
			*stack_out = NULL;
		}
		else
		{
			(*stack_out)->next->previous = (*stack_out)->previous;
			(*stack_out)->previous->next = (*stack_out)->next;
			*stack_in = *stack_out;
			*stack_out = (*stack_out)->next;
			(*stack_in)->next = *stack_in;
			(*stack_in)->previous = *stack_in;
		}
	}
	else if ((*stack_out)->next == *stack_out)
	{
		// (*stack_out)->next = *stack_in;
		// (*stack_out)->previous = (*stack_in)->previous;
		// (*stack_in)->previous->next = *stack_out;
		// (*stack_in)->previous = *stack_out;
		// *stack_in = *stack_out;
		// *stack_out = NULL;

		// (*stack_out)->next->previous = (*stack_out)->previous;
		// (*stack_out)->previous->next = (*stack_out)->next;
		// (*stack_out)->previous = (*stack_in)->previous;
		// (*stack_in)->previous->next = (*stack_out);
		// *stack_out = (*stack_out)->next;
		// (*stack_in)->previous->next->next = *stack_in;
		// *stack_in = (*stack_in)->previous->next;
		// (*stack_in)->next->previous = *stack_in;

		single_to_stack(stack_out, stack_in);

	}
	else
	{
		(*stack_out)->next->previous = (*stack_out)->previous;
		(*stack_out)->previous->next = (*stack_out)->next;
		(*stack_out)->previous = (*stack_in)->previous;
		(*stack_in)->previous->next = (*stack_out);
		*stack_out = (*stack_out)->next;
		(*stack_in)->previous->next->next = *stack_in;
		*stack_in = (*stack_in)->previous->next;
		(*stack_in)->next->previous = *stack_in;

		// (*stack_out)->next = *stack_in;
		// (*stack_out)->previous = (*stack_in)->previous;
		// (*stack_in)->previous->next = *stack_out;
		// (*stack_in)->previous = *stack_out;
		// *stack_in = *stack_out;
		// *stack_out = NULL;
	}


	
}