/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moatieh <moatieh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 05:11:14 by moatieh           #+#    #+#             */
/*   Updated: 2025/12/26 13:46:12 by moatieh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);
void				print_stack(t_stack *s);
t_node				*create_node(int value);
void				init_stack(t_stack *stack);
void				push_top(t_stack *stack, t_node *new_node);
t_node				*pop(t_stack *stack);
void				fill_stack_a(t_stack *a, int argc, char **argv);
void				free_stack(t_stack *s);
int					*stack_to_array(t_stack *a);
void				index_the_stack(t_stack *a);
void				sort_array(int *arr, int size);
void				apply_index_to_stack(t_stack *a, int *arr, int size);
int					find_max_index_in_b(t_stack *b);
int					find_pos_in_b(t_stack *b, int index);
void				bring_max_to_top(t_stack *b, int max_index);
void				push_back_to_a(t_stack *a, t_stack *b);
int					get_chunk_size(int size);
int					is_in_chunk(int index, int start, int end);
int					ra_or_rra(t_stack *a, int start, int end);
int					chunk_exists_in_a(t_stack *a, int start, int end);
void				push_chunk_to_b(t_stack *a, t_stack *b, int start, int end);
void				move_chunk_element_to_top(t_stack *a, int start, int end);
void				push_all_chunks(t_stack *a, t_stack *b);
void				sort_three(t_stack *a);
int					find_min_pos(t_stack *a);
void				sort_five(t_stack *a, t_stack *b);

#endif