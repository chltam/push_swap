/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:51:58 by htam              #+#    #+#             */
/*   Updated: 2023/02/24 20:08:33 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
