/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moatieh <moatieh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 02:30:39 by moatieh           #+#    #+#             */
/*   Updated: 2025/11/30 02:30:39 by moatieh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// typedef struct s_node
// {
// 	int		value;
// 	int		index;
// 	struct s_node *next;
// } t_node;

// typedef	struct s_stack
// {
// 	t_node *top;
// 	int	size;
// } t_stack;

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

void	fill_stack_a(t_stack *a, int argc, char **argv)
{
	int	i = 1;
	while (i < argc)
	{
		int num;

		num = atoi(argv[i]);
		t_node *new = create_node(num);
		push_top(a, new);
		i++;
	}
}

t_node	*pop(t_stack *stack)
{
	if (stack->top == NULL)
		return NULL;
	t_node *removed = stack->top;
	stack->top = removed->next;
	removed->next = NULL;
	stack->size--;
	return removed;
}

int	main(int argc, char **argv)
{
	t_stack a;
	t_stack b;

	init_stack(&a);
	init_stack(&b);

	if (argc < 2)
		return 0;
	fill_stack_a(&a, argc, argv);
	t_node *tmp = a.top;
	while (tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}

	sa(&a);
	printf("After sa:\n");
	tmp = a.top; 
		while (tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}

	return 0;
}





