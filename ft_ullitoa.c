/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:01:05 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/02 22:30:36 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puting_ulli_to_a(uintmax_t n, char **res, size_t buf)
{
	while (n)
	{
		(*res)[--buf] = (char)(n % 10 + '0');
		n /= 10;
	}
}

char		*ft_ullitoa(uintmax_t nb, t_var *tmp)
{
	char					*res;
	unsigned long long int	k;
	size_t					buf;

	if (nb == 0)
		return (ft_strdup("0"));
	buf = 1;
	k = nb;
	while (k)
	{
		buf++;
		k /= 10;
	}
	if (!(res = (char*)malloc(buf * sizeof(char))))
		return (0);
	res[--buf] = 0;
	ft_puting_ulli_to_a(nb, &res, buf);
	return (res);
}
