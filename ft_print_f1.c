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


char	*ft_print_f(var *tmp)
{
	char	*str;
	int		wdth;
	int		len;
	int		i;

	i = 0;
/*	ft_putchar('|');
	ft_putchar(tmp->flag);
	ft_putchar(tmp->flag_1);
	ft_putchar(tmp->flag2);
	ft_putchar('|');
*/

	len = ft_strlen(tmp->data);
	while (tmp->data[i] != '.')
		i++;
	if (tmp->precision >= len)
		tmp->precision = 0;
	if (tmp->precision > 0 && tmp->precision_flag == 1)
	{
		tmp->data = ft_crop_str(tmp->data, len, tmp->precision + i + 1);
		len = (len > tmp->precision) ? tmp->precision + i : len;
	}
	len = (tmp->precision) ? ++len : len;
	if (tmp->flag == '-')
	{
		if (tmp->flag2 == ' ' || tmp->flag2 == '+')
			tmp->width--;
	}
	if (tmp->flag != '-')
		tmp->data = ft_fil_whitespaces(tmp, tmp->width, len);
	if (tmp->flag == '-')
		tmp->data = ft_end_whitespaces(tmp, tmp->width, len);
	if (tmp->arg_sign == -1)
		tmp->data = ft_strjoin("-", tmp->data);
	if (tmp->arg_sign != -1)
	{
		if (tmp->flag2 == ' ')
		{
			if (tmp->flag == '-' || tmp->flag == '0')
				tmp->data = ft_strjoin(" ", tmp->data);
			if (tmp->flag == '+')
				tmp->data = ft_strjoin("+", tmp->data);
		}
		if (tmp->flag == '-' && tmp->flag2 == '+')
			tmp->data = ft_strjoin("+", tmp->data);
	}
	return (tmp->data);
}