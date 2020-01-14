/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 08:50:11 by syboeuf           #+#    #+#             */
/*   Updated: 2017/11/15 10:06:46 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	number;
	char			*stock;
	size_t			i;

	stock = s;
	number = c;
	i = 0;
	while (i < n)
	{
		stock[i] = number;
		i++;
	}
	return (s);
}
