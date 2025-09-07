/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhavari <gkhavari@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 23:48:43 by gkhavari          #+#    #+#             */
/*   Updated: 2025/09/07 23:48:48 by gkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

t_stack_node	*make_new_node(int nbr)
{
	t_stack_node	*new_node;

	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (new_node == NULL)
		return (NULL);
	new_node -> nbr = nbr;
	new_node -> index = 0;
	new_node -> next = NULL;
	return (new_node);
}

void	add_node_back(t_stack_node **stack, t_stack_node *new)
{
	t_stack_node	*tmp;

	tmp = *stack;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	while (tmp -> next != NULL)
		tmp = tmp -> next;
	tmp -> next = new;
}

void	free_stack(t_stack_node *stack)
{
	t_stack_node	*temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

t_stack_node	*free_all(t_stack_node *stack, char **temp_split, int i)
{
	free(temp_split[i]);
	free(temp_split);
	free_stack(stack);
	return (NULL);
}
