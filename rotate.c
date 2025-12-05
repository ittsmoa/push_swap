/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moatieh <moatieh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 05:08:08 by moatieh           #+#    #+#             */
/*   Updated: 2025/12/03 05:08:08 by moatieh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void doRotate(t_stack *s)
{
    t_node *f;
    t_node *l;

    if (!s || s->size < 2)
        return;
    f = s->top;
    s->top = s->top->next;
    l = s->top;
    while (l->next)
        l = l->next;
    l->next = f;
    f->next = NULL;
}

void ra(t_stack *a)
{
    doRotate(a);
    write(1, "ra\n", 3);
}

void rb(t_stack *b)
{
    doRotate(b);
    write(1, "rb\n", 3);
}

void rr(t_stack *a, t_stack *b)
{
    doRotate(a);
    doRotate(b);
    write(1, "rr\n", 3);
}