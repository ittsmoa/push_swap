/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moatieh <moatieh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 05:10:05 by moatieh           #+#    #+#             */
/*   Updated: 2025/12/03 05:10:05 by moatieh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void do_swap(t_stack *stack)
{
    int temp_value;
    int temp_index;

    if (!stack || stack->size < 2)
        return;
    temp_value = stack->top->value;
    temp_index = stack->top->index;
    stack->top->value = stack->top->next->value;
    stack->top->index = stack->top->next->index;
    stack->top->next->value = temp_value;
    stack->top->next->index = temp_index;
}

void    sa(t_stack *a)
{
    do_swap(a);
    write(1, "sa\n", 3);
}

void    sb(t_stack *b)
{
    do_swap(b);
    write(1, "sb\n", 3);
}

void    ss(t_stack *a, t_stack *b)
{
    do_swap(a);
    do_swap(b);
    write(1, "ss\n", 3);
}