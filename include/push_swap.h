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


t_stack_node	*make_new_node(int nbr);
void	add_node_back(t_stack_node **stack, t_stack_node *new);
void	free_stack(t_stack_node *stack);
t_stack_node	*free_all(t_stack_node *stack, char **temp_split, int i);
t_bool	int_overflow(int sign, int nbr, int digit);
t_bool	is_int(char *input);
t_bool	is_unique(t_stack_node *stack, int nbr);
void	do_the_sorting(t_stack_node **stack_a, t_stack_node **stack_b);
void	do_push(t_stack_node **stack_a, t_stack_node **stack_b);
void	do_rotate(t_stack_node **stack);
size_t get_size(t_stack_node *stack);
t_stack_node *find_next_bigger(t_stack_node *stack, int min_nbr);
int find_min(t_stack_node *stack);



#endif
