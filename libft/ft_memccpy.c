/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 07:37:52 by tlynesse          #+#    #+#             */
/*   Updated: 2018/11/30 02:33:25 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*pdst;
	unsigned char	*psrc;
	size_t			i;

	if (!dst && !src)
		return (0);
	pdst = (unsigned char*)dst;
	psrc = (unsigned char*)src;
	i = 0;
	while (i < n && psrc[i] != (unsigned char)c)
	{
		pdst[i] = psrc[i];
		i++;
	}
	if (psrc[i] == (unsigned char)c && i < n)
	{
		pdst[i] = psrc[i];
		i++;
		return ((void*)&pdst[i]);
	}
	return (0);
}
