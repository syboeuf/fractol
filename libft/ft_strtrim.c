/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:38:57 by syboeuf           #+#    #+#             */
/*   Updated: 2017/11/17 08:48:53 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_trim(char const *s, char *array, size_t i, size_t a)
{
	size_t	k;

	k = 0;
	while (s[k] == ' ' || s[k] == '\n' || s[k] == '\t')
		k++;
	if (k == a)
	{
		if (!(array = (char*)malloc(sizeof(char) * 1)))
			return (NULL);
		array[0] = '\0';
		return (array);
	}
	while (s[a - 1] == ' ' || s[a - 1] == '\n' || s[a - 1] == '\t')
		a--;
	if (!(array = (char*)malloc(sizeof(char) * (a - k + 1))))
		return (NULL);
	while (s[i + k] != '\0')
	{
		if (i + k == a)
			break ;
		array[i] = s[i + k];
		i++;
	}
	array[i] = '\0';
	return (array);
}

char			*ft_strtrim(char const *s)
{
	char	*array;
	size_t	i;
	size_t	k;
	size_t	a;

	array = NULL;
	if (s == NULL)
		return (NULL);
	i = 0;
	k = 0;
	a = ft_strlen(s);
	return (ft_trim(s, array, i, a));
}
