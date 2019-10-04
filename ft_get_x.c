/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:52:55 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/04 15:10:07 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_x(char *str1, t_var *tmp, va_list str)
{
	int long long	nb;

	nb = 0;
	if (tmp->size1 == 'h')
	{
		if (tmp->size2 == 'h')
			nb = (unsigned char)va_arg(str, unsigned int);
		else
			nb = (unsigned short int)va_arg(str, unsigned int);
	}
	else if (tmp->size1 == 'j')
		nb = va_arg(str, uintmax_t);
	else if ((tmp->size1 == 'z' || tmp->size1 == 'l'))
		nb = va_arg(str, size_t);
	else
	{
		nb = (unsigned int)va_arg(str, unsigned int);
		if (!nb && !tmp->precision && tmp->flag == '?' && tmp->precision_flag)
			return ("");
	}
	if (nb == 0 && tmp->type != 'p')
		return ("");
	str1 = ft_uitoa_base(nb, 16, tmp->type);
	return (str1);
}
