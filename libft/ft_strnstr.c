/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 11:59:42 by tlynesse          #+#    #+#             */
/*   Updated: 2018/12/01 14:13:43 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		fl;
	size_t	i;
	size_t	j;
	size_t	needle_len;

	if (!haystack && !needle)
		return (0);
	if (!needle[0])
		return ((char*)haystack);
	fl = 1;
	i = 0;
	needle_len = ft_strlen(needle);
	while (fl && haystack[i] && i + needle_len <= len)
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
