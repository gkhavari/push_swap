/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhavari <gkhavari@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:00:14 by gkhavari          #+#    #+#             */
/*   Updated: 2025/04/22 14:00:16 by gkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	index;

	if (s == NULL || f == NULL)
		return ;
	index = 0;
	while (s[index])
	{
		f(index, &s[index]);
		index++;
	}
}
/*
#include <stdio.h>
void switch_upper_lower(unsigned int i, char *c)
{
	if (i % 2)
		*c = ft_toupper(*c);
	else
		*c = ft_tolower(*c);
}

int main(void)
{
	char str[12] = "LoReM iPsUm";
	printf("Input:   %s\n", str);
	ft_striteri(str, &switch_upper_lower);
	printf("Output:  %s\n", str);
}*/