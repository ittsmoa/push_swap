/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moatieh <moatieh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 05:11:14 by moatieh           #+#    #+#             */
/*   Updated: 2025/12/03 05:11:14 by moatieh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_node
{
    int value;
    int index;
    struct s_node *next;
} t_node;

typedef struct s_stack
{
    t_node *top;
    int size;
} t_stack;

void    pa(t_stack *a, t_stack *b);
void    pb(t_stack *a, t_stack *b);
void    sa(t_stack *a);
void    sb(t_stack *b);
void    ss(t_stack *a, t_stack *b);
void    ra(t_stack *a);
void    rb(t_stack *b);
void    rr(t_stack *a, t_stack *b);
void    rra(t_stack *a);
void    rrb(t_stack *b);
void    rrr(t_stack *a, t_stack *b);
void    print_stack(t_stack *s);
t_node	*create_node(int value);
void	init_stack(t_stack *stack);
void	push_top(t_stack *stack, t_node *new);
t_node	*pop(t_stack *stack);
void	fill_stack_a(t_stack *a, int argc, char **argv);
void free_stack(t_stack *s);
void print_stack(t_stack *s);
int *stackToArray(t_stack *a);
void	indexTheStack(t_stack *a);
void    sortArray(int *arr, int size);
void applyIndexToStack(t_stack *a, int *arr, int size);


#endif