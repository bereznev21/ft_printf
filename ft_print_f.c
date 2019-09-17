/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:37:01 by rpoetess          #+#    #+#             */
/*   Updated: 2019/09/13 19:55:59 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*ft_print_f(var *s)
{
	char	*str;
	int		wdth;
	int		len;
	int		i;

	i = 0;
	wdth = (s->width) ? s->width : 0;
	len = ft_strlen(s->data);
	while (s->data[i] != '.')
		i++;
	if (!(str = ft_strnew(wdth)))
		return (0);
	if (s->precision >= len)
		s->precision = 0;
	if (s->precision > 0)
	{
		s->data = ft_crop_str(s->data, len, s->precision + i + 1);
		len = (len > s->precision) ? s->precision + i : len;
	}
	len = (s->precision) ? ++len : len;
	if (s->width)
		s->data = (s->flag != '-') ?
			ft_fil_whitespaces(s, wdth, len) :
			ft_end_whitespaces(s, wdth, len);
	return (s->data);
}
