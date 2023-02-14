/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:13:25 by htam              #+#    #+#             */
/*   Updated: 2023/02/13 20:13:27 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	single_to_stack(t_stack **stack_out, t_stack **stack_in)
{
	(*stack_out)->next = *stack_in;
	(*stack_out)->previous = (*stack_in)->previous;
	(*stack_in)->previous->next = *stack_out;
	(*stack_in)->previous = *stack_out;
	*stack_in = *stack_out;
	*stack_out = NULL;
}

void	stack_to_stack(t_stack **stack_out, t_stack **stack_in)
{
	(*stack_out)->next->previous = (*stack_out)->previous;
	(*stack_out)->previous->next = (*stack_out)->next;
	(*stack_out)->previous = (*stack_in)->previous;
	(*stack_in)->previous->next = (*stack_out);
	*stack_out = (*stack_out)->next;
	(*stack_in)->previous->next->next = *stack_in;
	*stack_in = (*stack_in)->previous->next;
	(*stack_in)->next->previous = *stack_in;
}

void	push_stack(t_stack **stack_out, t_stack **stack_in)
{
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
		single_to_stack(stack_out, stack_in);
	else
		stack_to_stack(stack_out, stack_in);
}

void	push_action(t_stack **stack_a, t_stack **stack_b, char flag)
{
	if (flag == 'a')
	{
		push_stack(stack_b, stack_a);
		ft_printf("pa\n");
	}
	else if (flag == 'b')
	{
		push_stack(stack_a, stack_b);
		ft_printf("pb\n");
	}
}