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

static t_bool	stack_is_sorted(t_stack_node *stack_a)
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

static void	free_stack(t_stack_node *stack)
{
	t_stack_node	*temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

t_stack_node	*free_all(t_stack_node *stack_a, t_stack_node *stack_b,
	char **temp_split)
{
	int	i;

	i = 0;
	if (temp_split)
	{
		while (temp_split[i])
		{
			free(temp_split[i]);
			i++;
		}
		free(temp_split);
	}
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	size_t			stack_size;

	stack_b = NULL;
	if (argc == 1)
		return (0);
	stack_a = initialize_stack(argv);
	if (stack_a == NULL)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack_size = get_size(stack_a);
	if (stack_size == 0)
		return (0);
	if (!stack_is_sorted(stack_a))
	{
		assign_order(&stack_a);
		do_the_sorting(stack_size, &stack_a, &stack_b);
	}
	free_all(stack_a, stack_b, NULL);
}
