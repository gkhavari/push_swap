/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhavari <gkhavari@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:26:08 by gkhavari          #+#    #+#             */
/*   Updated: 2025/08/25 16:26:11 by gkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

bool	stack_is_sorted(stack_node *stack_a)
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

stack_node *initialize_stack(char **argv)
{
    size_t i;
    size_t j;
    char **temp_split;
    stack_node *stack;

    i = 1;
    stack = NULL;
    while (argv[i])
    {
        temp_split = ft_split(argv[i], ' ');
        i++;
        j = 0;
        while (temp_split[j])
        {
            if(!is_int(temp_split[j]) || !is_unique(stack, ft_atoi(temp_split[j])))
                return(free_all(stack, temp_split, j));
            add_node_back(&stack, new_node((int)ft_atoi(temp_split[j])));
            free(temp_split[j]);
            j++;
        }
        free(temp_split);
    }
    return (stack);
}

int main(int argc, char **argv)
{
    stack_node *stack_a;
    stack_node *stack_b;

    if (argc == 1)
    {
        ft_putstr_fd("Error\n", 2);
        return (0);
    }
    stack_a = initialize_stack(argv);
    if (stack_a == NULL)
		write(2, "Error\n", 6);
	else
		do_the_sorting(stack_a, stack_b);
}
