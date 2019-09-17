/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 01:45:25 by tlynesse          #+#    #+#             */
/*   Updated: 2018/11/27 13:16:00 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			buf;
	char			*tmp;
	char			*res;

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
	i = 0;
	while (s[i])
	{
		tmp[i] = (*f)(i, s[i]);
		i++;
	}
	tmp[i] = 0;
	return (res);
}
