/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 07:55:58 by tlynesse          #+#    #+#             */
/*   Updated: 2018/11/26 13:56:35 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*pdst;
	char	*psrc;
	size_t	i;

	pdst = (char*)dst;
	psrc = (char*)src;
	if (pdst >= psrc && pdst <= psrc + len - 1)
	{
		i = len;
		while (i-- > 0)
			pdst[i] = psrc[i];
	}
	else
	{
		i = 0;
		while (i++ < len)
			*(pdst++) = *(psrc++);
	}
	return (dst);
}
