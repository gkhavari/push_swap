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
#include "libft.h"

void	do_push(t_stack_node **stack_from, t_stack_node **stack_to,
			char *output)
{
	t_stack_node	*temp;

	if (*stack_from == NULL)
		return ;
	temp = *stack_from;
	*stack_from = (*stack_from)->next;
	temp->next = *stack_to;
	*stack_to = temp;
	ft_putstr_fd(output, 1);
}

void	do_swap(t_stack_node **stack, char *output)
{
	t_stack_node	*temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	ft_putstr_fd(output, 1);
}

void	do_rotate(t_stack_node **stack, char *output)
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
	ft_putstr_fd(output, 1);
}

void	do_rrotate(t_stack_node **stack, char *output)
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
	ft_putstr_fd(output, 1);
}
