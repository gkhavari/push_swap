#include "push_swap.h"

bool is_int(char *input)
{

}

bool is_unique(stack_node *stack, int nbr)
{
    while (stack)
    {
        if (stack->nbr == nbr)
            return (false);
        stack = stack->next;
    }
    return (true);
}