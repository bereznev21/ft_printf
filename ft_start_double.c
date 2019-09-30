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

long double			ft_power(long double nb, int power)
{
	long double	s;

	s = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power-- > 1)
		nb = s * nb;
	return (nb);
}

float_struct	ft_create_double_list(float_struct tmp, long double n, int precision)
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
	tmp.mantisa = (n - (uintmax_t)n);
/*	ft_putchar('|');
	ft_putnbr(n * 1000000);
	ft_putchar('|');*/
	return (tmp);
}

float_struct	ft_create_double(long double n, int precision, var *var_struct)
{
	float_struct	tmp;

	tmp.zero_len = 0;
	tmp.mantisa_len = 0;
	tmp = ft_create_double_list(tmp, n, precision);
	while (tmp.mantisa_len < precision && tmp.mantisa > 0)
	{
		tmp.mantisa_len++;
		tmp.mantisa *= 10;
		if ((long long int)tmp.mantisa == 0)
			tmp.zero_len++;
	}
	if (tmp.zero_len > 0)
		tmp.mantisa_len = tmp.zero_len;
	else
		tmp.mantisa_len = precision;
	/*
	ft_putchar('|');
	ft_putnbr(tmp.mantisa_len);
	ft_putchar('|');
*/
	tmp.num = n;
	if (var_struct->arg_sign == -1)
	{
		tmp.base *= -1;
		tmp.mantisa *= -1;
	}
	return (tmp);
}

char			*ft_start_double(long double n, var *var_struct)
{
	float_struct	tmp;
	int				precision;
	int				len;
	long double		num;

	len = 0;
	//ft_putnbr(n);
	var_struct->arg_sign = (n < 0) ? -1 : 1;
	n = (n >= 0) ? n : n * (-1);
	num = n;
	precision = 0;
	if (!(var_struct->precision == 0 && var_struct->precision_flag == 1))
		precision = (var_struct->precision == 0) ? 6 : var_struct->precision;
/*	
	ft_putchar('|');
	ft_putnbr(precision);
	ft_putchar('|');
*/
	n += 0.5 * ft_power(0.1, precision);
	tmp = ft_create_double(n, precision, var_struct);
	tmp.res = ft_itoa((int)tmp.num);
	if (!(var_struct->precision == 0 && var_struct->precision_flag == 1))
	{
		
		tmp.res = ft_strjoin(tmp.res, ".");
		while (tmp.mantisa_len > 0 && tmp.zero_len > 0)
		{
			tmp.res = ft_strjoin(tmp.res, "0");
			tmp.mantisa_len--;
		}
		if ((long long int)tmp.mantisa > 0)
			tmp.res = ft_strjoin(tmp.res, ft_ullitoa((uintmax_t)tmp.mantisa, var_struct));
	}
	return (tmp.res);
}
