/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:58:08 by tlynesse          #+#    #+#             */
/*   Updated: 2018/12/01 16:38:02 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lendst;
	size_t	lensrc;

	lendst = ft_strlen((const char*)dst);
	lensrc = ft_strlen(src);
	i = 0;
	while ((i + lendst + 1) < size && src[i])
	{
		dst[lendst + i] = src[i];
		i++;
	}
	dst[lendst + i] = 0;
	if (size < lendst)
		return (lensrc + size);
	else
		return (lensrc + lendst);
}
