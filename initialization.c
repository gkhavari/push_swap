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

static t_stack_node	*make_new_node(int nbr)
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

static void	add_node_back(t_stack_node **stack, t_stack_node *new)
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

static t_stack_node	*find_next_bigger(t_stack_node *stack, int min_nbr)
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

t_stack_node	*initialize_stack(char **argv)
{
	size_t			i;
	size_t			j;
	char			**temp_split;
	t_stack_node	*stack;
	t_stack_node	*new_node;

	i = 1;
	stack = NULL;
	while (argv[i])
	{
		temp_split = ft_split(argv[i++], ' ');
		if (!temp_split)
			return (free_stack(stack), NULL);
		j = 0;
		while (temp_split[j])
		{
			new_node = make_new_node(ft_atoi(temp_split[j]));
			if (!is_int(temp_split[j])
				|| !is_unique(stack, ft_atoi(temp_split[j++])) || !new_node)
				return (free_all(stack, temp_split), NULL);
			add_node_back(&stack, new_node);
		}
		free_all(NULL, temp_split);
	}
	return (stack);
}

void	assign_order(t_stack_node **stack)
{
	size_t			stack_size;
	size_t			i;
	int				min_nbr;
	t_stack_node	*node;

	i = 0;
	stack_size = get_size(*stack);
	min_nbr = INT_MIN;
	node = *stack;
	while (i < stack_size)
	{
		node = find_next_bigger(*stack, min_nbr);
		if (node == NULL)
			return ;
		node->index = i;
		min_nbr = node->nbr;
		i++;
	}
}
