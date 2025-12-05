/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moatieh <moatieh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 03:53:14 by moatieh           #+#    #+#             */
/*   Updated: 2025/12/05 03:53:14 by moatieh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *stackToArray(t_stack *a)
{
    int *arr;
    t_node	*temp;
	int	i;

	i = 0;
    arr = malloc(sizeof(int) * a->size);
	if (!arr)
		return NULL;
	temp = a->top;
	while(temp)
	{
		arr[i] = temp->value;
		temp =  temp->next;
		i++;
	}
	return arr;
}

void	indexTheStack(t_stack *a)
{
	int	*arr;

	arr = stackToArray(a);
	if (!arr)
		return;
	sortArray(arr, a->size);
	applyIndexToStack(a, arr, a->size);
	free (arr);
}

void    sortArray(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while(i < size - 1)
	{
		j = 0;
		while(j < size - i - 1)
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

void applyIndexToStack(t_stack *a, int *arr, int size)
{
	t_node *temp;
	int	i;

	temp = a->top;
	while(temp)
	{
		i = 0;
		while(i < size)
		{
			if (temp->value == arr[i])
			{
				temp->index = i;
				break;
			}
			i++;
		}
		temp = temp->next;
	}

}
