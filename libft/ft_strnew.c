/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 22:07:00 by tlynesse          #+#    #+#             */
/*   Updated: 2019/10/03 21:01:03 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if (size + 1 < size)
		return (0);
	str = 0;
	if (!(str = (char*)malloc(((++size) * sizeof(char)))))
		return (0);
	ft_bzero((void*)str, size);
	return (str);
}
