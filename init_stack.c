/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:59:41 by htam              #+#    #+#             */
/*   Updated: 2023/02/09 16:59:43 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	free_split(char **str)
{
	int	n;

	n = 0;
	while (str[n])
	{
		free(str[n]);
		n++;
	}
	free(str);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

void	free_and_exit(char **str, t_stack **stack)
{
	free_split(str);
	free_stack(stack);
	ft_error("ERROR");
}

t_stack	*init_stack(char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_tmp;
	char	**str;
	int		n;

	stack_a = NULL;
	while (*argv)
	{
		str = ft_split(*argv, ' ');
		n = 0;
		while (str[n])
		{
			if (!valid_input(str[n]))
				free_and_exit(str, &stack_a);
			stack_tmp = malloc(sizeof(t_stack));
			stack_tmp->number = ft_atol(str[n]);
			stack_tmp->next = NULL;
			add_to_stack_bot(&stack_a, stack_tmp);
			n++;
		}
		free_split(str);
		argv++;
	}
	return (stack_a);
}
