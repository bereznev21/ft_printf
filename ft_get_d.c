/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:29:51 by rpoetess          #+#    #+#             */
/*   Updated: 2019/09/09 20:29:54 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*ft_get_d(char *str1, var *tmp, va_list str)
{
	size_t	nb;

	nb = 0;
	if (tmp->size1 == 'l')
	{
		if (tmp->size2 == 'l')
			nb = va_arg(str, long long int);
		else
			nb = va_arg(str, long int);
	}
	else if (tmp->size1 == 'h')
	{
		if (tmp->size2 == 'h')
			nb = (signed char)va_arg(str, int);
		else
			nb = (short int)va_arg(str, int);
	}
	else if (tmp->size1 == 'j')
		nb = va_arg(str, intmax_t);
	else if (tmp->size1 == 'z')
		nb = va_arg(str, size_t);
	else
	{
		nb = va_arg(str, int);
		if (nb == 0 && tmp->precision == 0 && tmp->precision_flag == 1)
			return ("");
	}
	str1 = ft_llitoa(nb, tmp);
	return (str1);
}
