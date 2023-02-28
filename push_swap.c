/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:57:20 by htam              #+#    #+#             */
/*   Updated: 2023/02/24 19:16:03 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*
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
			printf("       ");
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
*/
void	ft_error(char *str)
{
	write(2, "\033[0;31m", 8);
	write(2, str, ft_strlen(str));
	write(2, "\033[0;39m", 8);
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

int	is_sorted(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return (0);
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

void	size_matter(t_info *info_a, t_info *info_b)
{
	if (info_a->size == 1)
		return ;
	if (info_a->size == 2)
		swap_action(info_a, info_b, 'a');
	if (info_a->size == 3)
		sort_three(info_a, info_b, 'a');
	if (info_a->size == 4)
		sort_four(info_a, info_b);
	if (info_a->size == 5)
		sort_five(info_a, info_b);
	if (info_a->size > 5 && info_a->size <= 10)
		sort_more(info_a, info_b, 1);
	if (info_a->size > 10 && info_a->size < 1700)
		sort_more(info_a, info_b, 0.0875 * info_a->size + 6);
	if (info_a->size >= 1700)
		radix_sort(info_a, info_b);
	while (!is_sorted(info_a->head))
		re_rotate_action(info_a, info_b, 'a');
}

int	main(int argc, char **argv)
{
	t_info	info_a;
	t_info	info_b;

	if (argc == 1)
		return (0);
	info_a.head = init_stack(&argv[1]);
	valid_number(&info_a.head);
	make_circle(&info_a.head);
	set_index(info_a.head);
	info_a.size = count_node(info_a.head);
	info_b.head = NULL;
	info_b.size = count_node(info_b.head);
	if (!is_sorted(info_a.head))
		size_matter(&info_a, &info_b);
	free_stack(&info_a.head);
	free_stack(&info_b.head);
	return (0);
}
