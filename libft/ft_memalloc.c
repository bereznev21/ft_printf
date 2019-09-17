/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 09:57:09 by tlynesse          #+#    #+#             */
/*   Updated: 2018/11/30 04:58:47 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*res;
	size_t			i;

	if (!(res = (void*)malloc(size)))
		return (0);
	i = 0;
	while (i < size)
	{
		res[i] = 0;
		i++;
	}
	return (res);
}
