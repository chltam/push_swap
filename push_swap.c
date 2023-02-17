/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:57:20 by htam              #+#    #+#             */
/*   Updated: 2023/02/16 23:16:35 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_error(char *str)
{
	write(2, "\033[0;31m", 8);
	write(2, str, ft_strlen(str));
	write(2, "\033[0;39m", 8);
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

void	print_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_a = stack_a;
	temp_b = stack_b;

	if (temp_a)
		temp_a->previous->next = NULL;
	if (temp_b)
		temp_b->previous->next = NULL;
	while (temp_a || temp_b)
	{
		if (temp_a)
		{
			printf("%ld(%d)   ", temp_a->number, temp_a->index);
			temp_a = temp_a->next;
		}
		else
			printf("    ");
		if (temp_b)
		{
			printf("%ld(%d)\n", temp_b->number, temp_b->index);
			temp_b = temp_b->next;
		}
		else
			printf("\n");
	}
	if (stack_a)
		stack_a->previous->next = stack_a;
	if (stack_b)
		stack_b->previous->next = stack_b;

	printf("-----------\n");
	printf(" a      b\n");
	printf("\n");
}

int	is_sorted(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	stack->previous->next = NULL;
	while (stack)
	{
		
		if (stack->next && stack->next->number < stack->number)
		{
			temp->previous->next = temp;
			return (0);
		}
		stack = stack->next;
	}
	temp->previous->next = temp;
	return (1);
}

void	size_matter(t_stack **stack_a, t_stack **stack_b, size_t size)
{
	if (size == 1)
		return ;
	if (size == 2)
		swap_action(stack_a, stack_b, 'a');
	if (size == 3)
		sort_three(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = init_stack(&argv[1]);
	stack_b = NULL;
	valid_number(&stack_a);
	make_circle(&stack_a);
	size_t n = set_index(stack_a);

	if (!is_sorted(stack_a))
	{
		size_matter(&stack_a, &stack_b, set_index(stack_a));
	}

	print_stack(stack_a, stack_b);
	free_stack(&stack_a);
	return (0);
}
