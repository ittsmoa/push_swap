/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moatieh <moatieh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 05:10:40 by moatieh           #+#    #+#             */
/*   Updated: 2025/12/03 05:10:40 by moatieh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	error_exit(void)
{
	int	i;
	int	num;

	i = argc - 1;
	while (i > 0)
	{
		num = atoi(argv[i]);
		t_node *new = create_node(num);
		push_top(a, new);
		i--;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10;
		nb = nb + nptr[i] - '0';
		i++;
	}
	return (nb * si);
}

static int	has_duplicate(t_stack *a, int value)
{
	t_node *current;

	current = a->top;
	while (current)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
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
			error_exit();

		new = create_node(num);
		if (!new)
			error_exit();

		push_top(a, new);
		i--;
	}
}


t_node *create_node(int value)
{
	t_node *new = malloc(sizeof(t_node));
	if(!new)
		return NULL;
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return new;
}

void init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->size = 0;
}

void	push_top(t_stack *stack, t_node *new)
{
	if (!new)
		return;
	new->next = stack->top;
	stack->top = new;
	stack->size++;
}


t_node *pop(t_stack *s)
{
    t_node *removed;

    if (!s || !s->top)
        return NULL;

    removed = s->top;
    s->top = s->top->next;
    removed->next = NULL;
    s->size--;

    return removed;
}

void print_stack(t_stack *s)
{
    t_node *tmp = s->top;

    while (tmp)
    {
        printf("%d\n", tmp->value);
        tmp = tmp->next;
    }
}

void free_stack(t_stack *s)
{
    t_node *tmp;

    while (s->top)
    {
        tmp = s->top->next;
        free(s->top);
        s->top = tmp;
    }
    s->size = 0;
}