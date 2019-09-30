/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:52:11 by rpoetess          #+#    #+#             */
/*   Updated: 2019/09/21 05:43:25 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_o(char *str1, var *tmp, va_list str)
{
	intmax_t	nb;

	nb = 0;
	if (tmp->size1 == 'l')
		nb = va_arg(str, unsigned long long int);
	else if (tmp->size1 == 'h')
	{
		if (tmp->size2 == 'h')
			nb = (unsigned char)va_arg(str, int);
		else
			nb = (unsigned short int)va_arg(str, int);
	}
	else
	{
		nb = va_arg(str, unsigned int);
	}
	if (nb == 0)
	{
		
		if (tmp->precision == 0 && tmp->precision_flag == 1)
			return ("");
		if (tmp->flag2 == '#')
			return ("");
		/*
		if (tmp->flag == '0' && tmp->flag2 == '#' && tmp->flag_1 == '?')
			return ("");
		if (tmp->precision_flag == 0)
		{
			if (tmp->flag == '?' && tmp->flag2 == '#' && tmp->flag_1 == '?')
				return ("");
			if (tmp->flag == '-' && tmp->flag2 == '#' && tmp->flag_1 == '?')
				return ("");
			if (tmp->flag == '?' && tmp->flag2 == '#' && tmp->flag_1 == '0')
				return ("");
		}
		if (tmp->precision_flag == 1)
		{
			if (tmp->flag == '-' && tmp->flag2 == '#' && tmp->flag_1 == '?')
				return ("");
			if (tmp->flag == '?' && tmp->flag2 == '#' && tmp->flag_1 == '0')
				return ("");
			if (tmp->flag == '?' && tmp->flag2 == '#' && tmp->flag_1 == '?')
				return ("");
		}*/
	}
	str1 = ft_itoa_base(nb, 8, tmp->type);
	return (str1);
}
