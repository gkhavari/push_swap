#include "push_swap.h"
#include <limits.h>

bool    is_int(char *input)
{
    int nbr;
    int sign;
    int digit;
    size_t i;

    sign = 1;
    i = 0;
    nbr = 0;
    if (input[i] == '-' || input[i] == '+')
    {
        if (input[i] == '-')
            sign = -1;
        i++;
    }
    if (!(input[i] >= '0' && input[i] <= '9'))
        return (false);
    while (input[i] >= '0' && input[i] <= '9')
    {
        digit = input[i] - '0';
        if (sign == 1 && (nbr > (INT_MAX - digit) / 10))
            return false;
        if (sign == -1 && (-nbr < (INT_MIN + digit) / 10))
            return false;
        nbr = nbr * 10 + digit;
        i++;
    }
    nbr = nbr * sign;
    if (input[i] != 0)
        return (false);
    return (true);
}

bool    is_unique(stack_node *stack, int nbr)
{
    while (stack)
    {
        if (stack->nbr == nbr)
            return (false);
        stack = stack->next;
    }
    return (true);
}