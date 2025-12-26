/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moatieh <moatieh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 05:10:40 by moatieh           #+#    #+#             */
/*   Updated: 2025/12/26 13:45:05 by moatieh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	error_exit(t_stack *a)
{
	if (a)
		free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}

static int	has_duplicate(t_stack *a, int value)
{
	t_node	*current;

	current = a->top;
	while (current)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	long	nb;
	int		i;
	int		si;

	nb = 0;
	i = 0;
	si = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			si *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10;
		nb = nb + nptr[i] - '0';
		i++;
	}
	return (nb * si);
}

void	fill_stack_a(t_stack *a, int argc, char **argv)
{
	int		i;
	int		num;
	t_node	*new;

	i = argc - 1;
	while (i > 0)
	{
		num = ft_atoi(argv[i]);
		if (has_duplicate(a, num))
			error_exit(a);
		new = create_node(num);
		if (!new)
			error_exit(a);
		push_top(a, new);
		i--;
	}
}

t_node	*create_node(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->size = 0;
}

void	push_top(t_stack *stack, t_node *new)
{
	if (!new)
		return ;
	new->next = stack->top;
	stack->top = new;
	stack->size++;
}

t_node	*pop(t_stack *s)
{
	t_node	*removed;

	if (!s || !s->top)
		return (NULL);
	removed = s->top;
	s->top = s->top->next;
	removed->next = NULL;
	s->size--;
	return (removed);
}

void	free_stack(t_stack *s)
{
	t_node	*tmp;

	while (s->top)
	{
		tmp = s->top->next;
		free(s->top);
		s->top = tmp;
	}
	s->size = 0;
}
