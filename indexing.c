/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moatieh <moatieh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 03:53:14 by moatieh           #+#    #+#             */
/*   Updated: 2025/12/26 13:34:39 by moatieh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_to_array(t_stack *a)
{
	int		*arr;
	t_node	*temp;
	int		i;

	i = 0;
	arr = malloc(sizeof(int) * a->size);
	if (!arr)
		return (NULL);
	temp = a->top;
	while (temp)
	{
		arr[i] = temp->value;
		temp = temp->next;
		i++;
	}
	return (arr);
}

void	index_the_stack(t_stack *a)
{
	int	*arr;

	arr = stack_to_array(a);
	if (!arr)
		return ;
	sort_array(arr, a->size);
	apply_index_to_stack(a, arr, a->size);
	free(arr);
}

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	apply_index_to_stack(t_stack *a, int *arr, int size)
{
	t_node	*temp;
	int		i;

	temp = a->top;
	while (temp)
	{
		i = 0;
		while (i < size)
		{
			if (temp->value == arr[i])
			{
				temp->index = i;
				break ;
			}
			i++;
		}
		temp = temp->next;
	}
}
