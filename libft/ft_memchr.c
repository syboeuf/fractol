/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:31:37 by syboeuf           #+#    #+#             */
/*   Updated: 2017/11/15 14:53:40 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		lettre;
	const unsigned char *array;

	i = 0;
	array = s;
	lettre = c;
	while (i < n)
	{
		if (array[i] == lettre)
			return ((void *)(array + i));
		i++;
	}
	return (NULL);
}
