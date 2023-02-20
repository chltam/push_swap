/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:51:58 by htam              #+#    #+#             */
/*   Updated: 2023/02/20 15:48:13 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	rotate_action(t_stack **stack_a, t_stack **stack_b, char flag)
// {
// 	if (flag == 'a' && *stack_a)
// 	{
// 		*stack_a = (*stack_a)->next;
// 		ft_printf("ra\n");
// 	}
// 	else if (flag == 'b' && *stack_b)
// 	{
// 		*stack_b = (*stack_b)->next;
// 		ft_printf("rb\n");
// 	}
// 	else if (flag == 'r' && *stack_a && *stack_b)
// 	{
// 		*stack_a = (*stack_a)->next;
// 		*stack_b = (*stack_b)->next;
// 		printf("rr\n");
// 	}
// 	else
// 		return ;
// }

void	rotate_action(t_info *info_a, t_info *info_b, char flag)
{
	if (flag == 'a' && info_a->head)
	{
		info_a->head = (info_a->head)->next;
		ft_printf("ra\n");
	}
	else if (flag == 'b' && info_b->head)
	{
		info_b->head = (info_b->head)->next;
		ft_printf("rb\n");
	}
	else if (flag == 'r' && info_a->head && info_b->head)
	{
		info_a->head = (info_a->head)->next;
		info_b->head = (info_b->head)->next;
		printf("rr\n");
	}
	else
		return ;
}

// void	re_rotate_action(t_stack **stack_a, t_stack **stack_b, char flag)
// {
// 	if (flag == 'a' && *stack_a)
// 	{
// 		*stack_a = (*stack_a)->previous;
// 		ft_printf("rra\n");
// 	}
// 	else if (flag == 'b' && *stack_b)
// 	{
// 		*stack_b = (*stack_b)->previous;
// 		ft_printf("rrb\n");
// 	}
// 	else if (flag == 'r' && *stack_a && *stack_b)
// 	{
// 		*stack_a = (*stack_a)->previous;
// 		*stack_b = (*stack_b)->previous;
// 		ft_printf("rrr\n");
// 	}
// 	else
// 		return ;
// }

void	re_rotate_action(t_info *info_a, t_info *info_b, char flag)
{
	if (flag == 'a' && info_a->head)
	{
		info_a->head = (info_a->head)->previous;
		ft_printf("rra\n");
	}
	else if (flag == 'b' && info_b->head)
	{
		info_b->head = (info_b->head)->previous;
		ft_printf("rrb\n");
	}
	else if (flag == 'r' && info_a->head && info_b->head)
	{
		info_a->head = (info_a->head)->previous;
		info_b->head = (info_b->head)->previous;
		printf("rrr\n");
	}
	else
		return ;
}