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

stack *initialize_stack(char **args)
{
    size_t i;
    long nbr;

    i = 0;
    while (args[i])
    {
        nbr = ft_atoi(args[i]);
        if(nbr > INT_MAX || nbr < INT_MIN || ft_check(res, nbr) == 0)
        {
            ft_putstr_fd("Error\n", 2);
            return (NULL);
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    char **args;
    stack *stack_a;

    if (argc == 1)
        return (0);
    else if (argc == 2)
        args = &argv[1];
    else
        args = ft_split(argv[1], ' ');
    stack_a = (stack *) malloc(sizeof(stack));
    stack_a = initialize_stacks(args);
    print_stack(stack_a);
}
