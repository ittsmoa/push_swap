/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moatieh <moatieh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 05:31:11 by moatieh           #+#    #+#             */
/*   Updated: 2025/12/26 13:49:42 by moatieh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stack *a)
{
	t_node	*tmp;

	if (!a || a->size < 2)
		return (1);
	tmp = a->top;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int	handle_small_cases(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (a->top->value > a->top->next->value)
			sa(a);
		return (1);
	}
	if (a->size == 3)
	{
		sort_three(a);
		return (1);
	}
	if (a->size == 4 || a->size == 5)
	{
		sort_five(a, b);
		return (1);
	}
	return (0);
}

void	push_swap(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	if (handle_small_cases(a, b))
		return ;
	index_the_stack(a);
	push_all_chunks(a, b);
	push_back_to_a(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	init_stack(&a);
	init_stack(&b);
	fill_stack_a(&a, argc, argv);
	push_swap(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

void	print_stack(t_stack *s)
{
	t_node	*tmp;

	tmp = s->top;
	while (tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
}
