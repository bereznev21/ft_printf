/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 09:40:31 by tlynesse          #+#    #+#             */
/*   Updated: 2018/12/05 14:11:10 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	if (!s || len + 1 < len)
		return (0);
	if (!(res = (char*)malloc((len + 1) * sizeof(char))))
		return (0);
	i = 0;
	while (i < len)
	{
		res[i] = (char)s[start + i];
		i++;
	}
	res[i] = 0;
	return (res);
}
