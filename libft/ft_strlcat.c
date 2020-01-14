/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 18:18:28 by syboeuf           #+#    #+#             */
/*   Updated: 2017/11/16 08:40:32 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t dest_size;
	size_t src_size;
	size_t i;

	i = 0;
	src_size = ft_strlen(src);
	dest_size = ft_strlen(dest);
	if (dest_size > size)
		return (src_size + size);
	while ((dest_size + i) < (size - 1) && src[i])
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[dest_size + i] = '\0';
	return (src_size + dest_size);
}
