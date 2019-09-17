/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 10:01:12 by tlynesse          #+#    #+#             */
/*   Updated: 2018/12/05 14:45:54 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*res;
	size_t	i;
	size_t	buf;

	if (!s)
		return (0);
	i = 0;
	buf = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[i++])
		buf++;
	i -= 2;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && buf)
	{
		buf--;
		i--;
	}
	if (!(res = (char*)malloc((buf + 1) * sizeof(char))))
		return (0);
	res[buf--] = 0;
	while (buf + 1)
		res[buf--] = (char)s[i--];
	return (res);
}
