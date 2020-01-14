/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:23:05 by syboeuf           #+#    #+#             */
/*   Updated: 2017/11/15 10:05:50 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*source;
	char		*reception;
	size_t		i;

	i = 0;
	source = src;
	reception = dest;
	while (i < n)
	{
		reception[i] = source[i];
		i++;
	}
	dest = reception;
	return (dest);
}
