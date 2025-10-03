/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhavari <gkhavari@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 23:49:59 by gkhavari          #+#    #+#             */
/*   Updated: 2025/09/07 23:50:03 by gkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

size_t	find_biggest(t_stack_node	*stack)
{
	t_stack_node	*temp;
	size_t			max_value;

	max_value = 0;
	temp = stack;
	while (temp)
	{
		if (max_value < temp->index)
			max_value = temp-> index;
		temp = temp->next;
	}
	return (max_value);
}

size_t	get_size(t_stack_node *stack)
{
	size_t			size;
	t_stack_node	*temp;

	size = 0;
	temp = stack;
	while (temp)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}

int	find_min(t_stack_node *stack)
{
	int				min;
	t_stack_node	*node;

	node = stack;
	min = node->nbr;
	while (node)
	{
		if (node->nbr < min)
			min = node->nbr;
		node = node->next;
	}
	return (min);
}

t_stack_node	*find_next_bigger(t_stack_node *stack, int min_nbr)
{
	int				new_min;
	t_stack_node	*node;
	t_stack_node	*res;

	new_min = INT_MAX;
	node = stack;
	res = NULL;
	while (node)
	{
		if (node->nbr > min_nbr && node->nbr <= new_min)
		{
			new_min = node->nbr;
			res = node;
		}
		node = node->next;
	}
	return (res);
}
