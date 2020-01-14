/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 08:34:19 by syboeuf           #+#    #+#             */
/*   Updated: 2017/11/17 08:49:16 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_convert(int n, int i, int count, int k)
{
	char	*array;
	int		j;

	j = 0;
	while (n / i >= 10)
	{
		i = i * 10;
		count++;
	}
	if (!(array = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	if (k == 1)
		array[j++] = '-';
	while (i != 0)
	{
		array[j++] = (n / i) % 10 + '0';
		i = i / 10;
	}
	array[j] = '\0';
	return (array);
}

char			*ft_itoa(int n)
{
	int		i;
	int		count;
	int		j;
	int		k;

	i = 1;
	j = 0;
	count = 1;
	k = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		k = 1;
		n = -n;
		count++;
	}
	return (ft_convert(n, i, count, k));
}
