/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhavari <gkhavari@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:17:27 by gkhavari          #+#    #+#             */
/*   Updated: 2025/09/07 23:49:30 by gkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_push(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*temp;

	if (*stack_a == NULL)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
}

void	do_swap(t_stack_node **stack)
{
	t_stack_node	*temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}

void	do_rotate(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	last = *stack;
	*stack = (*stack)->next;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	do_rrotate(t_stack_node **stack)
{
	t_stack_node	*prev;
	t_stack_node	*last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}
