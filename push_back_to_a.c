/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moatieh <moatieh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 03:44:15 by moatieh           #+#    #+#             */
/*   Updated: 2025/12/26 13:50:48 by moatieh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_index_in_b(t_stack *b)
{
	t_node	*temp;
	int		max;

	if (!b || !b->top)
		return (-1);
	temp = b->top;
	max = temp->index;
	while (temp)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	return (max);
}

int	find_pos_in_b(t_stack *b, int index)
{
	t_node	*temp;
	int		pos;

	if (!b || !b->top)
		return (5 - 1);
	temp = b->top;
	pos = 0;
	while (temp)
	{
		if (temp->index == index)
			return (pos);
		pos++;
		temp = temp->next;
	}
	return (-1);
}

void	bring_max_to_top(t_stack *b, int max_index)
{
	int	pos;

	pos = find_pos_in_b(b, max_index);
	if (pos <= b->size / 2)
	{
		while (b->top->index != max_index)
			rb(b);
	}
	else
	{
		while (b->top->index != max_index)
			rrb(b);
	}
}

void	push_back_to_a(t_stack *a, t_stack *b)
{
	int	max_index;

	while (b->size > 0)
	{
		max_index = find_max_index_in_b(b);
		bring_max_to_top(b, max_index);
		pa(a, b);
	}
}
