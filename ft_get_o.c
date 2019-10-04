/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:52:11 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/04 16:28:25 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_o(char *str1, t_var *tmp, va_list str)
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
	else if (tmp->size1 == 'j')
		nb = va_arg(str, uintmax_t);
	else if (tmp->size1 == 'z')
		nb = va_arg(str, size_t);
	else
		nb = va_arg(str, unsigned int);
	if (nb == 0)
	{
		/*
	ft_putchar('|');
	ft_putchar(tmp->flag);
	ft_putchar(tmp->flag_1);
	ft_putchar(tmp->flag2);
	ft_putchar('|');
	*/
		if (tmp->precision == 0 && tmp->precision_flag == 1)
		{
			return ("");
		}
		if (tmp->flag2 == '#')
			return ("");
	}
	str1 = ft_uitoa_base(nb, 8, tmp->type);
	return (str1);
}
