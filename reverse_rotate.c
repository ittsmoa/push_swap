/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moatieh <moatieh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 05:08:12 by moatieh           #+#    #+#             */
/*   Updated: 2025/12/03 05:08:12 by moatieh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    doReverseRotate(t_stack *s)
{
    t_node  *last;
    t_node  *prev;

    if(!s || s->size < 2)
        return;
    last = s->top;
    prev = NULL;
    while(last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = s->top;
    s->top = last;
}

void    rra(t_stack *a)
{
    doReverseRotate(a);
    write(1, "rra\n", 4);
}

void    rrb(t_stack *b)
{
    doReverseRotate(b);
    write(1, "rrb\n", 4);
}

void    rrr(t_stack *a, t_stack *b)
{
    doReverseRotate(a);
    doReverseRotate(b);
    write(1, "rrr\n", 1);
}