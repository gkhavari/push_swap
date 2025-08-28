#include "push_swap.h"
#include <limits.h>

t_bool	int_overflow(int sign, int nbr, int digit)
{
	if (sign == 1 && (nbr > (INT_MAX - digit) / 10))
		return (true);
	if (sign == -1 && (-nbr < (INT_MIN + digit) / 10))
		return (true);
	return (false);
}

t_bool	is_int(char *input)
{
	int		nbr;
	int		sign;
	int		digit;
	size_t	i;

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
		if (int_overflow(sign, nbr, digit))
			return (false);
		nbr = nbr * 10 + digit;
		i++;
	}
	nbr = nbr * sign;
	if (input[i] != 0)
		return (false);
	return (true);
}

t_bool	is_unique(t_stack_node *stack, int nbr)
{
	while (stack != NULL)
	{
		if (stack->nbr == nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}
