/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:57:20 by htam              #+#    #+#             */
/*   Updated: 2023/02/08 16:57:22 by htam             ###   ########.fr       */
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
			printf("%ld   ", temp_a->number);
			temp_a = temp_a->next;
		}
		else
			printf("|    ");
		if (temp_b)
		{
			printf("%ld\n", temp_b->number);
			temp_b = temp_b->next;
		}
		else
			printf("\n");
	}
	if (stack_a)
		stack_a->previous->next = stack_a;
	if (stack_b)
		stack_b->previous->next = stack_b;

	printf("------\n");
	printf("a   b\n");
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = init_stack(&argv[1]);
	stack_b = NULL; //test stack_b need set back to NULL
	//stack_b = init_stack(&argv[1]);

	valid_number(&stack_a);
	make_circle(&stack_a);
	
	// t_stack	*tmp = stack_a;
	//printf("last number b4 swap = %ld\n", tmp->number);
	 swap_node(&stack_a);
	 push_action(&stack_a, &stack_b, 'b');
	 push_action(&stack_a, &stack_b, 'b');
	// push_action(&stack_a, &stack_b, 'b');
	// swap_action(&stack_a, &stack_b, 'a');
	// print_stack(stack_a, stack_b);
	// rotate_action(&stack_a, &stack_b, 'b');
	 rotate_action(&stack_a, &stack_b, 'r');
	print_stack(stack_a, stack_b);
	


	
	
	
	free_stack(&stack_a);
	free_stack(&stack_b);
}