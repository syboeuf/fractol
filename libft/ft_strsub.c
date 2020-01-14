/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:19:32 by syboeuf           #+#    #+#             */
/*   Updated: 2017/11/15 14:43:55 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*array;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	if (!(array = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		if (s[start] == '\0')
			return (0);
		array[i] = s[start];
		start++;
		i++;
	}
	array[i] = '\0';
	return (array);
}
