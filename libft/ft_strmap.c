/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 01:04:26 by tlynesse          #+#    #+#             */
/*   Updated: 2018/11/27 13:13:21 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	buf;
	char	*tmp;
	char	*res;

	if (!s || !f)
		return (0);
	buf = 0;
	tmp = (char*)s;
	while (*(tmp++))
		buf++;
	res = (char*)malloc((buf + 1) * sizeof(char));
	if (!res)
		return (0);
	tmp = res;
	while (*s)
		*(tmp++) = (*f)(*(s++));
	res[buf] = 0;
	return (res);
}
