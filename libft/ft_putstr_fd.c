/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhavari <gkhavari@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:59:04 by gkhavari          #+#    #+#             */
/*   Updated: 2025/04/22 13:59:07 by gkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	index;

	if (s == NULL)
		return ;
	index = 0;
	while (s[index] != '\0')
	{
		write(fd, &s[index], 1);
		index++;
	}
}
/*
int main(void)
{
	ft_putstr_fd("lorem ipsum dolor sit amet\n", 2);
	ft_putstr_fd("  lorem\nipsum\rdolor\tsit amet  \n", 1);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("lorem ipsum do\0lor sit amet\n", 1);
}*/
