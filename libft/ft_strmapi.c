/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhavari <gkhavari@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:01:18 by gkhavari          #+#    #+#             */
/*   Updated: 2025/04/22 14:01:20 by gkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	char			*result;
	unsigned int	index;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	index = 0;
	while (s[index])
	{
		result[index] = f(index, s[index]);
		index++;
	}
	result[index] = '\0';
	return (result);
}
/*
#include <stdio.h>
char	switch_upper_lower(unsigned int i, char c)
{
	if (i % 2)
		return(ft_toupper(c));
	else
		return (ft_tolower(c));
}

int main(void)
{
	char str[12] = "LoReM iPsUm";
	char *dest;
	dest = ft_strmapi(str, &switch_upper_lower);
	printf("Input   %s\n", str);
	printf("Output  %s\n", dest);
	free(dest);
}*/
