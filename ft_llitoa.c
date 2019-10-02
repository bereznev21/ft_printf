/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:23:56 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/02 22:27:44 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puting_lli_to_a(long long int n, char **res, size_t buf)
{
	while (n)
	{
		(*res)[--buf] = (char)(n % 10 + '0');
		n /= 10;
	}
}

char		*ft_llitoa(long long int nb, t_var *tmp)
{
	char			*res;
	long long int	k;
	size_t			buf;

	if (nb == 0)
		return ("0");
	tmp->arg_sign = (nb < 0) ? -1 : 1;
	nb = (nb > 0) ? nb : nb * (-1);
	buf = 1;
	k = nb;
	while (k)
	{
		buf++;
		k /= 10;
	}
	if (nb == (-9223372036854775807 - 1))
		return (ft_strdup("9223372036854775808"));
	if (!(res = (char*)malloc(buf * sizeof(char))))
		return (0);
	res[--buf] = 0;
	ft_puting_lli_to_a(nb, &res, buf);
	return (res);
}
