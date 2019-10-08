/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:27:52 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/08 21:18:50 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_u(char *str1, t_var *tmp, va_list str)
{
	uintmax_t	nb;

	nb = 0;
	if (tmp->size1 == 'l' || tmp->type == 'U')
	{
		if (tmp->size2 == 'l')
			nb = va_arg(str, unsigned long long);
		else
			nb = va_arg(str, unsigned long);
	}
	else if (tmp->size1 == 'h' && tmp->size2 == 'h')
		nb = (unsigned char)va_arg(str, unsigned int);
	else if (tmp->size1 == 'h')
		nb = (unsigned short int)va_arg(str, unsigned int);
	else if (tmp->size1 == 'j')
		nb = va_arg(str, uintmax_t);
	else if (tmp->size1 == 'z')
		nb = va_arg(str, size_t);
	else
		nb = va_arg(str, unsigned int);
	if (nb == 0 && tmp->precision == 0 && tmp->precision_flag == 1)
		return (ft_strdup(""));
	str1 = ft_ullitoa(nb, tmp);
	return (str1);
}
