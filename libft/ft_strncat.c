/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:52:38 by tlynesse          #+#    #+#             */
/*   Updated: 2018/11/30 05:09:06 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*temp;

	temp = s1;
	while (*temp)
		temp++;
	while (*(s2) && n-- > 0)
		*(temp++) = *(s2++);
	*temp = 0;
	return (s1);
}
