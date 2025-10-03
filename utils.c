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
