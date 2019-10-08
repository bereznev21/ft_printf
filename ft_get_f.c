/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:49:47 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/08 21:04:04 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_f(char *str1, t_var *tmp, va_list str)
{
	if (tmp->size1 == 'l')
		str1 = ft_start_double(va_arg(str, double), tmp);
	else if (tmp->size1 == 'L')
		str1 = ft_start_double((long double)va_arg(str, long double), tmp);
	else
		str1 = ft_start_double(va_arg(str, double), tmp);
	return (str1);
}
