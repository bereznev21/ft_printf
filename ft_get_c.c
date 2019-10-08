/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:27:04 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/08 18:05:13 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_c(char *str1, t_var *tmp, va_list str)
{
	int		c;
	int		b;
	char	*nul;

	nul = 0;
	b = (char)0;
	str1 = 0;
	if (tmp->width == '0')
		tmp->precision = 0;
	str1 = ft_strnew(1);
	c = va_arg(str, int);
	str1[0] = (char)c;
	str1[1] = '\0';
	if (c == 0)
	{
		free(str1);
		str1 = nul;
	}
	return (str1);
}
