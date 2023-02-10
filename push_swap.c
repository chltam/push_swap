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
	while (stack_a || stack_b)
	{
		printf("%ld\n", stack_a->number);
		stack_a = stack_a->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	
	stack_a = init_stack(&argv[1]);
	
	stack_b = NULL;
	valid_number(&stack_a);
	
	t_stack	*tmp = stack_a;
	//swap_node(&stack_a, stack_a->next);
	print_stack(stack_a, stack_b);
	
	
	free_stack(&stack_a);


}