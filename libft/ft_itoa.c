/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 23:23:01 by tlynesse          #+#    #+#             */
/*   Updated: 2018/12/09 16:58:43 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	puting_i_to_a(int n, char **res, size_t buf)
{
	unsigned int	k;

	k = (n < 0 ? -n : n);
	while (k)
	{
		(*res)[--buf] = (char)(k % 10 + '0');
		k /= 10;
	}
}

char		*ft_itoa(int n)
{
	char	*res;
	int		k;
	size_t	buf;

	if (!n)
		return (ft_strdup("0"));
	buf = 1;
	if (n < 0)
		buf++;
	k = n;
	while (k)
	{
		buf++;
		k /= 10;
	}
	if (!(res = (char*)malloc(buf * sizeof(char))))
		return (0);
	res[--buf] = 0;
	if (n < 0)
		*res = '-';
	puting_i_to_a(n, &res, buf);
	return (res);
}
