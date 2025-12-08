/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moatieh <moatieh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 05:52:03 by moatieh           #+#    #+#             */
/*   Updated: 2025/12/05 05:52:03 by moatieh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int getChunkSize(int size)
{
    if (size <= 100)
        return (size / 5);
    else
        return (size / 11);
}

int isINChunk(int index, int start, int end)
{
    return (index >= start && index <= end);
}

int raOrRra(t_stack *a, int start, int end)
{
    t_node  *temp;
    int pos;

    temp = a->top;
    pos = 0;
    while (temp)
    {
        if (isINChunk(temp->index, start, end))
            break;
        pos++;
        temp = temp->next;
    }
    if (!temp)
        return 0;

    if (pos <= (a->size / 2))
        return 0;
    return 1;
}

int    chunkExistsInA(t_stack *a, int start, int end)
{
    t_node  *temp;

    temp = a->top;
    while (temp)
    {
        if (temp->index >= start && temp->index <= end)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void    pushChunkToB(t_stack *a, t_stack *b, int start, int end)
{
    while (chunkExistsInA(a, start, end))
    {
        moveChunkElementToTop(a, start, end);
        pb(a,b);
    }
}

void    moveChunkElementToTop(t_stack *a, int start, int end)
{
    int direction;

    direction = raOrRra(a, start, end);

    while (!isINChunk(a->top->index, start, end))
    {
        if (direction == 0)
            ra(a);
        else
            rra(a);
    }
}

void pushAllChunks(t_stack *a, t_stack *b)
{
    int chunk_size;
    int start;
    int end;

    if (!a || a->size == 0)
        return;
    chunk_size = getChunkSize(a->size);
    start = 0;
    end = chunk_size - 1;
    while (start < a->size)
    {
        if (end >= a->size)
            end = a->size - 1;
        pushChunkToB(a, b, start, end);
        start = end + 1;
        end = start + chunk_size - 1;
    }
}

