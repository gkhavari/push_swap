/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhavari <gkhavari@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:00:25 by gkhavari          #+#    #+#             */
/*   Updated: 2025/04/22 14:00:28 by gkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	len1;
	size_t	len2;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joined = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (joined == NULL)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		joined[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		joined[i] = s2[i - len1];
		i++;
	}
	joined[len1 + len2] = '\0';
	return (joined);
}
/*
#include <stdio.h>

typedef struct TestCase {
	char str1[1024];
	char str2[1024];
} TestCase;

int main(void)
{
	TestCase test_cases[] = {
		{.str1 = "Lorem ip", .str2 = "sum"},
		{.str1 = "", .str2 = "Lorem ipsum"},
		{.str1 = "Lorem ipsum", .str2 = ""},
		{.str1 = "", .str2 = ""}
	};
	size_t num_of_tests = sizeof(test_cases) / sizeof(test_cases[0]);
	size_t i = 0;
	while (i < num_of_tests)
	{
		printf("String 1:         %s\n", test_cases[i].str1);
		printf("String 2:         %s\n", test_cases[i].str2);
		printf("joined string:    %s\n\n", ft_strjoin(test_cases[i].str1, \
		test_cases[i].str2));
		i++;
	}
}*/
