/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 02:05:57 by tlynesse          #+#    #+#             */
/*   Updated: 2018/12/01 14:02:01 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		fl;
	size_t	i;
	size_t	j;

	if (!haystack && !needle)
		return (0);
	if (!needle[0])
		return ((char*)haystack);
	fl = 1;
	i = 0;
	while (fl && haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j] && haystack[i + j])
			j++;
		if (!needle[j])
			return ((char*)&haystack[i]);
		else if (!haystack[i + j])
			fl = 0;
		i++;
	}
	return (0);
}
