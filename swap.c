/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:44:20 by htam              #+#    #+#             */
/*   Updated: 2023/02/20 15:47:51 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_node(t_stack **head)
{
	t_stack	*second;

	if (!*head || (*head)->next == *head)
		return ;
	second = (*head)->next;
	(*head)->next = second->next;
	second->next->previous = *head;
	(*head)->previous->next = second;
	second->previous = (*head)->previous;
	second->next = *head;
	(*head)->previous = second;
	*head = second;
}

// void	swap_action(t_stack **stack_a, t_stack **stack_b, char flag)
// {
// 	if (flag == 'a')
// 	{
// 		swap_node(stack_a);
// 		ft_printf("sa\n");
// 	}
// 	else if (flag == 'b')
// 	{
// 		swap_node(stack_b);
// 		ft_printf("sb\n");
// 	}
// 	else if (flag == 's')
// 	{
// 		swap_node(stack_a);
// 		swap_node(stack_b);
// 		ft_printf("ss\n");
// 	}
// }

void	swap_action(t_info *info_a, t_info *info_b, char flag)
{
	if (flag == 'a')
	{
		swap_node(&info_a->head);
		ft_printf("sa\n");
	}
	else if (flag == 'b')
	{
		swap_node(&info_b->head);
		ft_printf("sb\n");
	}
	else if (flag == 's')
	{
		swap_node(&info_a->head);
		swap_node(&info_b->head);
		ft_printf("ss\n");
	}
}
