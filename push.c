/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moatieh <moatieh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 05:08:24 by moatieh           #+#    #+#             */
/*   Updated: 2025/12/26 10:56:37 by moatieh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_node	*n;

	if (b->top == NULL)
		return ;
	n = pop(b);
	push_top(a, n);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*n;

	if (a->top == NULL)
		return ;
	n = pop(a);
	push_top(b, n);
	write(1, "pb\n", 3);
}
