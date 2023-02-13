/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:34:51 by htam              #+#    #+#             */
/*   Updated: 2023/02/09 21:34:53 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

long int	ft_atol(const char *nptr)
{
	int			n;
	int			positiveflag;
	long int	rei;

	n = 0;
	positiveflag = 1;
	rei = 0;
	while ((nptr[n] >= 9 && nptr[n] <= 13) || nptr[n] == 32)
		n++;
	if (nptr[n] == '+' || nptr[n] == '-')
	{
		if (nptr[n] == '-')
			positiveflag *= -1;
		n++;
	}
	if (!ft_isdigit(nptr[n]))
		return (0);
	while (nptr[n] && ft_isdigit(nptr[n]))
	{
		rei = rei * 10 + nptr[n] - 48;
		n++;
	}
	return (rei * positiveflag);
}

int	valid_input(char *str)
{
	while (*str)
	{
		if (*str == '+' || *str == '-')
			str++;
		if (ft_isdigit(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}

void	valid_number(t_stack **stack)
{
	t_stack			*current;
	t_stack			*head;

	head = *stack;
	while (head)
	{
		if (head->number > INT_MAX)
		{
			free_stack(stack);
			ft_error("ERROR");
		}
		current = head->next;
		while (current)
		{
			if (head->number == current->number)
			{
				free_stack(stack);
				ft_error("ERROR");
			}
			current = current->next;
		}
		head = head->next;
	}
}
