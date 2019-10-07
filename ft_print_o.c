/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 16:39:28 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/07 16:11:33 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	if_flag_zero3(t_var *tmp)
{
	if (tmp->flag == '?' && tmp->flag2 == '#' && tmp->flag_1 == '?')
		tmp->data = ft_strjoin_left("0", tmp->data);
	if (!(tmp->precision == 0 && tmp->precision_flag == 1))
		if (tmp->flag == '?' && tmp->flag2 == '?' && tmp->flag_1 == '?')
			tmp->data = ft_strjoin_left("0", tmp->data);
	if (tmp->flag == '?' && tmp->flag2 == '#' && tmp->flag_1 == '0')
	{
		tmp->data = ft_strjoin_left("0", tmp->data);
		if (tmp->precision_flag == 0)
			tmp->flag = '0';
	}
	if (tmp->flag == '-' && tmp->flag2 == '#' && tmp->flag_1 == '?')
		tmp->data = ft_strjoin_left("0", tmp->data);
	if (!(tmp->precision == 0 && tmp->precision_flag == 1))
		if (tmp->flag == '-' && tmp->flag2 == '?' && tmp->flag_1 == '?')
			tmp->data = ft_strjoin_left("0", tmp->data);
	if (tmp->flag == '0' && tmp->flag2 == '#' && tmp->flag_1 == '?')
	{
		tmp->data = ft_strjoin_left("0", tmp->data);
		if (tmp->precision_flag == 1)
			tmp->flag = '?';
	}
}

void	if_flag_zero2(t_var *tmp)
{
	if (tmp->flag == '0' && tmp->flag2 == '#' && tmp->flag_1 == '?')
	{
		if (tmp->precision_flag == 1)
			if (tmp->precision <= (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("0", tmp->data);
		if (tmp->precision_flag == 0)
		{
			if (tmp->width <= (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("0", tmp->data);
			while (tmp->width > (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("0", tmp->data);
		}
		tmp->flag = '?';
	}
}

void	if_flag_zero1(t_var *tmp)
{
	if (tmp->flag == '?' && tmp->flag2 == '#' && tmp->flag_1 == '?')
		tmp->data = ft_strjoin_left("0", tmp->data);
	if (tmp->flag == '-' && tmp->flag2 == '#' && tmp->flag_1 == '?')
		tmp->data = ft_strjoin_left("0", tmp->data);
	if (tmp->flag == '-' && tmp->flag2 == '#' && tmp->flag_1 == '0')
		tmp->data = ft_strjoin_left("0", tmp->data);
	if (tmp->flag == '?' && tmp->flag2 == '#' && tmp->flag_1 == '0')
	{
		if (tmp->precision_flag == 0)
		{
			if (tmp->width <= (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("0", tmp->data);
			while (tmp->width > (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("0", tmp->data);
		}
		if (tmp->precision_flag == 1)
		{
			if (tmp->precision <= (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("0", tmp->data);
			while (tmp->precision > (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("0", tmp->data);
		}
	}
	if_flag_zero2(tmp);
}

void	ft_print_o(t_var *tmp)
{
	int flag_zero;

	flag_zero = 0;
	if ((int)ft_strlen(tmp->data) == 0)
		flag_zero = 1;
	if (flag_zero == 0)
		if_flag_zero1(tmp);
	if (flag_zero == 1)
		if_flag_zero3(tmp);
	ft_print_d(tmp);
}
