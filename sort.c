#include "push_swap.h"
#include "libft.h"

t_bool	is_sorted(t_stack_node **stack)
{
	t_stack_node *node;

	node = *stack;
	while(node->next)
	{
		if (node->nbr < node->next->nbr)
			node = node->next;
		else
			return false;
	}
	return true;
}

void	do_the_sorting(t_stack_node **stack_a, t_stack_node **stack_b)
{
	size_t size_stack;
	size_t sig_digits;

	sig_digits = 0;

	write(1, "Test2\n", 6);
	while (sig_digits < 32)
	{
		size_stack = get_size(*stack_a);
		while (size_stack--)
		{
			if(*stack_b == NULL && is_sorted(stack_a))
				return ;
			if (((*stack_a)->index>>sig_digits & 1) == 1)
			{
				do_rotate(stack_a); //ra
				ft_putstr_fd("ra\n", 1);
			}
			else
			{
				do_push(stack_a, stack_b); //pb
				ft_putstr_fd("pb\n", 1);
			}
		}
		while(*stack_b)
		{
			do_push(stack_b, stack_a); //pa
			ft_putstr_fd("pa\n", 1);
		}
		sig_digits++;
	}
}