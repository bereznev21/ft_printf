/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:19:54 by tlynesse          #+#    #+#             */
/*   Updated: 2018/12/09 17:37:57 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcdel(char *s, char c)
{
	char	*res;
	size_t	i;
	size_t	len;

	if (!s || !c)
		return (0);
	i = 0;
	len = 1;
	while (s[i])
		if (s[i++] != c)
			len++;
	if (!(res = (char*)malloc(len * sizeof(char))))
		return (0);
	i = 0;
	while (*s)
	{
		if (*s != c)
			res[i++] = *s;
		s++;
	}
	res[i] = 0;
	return (res);
}
