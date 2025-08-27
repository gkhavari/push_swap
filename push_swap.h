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

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef enum
{
    false = 0,
    true = 1
} bool;

typedef struct stack_node
{
    int nbr;
    size_t index;
    struct stack_node *next;
}   stack_node;

#endif
