/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:50:21 by htam              #+#    #+#             */
/*   Updated: 2023/02/06 19:50:22 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "push_swap.h"

// void	add_to_stack_top(t_stack **stack, t_stack *new)
// {
// 	new->next = *stack;
// 	*stack = new;
// }

int main()
{
	char	*str = NULL;

	printf("%s", str);

}
// void	swap_node(t_stack *node1, t_stack *node2)
// {
// 	t_stack	temp;

	
// 	temp.number = node1->number;
// 	temp.next = node1->next;
// 	node1->number = node2->number;
// 	node1->next = node2->next;
// 	*node2 = temp;


// }

// void	ft_error(char *str)
// {
// 	write(2, "\033[0;31m", 8);
// 	write(2, str, ft_strlen(str));
// 	write(2, "\033[0;39m", 8);
// 	write(2, "\n", 1);
// 	exit(EXIT_FAILURE);
// }

// int	valid_input(char *str)
// {
// 	while (*str)
// 	{
// 		if (*str == '+' || *str == '-')
// 			str++;
// 		if (ft_isdigit(*str) == 0)
// 			return (0);
// 		str++;
// 	}
// 	return (1);
// }

// void	add_to_stack(t_stack **stack, t_stack *new)
// {
// 	t_stack	*last;

// 	if (*stack == NULL)
// 		*stack = new;
// 	else
// 	{
// 		last = *stack;
// 		while (last && last->next)
// 			last = last->next;
// 		last->next = new;
// 	}
// }

// void	free_split(char **str)
// {
// 	int	n;

// 	n = 0;
// 	while (str[n])
// 	{
// 		free(str[n]);
// 		n++;
// 	}
// 	free(str);
// }

// void	free_stack(t_stack **stack)
// {
// 	t_stack	*temp;

// 	while (*stack)
// 	{
// 		temp = (*stack)->next;
// 		free(*stack);
// 		*stack = temp;
// 	}
// }

// int	main(int argc, char **argv)
// {
// 	char	**str;
// 	int		n;
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;
// 	t_stack *stack_tmp;

// 	stack_a = NULL;
// 	n = 0;

// 	argv++;
// 	while (*argv)
// 	{
// 		str = ft_split(*argv, ' ');
// 		n = 0;
// 		while(str[n])
// 		{
// 			if (!valid_input(str[n]))
// 			{
// 				free_split(str);
// 				free_stack(&stack_a);
// 				ft_error("input error");
// 			}
// 			stack_tmp = malloc(sizeof(t_stack));
// 			stack_tmp->number = ft_atoi(str[n]);
// 			stack_tmp->next = NULL;
// 			add_to_stack(&stack_a, stack_tmp);
// 			n++;
// 		}
// 		free_split(str);
// 		argv++;
// 	}
// 	stack_tmp = stack_a;
// 	while (stack_tmp)
// 	{
// 		printf("%d\n", stack_tmp->number);
// 		stack_tmp = stack_tmp->next;
// 	}

// 	free_stack(&stack_a);
	// while (stack_a)
	// {
	// 	stack_tmp = stack_a->next;
	// 	free(stack_a);
	// 	stack_a = stack_tmp;

	// }
	
// }

// int main(int argc, char **argv)
// {
// 	t_stack	*s1 = (t_stack *)malloc(sizeof(t_stack));
// 	t_stack s2;
// 	t_stack	s3;
// 	t_stack *stmp;

// 	s1->number = 1;
// 	s1->next = &s2;
// 	s2.number = 2;
// 	s2.next = &s3;
// 	s3.number = 3;
// 	s3.next = s1;

// 	stmp = s1;
// 	printf("stmp number = %d\n", stmp->number);
// 	swap_node(s1, &s3);
// 	printf("number of s1 = %d\n", s1->number);
// 	printf("number of s3 = %d\n", s3.number);
// 	char **str = ft_split(argv[1], ' ');
// 	int n = 0;
// 	while(str[n])
// 	{
// 		free(str[n]);
// 		n++;
// 	}
// 	free(str);

// }

// int main(int argc, char **argv)
// {

// 	int arr[] = {1, 9, 5, -20, -23, 7, 8, 99, 65, 85, -84, -3, -7, -54};

// 	int n = 0;
// 	int loop;
// 	int index = 0;

// 	while (n < 14)
// 	{
// 		loop = 0;
// 		index = 0;
// 		while (loop < 14)
// 		{
// 			if(arr[n] > arr[loop])
// 			{
// 				index++;
// 			}
// 			loop++;
// 		}
// 		printf("number %d is index %d\n", arr[n], index);
// 		n++;
// 	}
// 	if (argc == 2)
// 	{
// 		char **str = ft_split(argv[1], ' ');
// 	}

// }