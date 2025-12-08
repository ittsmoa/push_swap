/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moatieh <moatieh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 04:32:01 by moatieh           #+#    #+#             */
/*   Updated: 2025/12/08 04:32:01 by moatieh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sortThree(t_stack *a)
{
    int x;
    int y;
    int z;

    x = a->top->value;
    y = a->top->next->value;
    z = a->top->next->next->value;
    if (x < y && y < z)
        return;
    if (x > y && x < z)
        sa(a);
    else if (x > y && y > z)
    {
        sa(a);
        rra(a);
    }
    else if (x > z && y < z)
        ra(a);
    else if (x < y && x > z)
        rra(a);
    else
    {
        sa(a);
        ra(a);
    }
}

int findMinPos(t_stack *a)
{
    t_node *temp;
    int min;
    int pos;
    int i;

    temp = a->top;
    min = temp->value;
    pos = 0;
    i = 0;

    while (temp)
    {
        if (temp->value < min)
        {
            min = temp->value;
            pos = i;
        }
        temp = temp->next;
        i++;
    }
    return pos;
}

void    sortFive(t_stack *a, t_stack *b)
{
    int pos;

    while (a->size > 3)
    {
        pos = findMinPos(a);
        if (pos == 0)
            pb(a, b);
        else if (pos <= a->size / 2)
        {
            while(pos--)
                ra(a);
            pb(a, b);
        }
        else
        {
            pos = a->size - pos;
            while (pos--)
                rra(a);
            pb(a, b);
        }
    }
    sortThree(a);
    pa(a, b);
    pa(a, b);
}
