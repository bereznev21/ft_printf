/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:29:51 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/05 18:18:07 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_get_d_1(size_t nb, t_var *tmp, va_list str)
{
	if (tmp->size2 == 'l')
		nb = va_arg(str, long long int);
	else
		nb = va_arg(str, long int);
	return (nb);
}

char	*ft_get_d(char *str1, t_var *tmp, va_list str)
{
	size_t	nb;

	nb = 0;
	if (tmp->size1 == 'l')
		nb = ft_get_d_1(nb, tmp, str);
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
		nb = va_arg(str, int);
	if (nb == 0 && tmp->precision == 0 && tmp->precision_flag == 1)
		return ("");
	str1 = ft_llitoa(nb, tmp);
	return (str1);
}
