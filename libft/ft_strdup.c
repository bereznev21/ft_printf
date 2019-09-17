/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:54:00 by tlynesse          #+#    #+#             */
/*   Updated: 2018/11/29 23:27:56 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*res;
	size_t	len;
	size_t	i;

	len = 0;
	while (src[len])
		len++;
	res = (char*)malloc(len + 1);
	if (!res)
		return (0);
	i = 0;
	while (src[i])
	{
		res[i] = (char)src[i];
		i++;
	}
	res[i] = 0;
	return (res);
}
