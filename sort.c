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

void	sort_two_three(t_stack_node **stack_a)
{
	size_t	max_value;

	max_value = find_biggest(*stack_a);
	if ((*stack_a)->index == max_value)
		do_rotate(stack_a, "ra\n");
	if ((*stack_a)->next->index == max_value)
	{
		do_rrotate(stack_a, "rra\n");
	}
	if ((*stack_a)->index > (*stack_a)->next->index)
	{
		do_swap(stack_a, "sa\n");
	}
}

void	sort_four_five(t_stack_node **stack_a, t_stack_node **stack_b)
{
	size_t	pushed;

	pushed = 0;
	while (pushed < 2)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
		{
			do_push(stack_a, stack_b, "pb\n");
			pushed++;
		}
		else
			do_rotate(stack_a, "ra\n");
	}
	sort_two_three(stack_a);
	do_push(stack_b, stack_a, "pa\n");
	do_push(stack_b, stack_a, "pa\n");
	if ((*stack_a)->index != 0)
		do_swap(stack_a, "sa\n");
}

void	sort_small_stack(t_stack_node **stack_a, t_stack_node **stack_b)
{
	size_t	stack_size;

	stack_size = get_size(*stack_a);
	if (stack_size <= 3)
		sort_two_three(stack_a);
	else
		sort_four_five(stack_a, stack_b);
}

void	sort_big_stack(t_stack_node **stack_a, t_stack_node **stack_b)
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
				do_rotate(stack_a, "ra\n");
			else
				do_push(stack_a, stack_b, "pb\n");
			j++;
		}
		while (*stack_b)
			do_push(stack_b, stack_a, "pa\n");
		i++;
	}
}
