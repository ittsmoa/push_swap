/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moatieh <moatieh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 05:52:03 by moatieh           #+#    #+#             */
/*   Updated: 2025/12/26 13:48:24 by moatieh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size(int size)
{
	if (size <= 100)
		return (size / 5);
	else
		return (size / 11);
}

int	is_in_chunk(int index, int start, int end)
{
	return (index >= start && index <= end);
}

int	ra_or_rra(t_stack *a, int start, int end)
{
	t_node	*temp;
	int		pos;

	temp = a->top;
	pos = 0;
	while (temp)
	{
		if (is_in_chunk(temp->index, start, end))
			break ;
		pos++;
		temp = temp->next;
	}
	if (!temp)
		return (0);
	if (pos <= (a->size / 2))
		return (0);
	return (1);
}

int	chunk_exists_in_a(t_stack *a, int start, int end)
{
	t_node	*temp;

	temp = a->top;
	while (temp)
	{
		if (temp->index >= start && temp->index <= end)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	push_chunk_to_b(t_stack *a, t_stack *b, int start, int end)
{
	while (chunk_exists_in_a(a, start, end))
	{
		move_chunk_element_to_top(a, start, end);
		pb(a, b);
	}
}

void	move_chunk_element_to_top(t_stack *a, int start, int end)
{
	int	direction;

	direction = ra_or_rra(a, start, end);
	while (!is_in_chunk(a->top->index, start, end))
	{
		if (direction == 0)
			ra(a);
		else
			rra(a);
	}
}

void	push_all_chunks(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	start;
	int	end;
	int	max_index;

	if (!a || a->size == 0)
		return ;
	max_index = a->size - 1;
	chunk_size = get_chunk_size(a->size);
	start = 0;
	end = start + chunk_size - 1;
	while (start <= max_index)
	{
		if (end >= max_index)
			end = max_index;
		push_chunk_to_b(a, b, start, end);
		start = end + 1;
		end = start + chunk_size - 1;
	}
}
