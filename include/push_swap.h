/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhavari <gkhavari@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:26:19 by gkhavari          #+#    #+#             */
/*   Updated: 2025/08/25 16:26:22 by gkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef enum t_bool
{
	false = 0,
	true = 1
}	t_bool;

typedef struct t_stack_node
{
	int					nbr;
	size_t				index;
	struct t_stack_node	*next;
}	t_stack_node;

t_stack_node	*free_all(t_stack_node *stack_a, t_stack_node *stack_b,
					char **temp_split);
t_stack_node	*initialize_stack(char **argv);
void			assign_order(t_stack_node **stack);
t_bool			is_int(char *input);
t_bool			is_unique(t_stack_node *stack, int nbr);
void			do_push(t_stack_node **stack_from, t_stack_node **stack_to,
					char *output);
void			do_swap(t_stack_node **stack, char *output);
void			do_rotate(t_stack_node **stack, char *output);
void			do_rrotate(t_stack_node **stack, char *output);
void			do_the_sorting(size_t stack_size,
					t_stack_node **stack_a, t_stack_node **stack_b);
size_t			find_biggest(t_stack_node	*stack);
size_t			get_size(t_stack_node *stack);

#endif
