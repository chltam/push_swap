/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:39:02 by htam              #+#    #+#             */
/*   Updated: 2023/02/23 22:49:04 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_stack *stack)
{
	t_stack	*temp;
	int		max;

	temp = stack;
	max = 1;
	while(temp->next != stack)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	if (temp->index > max)
	max = temp->index;
	return (max);
}

int	find_min(t_stack *stack)
{
	t_stack	*temp;
	int		min;

	temp = stack;
	min = 2147483647;
	while(temp->next != stack)
	{
		if (temp->index < min)
			min = temp->index;
		temp = temp->next;
	}
	if (temp->index < min)
	min = temp->index;
	return (min);
}



int	is_rotate(t_stack *stack, int limit)
{
	t_stack *temp;
	int		n;
	int		p;

	temp = stack;
	n = 0;
	p = 0;
	while (temp->next != stack && temp->index > limit && temp->index <= 500 - limit)
	{
		temp = temp->next;
		n++;
	}
	temp = stack;
	while (temp->next != stack && temp->index > limit && temp->index <= 500 - limit)
	{
		temp = temp->previous;
		p++;
	}
	if (n <= p)
		return (1);
	else
		return (0);
}

void	make_block(t_info *info_a, t_info *info_b)
{
	int	size;
	int	n;

	size = info_a->size + info_b->size;
	n = 0;
	while (info_a->size > 0)
	{
		
		n += size / 10;
		while (info_a->head && info_b->size < n * 2)
		{
			if (info_a->head->index <= n)
				push_action(info_a, info_b, 'b');
			else if (info_a->head->index > size - n)
			{
				push_action(info_a, info_b, 'b');
				rotate_action(info_a, info_b, 'b');
			}
			else
				rotate_action(info_a, info_b, 'a');

		}
	}
}

void	sort_more(t_info *info_a, t_info *info_b)
{
	size_t	size = info_a->size + info_b->size;
	t_stack *temp;
	int	n = 0;
	int	fern = 0;
	int	count;
	count = 0;

	make_block(info_a, info_b);


	// while (info_a->size > 0)
	// {
	// 	n += size / 10;
	// 	while (info_b->size < n * 2)
	// 	{
	// 		if (info_a->head->index <= n)
	// 			push_action(info_a, info_b, 'b');
	// 		else if (info_a->head->index > size - n)
	// 		{
	// 			push_action(info_a, info_b, 'b');
	// 			rotate_action(info_a, info_b, 'b');
	// 		}
	// 		else
	// 		{
	// 			rotate_action(info_a, info_b, 'a');
	// 		}
	// 	}
	// }



	while (info_b->head->index != find_max(info_b->head))
		rotate_action(info_a, info_b, 'b');
	push_action(info_a, info_b, 'a');



	while (info_b->size > 0 || !is_sorted(info_a->head))
	{
		
		if (info_a->head->previous->index == info_a->size + info_b->size)
		{
			push_action(info_a, info_b, 'a');
			rotate_action(info_a, info_b, 'a');
		}
		if(info_a->head->previous->index == info_a->head->index - 1)
			re_rotate_action(info_a, info_b, 'a');
		if (!info_b->head)
			break ;
		if (info_b->head->index == info_a->head->index - 1 || info_b->head->index > info_a->head->previous->index)
		{
			push_action(info_a, info_b, 'a');
			if (info_a->head->index != info_a->head->next->index - 1)
				rotate_action(info_a, info_b, 'a');

		}
		else
		{

			fern = 0;
			temp = info_b->head;
			while (temp->next != info_b->head && temp->index != info_a->head->index - 1 && temp->index < info_a->head->previous->index)
			{

				temp = temp->next;
				fern++;
			}
			if (temp->index != info_a->head->index - 1 && temp->index < info_a->head->previous->index)
				fern++;

			if (fern <= info_b->size / 2)
			{

					rotate_action(info_a, info_b, 'b');
					if(info_a->head->previous->index == info_a->head->index - 1)
						re_rotate_action(info_a, info_b, 'a');

				
			}
			else if (fern > info_b->size / 2)
			{
					re_rotate_action(info_a, info_b, 'b');
					if(info_a->head->previous->index == info_a->head->index - 1)
						re_rotate_action(info_a, info_b, 'a');

				
			}

		}
			
	}
	
	while (!is_sorted(info_a->head))
		re_rotate_action(info_a, info_b, 'a');

/*------------------------------------------------------------*/
	
	// while (info_b->size > size / 2)
	// {
	// 	if (info_b->head->index <= size / 2)
	// 		push_action(info_a, info_b, 'a');
		
	// 	else
	// 		rotate_action(info_a, info_b, 'b');	
	// 	printf("here\n");
	// }

	
	// while (info_b->size > 0)
	// 	push_action(info_a, info_b, 'a');

/*radix*/

	// while (find_max(info_a->head) >> count)
	// 	count++;
	// n = 0;
	// int	test = 0;
	// while (n < count)
	// {	
	// 	test = 0;
	// 	while (!is_clear(info_a->head, n))
	// 	{
	// 		if (!((info_a->head->index >> n) & 1))
	// 			push_action(info_a, info_b, 'b');
	// 		else
	// 		{
	// 			rotate_action(info_a, info_b, 'a');
	// 			test++;
	// 		}
	// 	}
	// 	while (test > 0)
	// 	{
	// 		re_rotate_action(info_a, info_b, 'a');
	// 		test--;
	// 	}
	// 	while (info_b->size > 0)
	// 		push_action(info_a, info_b, 'a');
	// 	n++;

	// }
/*radix*/

	// sort_three(info_a, info_b, 'a');

	// size = info_a->size + info_b->size;
	// while (info_b->size > 0)
	// {
	// 	while (info_b->size > size / 2)
	// 	{
	// 		if (info_b->head->index > info_b->size / 2)
	// 			push_action(info_a, info_b, 'a');
	// 		else
	// 			rotate_action(info_a, info_b, 'b');
	// 	}
	// 	size = info_b->size;

	// }
	

	// while (info_b->size > 0)
	// {
	// 	fern = 0;
	// 	temp = info_b->head;
	// 	while (temp->index != info_b->size)
	// 	{
	// 		temp = temp->next;
	// 		fern++;
	// 	}
	// 	if (fern < info_b->size / 2)
	// 	{
	// 		while (info_b->head->index != info_b->size)
	// 			rotate_action(info_a, info_b, 'b');
	// 		push_action(info_a, info_b, 'a');
	// 	}
	// 	else
	// 	{
	// 		while (info_b->head->index != info_b->size)
	// 			re_rotate_action(info_a, info_b, 'b');
	// 		push_action(info_a, info_b, 'a');
	// 	}
	// }

}