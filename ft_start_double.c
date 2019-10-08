/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:17:18 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/08 15:49:32 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double		ft_power(long double nb, int power)
{
	long double		s;

	s = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power-- > 1)
		nb = s * nb;
	return (nb);
}

t_float_struct	ft_create_double_list(t_float_struct tmp,
long double n, int precision)
{
	long double		num;

	num = n;
	tmp.power = 1;
	tmp.mantisa_len = 0;
	tmp.res = ft_strdup("");
	while (num > 10)
	{
		num = num / 10;
		tmp.power++;
	}
	tmp.base = num;
	tmp.mantisa = (n - (uintmax_t)n);
	return (tmp);
}

t_float_struct	ft_create_double(long double n,
int precision, t_var *var_struct)
{
	t_float_struct	tmp;

	tmp.zero_len = 0;
	tmp.mantisa_len = 0;
	n += 0.5 * ft_power(0.1, precision);
	tmp = ft_create_double_list(tmp, n, precision);
	while (tmp.mantisa_len < precision)
	{
		tmp.mantisa_len++;
		tmp.mantisa *= 10;
		if ((intmax_t)tmp.mantisa == 0)
			tmp.zero_len++;
	}
	if (tmp.zero_len > 0)
		tmp.mantisa_len = tmp.zero_len;
	else
		tmp.mantisa_len = precision;
	tmp.num = n;
	if (n < 0)
	{
		tmp.base *= -1;
		tmp.mantisa *= -1;
	}
	return (tmp);
}

char			*ft_start_double(long double n, t_var *var_struct)
{
	t_float_struct	tmp;
	int				precision;
	int				len;
	char			*str;

	len = 0;
	var_struct->arg_sign = (n < 0) ? -1 : 1;
	n = (n < 0) ? -n : n;
	precision = 0;
	if (!(var_struct->precision == 0 && var_struct->precision_flag == 1))
		precision = (var_struct->precision == 0) ? 6 : var_struct->precision;
	tmp = ft_create_double(n, precision, var_struct);
	tmp.res = ft_itoa_base((intmax_t)tmp.num, 10, var_struct);
	if (!(var_struct->precision == 0 && var_struct->precision_flag == 1))
	{
		tmp.res = ft_strjoin_right(tmp.res, ".");
		while (tmp.mantisa_len > 0 && tmp.zero_len > 0)
		{
			tmp.res = ft_strjoin_right(tmp.res, "0");
			tmp.mantisa_len--;
		}
		if ((long long int)tmp.mantisa > 0)
		{
			str = tmp.res;
			tmp.res = ft_strjoin_left(tmp.res,
			ft_ullitoa((uintmax_t)tmp.mantisa, var_struct));
			free(str);
		}
	}
	return (tmp.res);
}