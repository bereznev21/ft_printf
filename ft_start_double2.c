/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:37:15 by rpoetess          #+#    #+#             */
/*   Updated: 2019/09/25 20:37:17 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

float_struct	ft_create_double_list(float_struct tmp, long double n)
{
	tmp.num = (int)n;
	tmp.mantisa = n - tmp.num;
	ft_putnbr(tmp.mantisa);
	return (tmp);
}

float_struct	ft_create_double(long double n, var *var_struct)
{
	float_struct	tmp;
	int				len;

	tmp = ft_create_double_list(tmp, n);
	return (tmp);
}

char			*ft_start_double(long double n, var *var_struct)
{
	float_struct	tmp;
	int				wdth;

	var_struct->arg_sign = (n < 0) ? -1 : 1;
	n = (n < 0) ? -n : n;
	tmp = ft_create_double(n, var_struct);
	tmp.res = ft_strjoin(tmp.res, ft_itoa((int)tmp.num));
	return (tmp.res);
}
