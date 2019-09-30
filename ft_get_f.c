/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:49:47 by rpoetess          #+#    #+#             */
/*   Updated: 2019/09/16 13:49:49 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_f(char *str1, var *tmp, va_list str)
{
	/*ft_putchar('|');
	ft_putchar(tmp->size1);
	ft_putchar(tmp->size2);
	ft_putchar('|');
*/
	double	n;

	n = 0;
	if (tmp->size1 == 'l')
		str1 = ft_start_double(va_arg(str, double), tmp);
	else if (tmp->size1 == 'L')
		str1 = ft_start_double(va_arg(str, long double), tmp);
	else
	{
		n = va_arg(str, double);
		if (n < 0.0)
			n = -n;
		str1 = ft_start_double(n, tmp);
	}
	return (str1);
}
