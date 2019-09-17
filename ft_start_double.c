/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:17:18 by rpoetess          #+#    #+#             */
/*   Updated: 2019/09/03 17:17:20 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

float			ft_power(float nb, int power)
{
	float	s;

	s = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power-- > 1)
		nb = s * nb;
	return (nb);
}

float_struct	ft_create_double_list(float_struct tmp, long double n)
{
	long double		num;

	num = n;
	tmp.power = 1;
	tmp.mantisa_len = 0;
	tmp.res = ft_strnew(0);
	while (num > 10)
	{
		num = num / 10;
		tmp.power++;
	}
	tmp.base = num;
	tmp.mantisa = n - (long double)(long int)n;
	return (tmp);
}

float_struct	ft_create_double(long double n, int precision)
{
	float_struct	tmp;

	tmp.mantisa_len = 0;
	tmp = ft_create_double_list(tmp, n);
	precision = (precision > 6) ? 6 : precision;
	if (precision > 0)
		tmp.mantisa += 0.5 * ft_power(0.1, precision);
	while (tmp.mantisa_len < 6)
	{
		tmp.mantisa_len++;
		tmp.mantisa *= 10;
	}
	tmp.num = n;
	if (n < 0)
	{
		tmp.base *= -1;
		tmp.mantisa *= -1;
	}
	return (tmp);
}

char			*ft_start_double(long double n, int precision)
{
	float_struct	tmp;
	int				wdth;

	wdth = (tmp.mantisa_len) ? (tmp.mantisa_len) : 0;
	tmp = ft_create_double(n, precision);
	tmp.res = ft_strjoin(tmp.res, ft_itoa((int)tmp.num));
	if (tmp.mantisa != 0)
	{
		tmp.res = ft_strjoin(tmp.res, ".");
		if ((int)ft_strlen(ft_itoa((int)tmp.mantisa)) < tmp.mantisa_len)
			while ((int)ft_strlen(ft_itoa((int)tmp.mantisa)) < tmp.mantisa_len--)
				tmp.res = ft_strjoin(tmp.res, "0");
		tmp.res = ft_strjoin(tmp.res, ft_itoa((int)tmp.mantisa));
	}
	return (tmp.res);
}
