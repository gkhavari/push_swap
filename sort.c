/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhavari <gkhavari@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 23:49:40 by gkhavari          #+#    #+#             */
/*   Updated: 2025/09/07 23:49:51 by gkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_bool	is_sorted(t_stack_node *stack)
{
	t_stack_node	*node;

	node = stack;
	while (node->next)
	{
		if (node->nbr > node->next->nbr)
			node = node->next;
		else
			return (false);
	}
	return (true);
}

void	do_the_sorting(t_stack_node **stack_a, t_stack_node **stack_b)
{
	size_t	size;
	size_t	max_bits;
	size_t	i;
	size_t	j;

	max_bits = 0;
	i = 0;
	size = get_size(*stack_a);
	while ((size - 1) >> max_bits)
		max_bits++;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*stack_a)->index >> i) & 1)
			{
				do_rotate(stack_a);
				ft_putstr_fd("ra\n", 1);
			}
			else
			{
				do_push(stack_a, stack_b);
				ft_putstr_fd("pb\n", 1);
			}
			j++;
		}
		while (*stack_b)
		{
			do_push(stack_b, stack_a);
			ft_putstr_fd("pa\n", 1);
		}
		i++;
	}
}
