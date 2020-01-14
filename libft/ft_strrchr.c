/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:31:01 by syboeuf           #+#    #+#             */
/*   Updated: 2017/11/15 14:51:06 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	letter;

	letter = c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == letter)
			return ((char *)(s + i));
		i--;
	}
	return (0);
}
