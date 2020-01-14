/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:03:42 by syboeuf           #+#    #+#             */
/*   Updated: 2017/11/16 11:37:03 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*array;
	t_list	*list;

	if (lst == NULL)
		return (NULL);
	list = f(lst);
	array = list;
	if (list == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		array->next = f(lst);
		if (array->next == NULL)
			return (NULL);
		array = array->next;
	}
	return (list);
}
