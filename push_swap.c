/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moatieh <moatieh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 05:31:11 by moatieh           #+#    #+#             */
/*   Updated: 2025/12/08 05:31:11 by moatieh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moatieh <moatieh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 05:08:24 by moatieh           #+#    #+#             */
/*   Updated: 2025/12/03 05:08:24 by moatieh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static int	is_sorted(t_stack *a)
{
	t_node *tmp;

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
		sortThree(a);
		return (1);
	}
	if (a->size == 4 || a->size == 5)
	{
		sortFive(a, b);
		return (1);
	}
	return (0);
}

void	push_swap(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return;

	if (handle_small_cases(a, b))
		return;

	indexTheStack(a);

	pushAllChunks(a, b);   // كل chunk تروح على B

	pushBackToA(a, b);     //   A مرتّبة
}

// my main main
// int	main(int argc, char **argv)
// {
// 	t_stack	a;
// 	t_stack	b;

// 	if (argc < 2)
// 		return (0);

// 	init_stack(&a);
// 	init_stack(&b);

// 	fill_stack_a(&a, argc, argv);  // تحويل argv إلى stack A

// 	push_swap(&a, &b);             // تنفيذ الخوارزمية كاملة

// 	free_stack(&a);                // مهم جداً لمنع الـ LEAKS!!!
// 	free_stack(&b);

// 	return (0);
// }

int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;

    if (argc < 2)
        return (0);

    init_stack(&a);
    init_stack(&b);

    fill_stack_a(&a, argc, argv);

    // Print BEFORE sorting
    printf("=== BEFORE SORT ===\n");
    print_stack(&a);
    printf("===================\n\n");

    // Call your push_swap algorithm
    push_swap(&a, &b);

    // Print AFTER sorting
    printf("=== AFTER SORT ===\n");
    print_stack(&a);
    printf("==================\n");

    // Free stacks
    free_stack(&a);
    free_stack(&b);

    return 0;
}
