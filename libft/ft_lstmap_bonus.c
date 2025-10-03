/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhavari <gkhavari@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:55:34 by gkhavari          #+#    #+#             */
/*   Updated: 2025/05/01 19:45:25 by gkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_lst(t_list *lst)
{
	t_list	*temp;

	while (lst)
	{
		temp = lst;
		lst = lst -> next;
		if (temp -> content != NULL)
			free(temp -> content);
		free(temp);
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_element;

	if (f == NULL)
		return (NULL);
	new_lst = NULL;
	new_element = NULL;
	while (lst)
	{
		new_element = (t_list *)ft_lstnew(f(lst -> content));
		if (new_element == NULL)
		{
			if (del != NULL)
				ft_lstclear(&new_lst, del);
			else
				free_lst(new_lst);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_element);
		lst = lst -> next;
	}
	return (new_lst);
}
