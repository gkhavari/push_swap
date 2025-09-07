/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhavari <gkhavari@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:26:08 by gkhavari          #+#    #+#             */
/*   Updated: 2025/09/07 23:49:16 by gkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

t_bool	stack_is_sorted(t_stack_node *stack_a)
{
	if (!stack_a)
		return (true);
	while (stack_a->next != NULL)
	{
		if ((stack_a->next->nbr) < (stack_a->nbr))
			return (false);
		stack_a = stack_a->next;
	}
	return (true);
}

t_stack_node	*initialize_stack(char **argv)
{
	size_t			i;
	size_t			j;
	char			**temp_split;
	t_stack_node	*stack;

	i = 1;
	stack = NULL;
	while (argv[i])
	{
		temp_split = ft_split(argv[i], ' ');
		if (!temp_split)
			return (NULL);
		i++;
		j = 0;
		while (temp_split[j])
		{
			if (!is_int(temp_split[j]) || !is_unique(stack, ft_atoi(temp_split[j])))
				return (free_all(stack, temp_split, j));
			add_node_back(&stack, make_new_node(ft_atoi(temp_split[j])));
			free(temp_split[j]);
			j++;
		}
		free(temp_split);
	}
	return (stack);
}

void	assign_order(t_stack_node **stack)
{
	size_t			stack_size;
	size_t			i;
	int				min_nbr;
	t_stack_node	*node;

	i = 1;
	stack_size = get_size(*stack);
	min_nbr = find_min(*stack);
	node = *stack;
	while (i < stack_size)
	{
		node = find_next_bigger(*stack, min_nbr);
		node->index = i;
		min_nbr = node->nbr;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	stack_b = NULL;
	if (argc == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	stack_a = initialize_stack(argv);
	if (stack_a == NULL)
		write(2, "Error\n", 6);
	else if (!stack_is_sorted(stack_a))
	{
		assign_order(&stack_a);
		do_the_sorting(&stack_a, &stack_b);
	}
	free_stack(stack_a);
}
