/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:52:55 by rpoetess          #+#    #+#             */
/*   Updated: 2019/09/16 13:52:57 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_x(char *str1, var *tmp, va_list str)
{
	int long long	nb;

	nb = 0;
	if (tmp->size1 == 'h' && tmp->type != 'p')
	{
		if (tmp->size2 == 'h')
			nb = (unsigned char)va_arg(str, unsigned int);
		else
			nb = (unsigned short int)va_arg(str, unsigned int);
	}
	else if (tmp->size1 == 'j' && tmp->type != 'p')
		nb = va_arg(str, uintmax_t);
	else if ((tmp->size1 == 'z' || tmp->size1 == 'l') && tmp->type != 'p')
		nb = va_arg(str, size_t);
	else
	{
		nb = (unsigned int)va_arg(str, unsigned int);
		if (nb == 0 && tmp->precision == 0 && tmp->flag == '?' && tmp->precision_flag == 1)
			return ("");
	}
	if (nb == 0)
		return ("0");
	str1 = ft_uitoa_base(nb, 16, tmp->type);
	return (str1);
}
