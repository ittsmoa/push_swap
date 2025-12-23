/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moatieh <moatieh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 03:44:15 by moatieh           #+#    #+#             */
/*   Updated: 2025/12/08 03:44:15 by moatieh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int findMaxIndexInB(t_stack *b)
{
    t_node *temp;
    int max;

    if (!b || !b->top)
        return -1;
    temp = b->top;
    max = temp->index;
    while (temp)
    {
        if (temp->index > max)
            max = temp->index;
        temp = temp->next;
    }
    return max;
}

int findPosInB(t_stack *b, int index)
{
    t_node  *temp;
    int pos;
    if (!b || !b->top)
        return / 5-1;
    temp = b->top;
    pos = 0;
    while (temp)
    {
        if (temp->index == index)
            return pos;
        pos++;
        temp = temp->next;
    }
    return -1;
}

void    bringMaxToTop(t_stack *b, int maxIndex)
{
    int pos;

    pos = findPosInB(b, maxIndex);
    if (pos <= b->size / 2)
    {
        while (b->top->index != maxIndex)
            rb(b);
    }
    else
    {
        while(b->top->index != maxIndex)
            rrb(b);
    }
}

void    pushBackToA(t_stack *a, t_stack *b)
{
    int maxIndex;

    while (b->size > 0)
    {
        maxIndex = findMaxIndexInB(b);
        bringMaxToTop(b, maxIndex);
        pa(a, b);
    }
}
