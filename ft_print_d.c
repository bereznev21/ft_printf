/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:43:57 by rpoetess          #+#    #+#             */
/*   Updated: 2019/08/31 16:43:58 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_if_ngtv_rgsgn(var *tmp)
{
	if (tmp->precision_flag == 1 && tmp->width > 0 && tmp->precision <= tmp->width)
	{
		if (tmp->width <= (int)ft_strlen(tmp->data))
			tmp->data = ft_strjoin("-", tmp->data);
		if (tmp->precision < tmp->width)
			tmp->width-- ;
	}
	if (tmp->precision_flag == 0)
	{
		if (tmp->flag == '-')
		{
			tmp->data = ft_strjoin("-", tmp->data);
			tmp->width--;
		}
		if (tmp->flag == '?' && tmp->width > (int)ft_strlen(tmp->data))
		{
			tmp->data = ft_strjoin("-", tmp->data);
			tmp->width--;
		}
	}
	if (tmp->flag == '0')
		tmp->width -= 2;
}

void	ft_if_pstv_rgsgn(var *tmp)
{
	if (tmp->flag2 == '+')
		tmp->width -= 2;
	if ((tmp->flag2 == ' ') && tmp->flag != '+')
		tmp->data = ft_strjoin(" ", tmp->data);
	if ((tmp->flag == '+') && tmp->precision <= tmp->width)
		tmp->data = ft_strjoin("+", tmp->data);
	if ((tmp->flag == '+') && tmp->precision > tmp->width)
		tmp->arg_sign = 2;

}

char	*ft_print_d(var *tmp)
{
	char	*res;

	if (tmp->arg_sign == -1)
		ft_if_ngtv_rgsgn(tmp);
	if ((int)ft_strlen(tmp->data) < tmp->precision && tmp->flag != '0' && tmp->precision_flag == 1)
		while (((int)ft_strlen(tmp->data) < tmp->precision && tmp->precision < tmp->width))
			tmp->data = ft_strjoin("0", tmp->data);
	if (tmp->arg_sign == -1 && tmp->width > tmp->precision && tmp->precision_flag == 1)
		tmp->data = ft_strjoin("-", tmp->data);
	if (tmp->flag == '0' && tmp->precision > 0 && tmp->precision_flag == 1)
	{
		while ((int)ft_strlen(tmp->data) < tmp->precision)
			tmp->data = ft_strjoin("0", tmp->data);
		while (tmp->width > (int)ft_strlen(tmp->data))
			tmp->data = ft_strjoin(" ", tmp->data);
	}
	if (tmp->flag_1 == '0' && tmp->flag == '+')
	{	if (tmp->flag != '?')
			tmp->width--;
		while ((int)ft_strlen(tmp->data) < tmp->width)
			tmp->data = ft_strjoin("0", tmp->data);
	}
	if (tmp->arg_sign == 1)
		ft_if_pstv_rgsgn(tmp);
	if (tmp->precision > (int)ft_strlen(tmp->data))
	{
		tmp->flag = '0';
		tmp->width = (tmp->arg_sign == -1) ? tmp->precision - 1 : tmp->precision;
	}
	tmp->precision = 0;
	if (tmp->flag == ' ' && tmp->arg_sign > 0)
		tmp->data = ft_strjoin(" ", tmp->data);
	res = ft_print_s(tmp);
	if (((tmp->flag2 == '+') && (tmp->arg_sign == 1)) || tmp->arg_sign == 2)
		res = ft_strjoin("+", res);
	if (tmp->arg_sign == -1 && (tmp->flag == '0' || tmp->width == 0 || tmp->width == (int)ft_strlen(tmp->data)))
		res = ft_strjoin("-", res);
	return (res);
}
