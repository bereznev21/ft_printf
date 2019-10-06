/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:17:29 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/06 13:48:22 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ox(t_var *tmp)
{
	if (tmp->type == 'x' || tmp->type == 'p')
		tmp->data = ft_strjoin_left("0x", tmp->data);
	if (tmp->type == 'X')
		tmp->data = ft_strjoin_left("0X", tmp->data);
}

void	ft_flag_zero_prcs_zero(t_var *tmp)
{
	if (tmp->precision_flag == 0)
	{
		if (tmp->flag == '?' && tmp->flag2 == '#' && tmp->flag_1 == '0')
		{
			tmp->width -= 2;
			while (tmp->width > (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("0", tmp->data);
		}
		if (tmp->flag == '0' && tmp->flag2 == '#' && tmp->flag_1 == '?')
		{
			tmp->width -= 2;
			while (tmp->width > (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("0", tmp->data);
		}
	}
}

void	ft_flag_zero_prcs_one(t_var *tmp)
{
	if (tmp->precision_flag == 1)
	{
		if (tmp->flag == '?' && tmp->flag2 == '#')
			if (tmp->flag_1 == '-' || tmp->flag_1 == '?' || tmp->flag_1 == '0')
				while ((int)ft_strlen(tmp->data) < tmp->precision)
					tmp->data = ft_strjoin_left("0", tmp->data);
		if (tmp->flag == '-' && tmp->flag2 == '#')
			if (tmp->flag_1 == '0' || tmp->flag_1 == '?')
				while (tmp->precision > (int)ft_strlen(tmp->data))
					tmp->data = ft_strjoin_left("0", tmp->data);
		if (tmp->flag == '0' && tmp->flag2 == '#' && tmp->flag_1 == '?')
		{
			tmp->flag2 = '?';
			while ((int)ft_strlen(tmp->data) < tmp->precision)
				tmp->data = ft_strjoin_left("0", tmp->data);
			ft_ox(tmp);
		}
	}
}

void	ft_flag_zero3(t_var *tmp, int flag_zero)
{
	if (flag_zero == 0)
	{
		ft_flag_zero_prcs_zero(tmp);
		ft_flag_zero_prcs_one(tmp);
		if (tmp->flag == '?' && tmp->flag2 == '#')
			ft_ox(tmp);
		if (tmp->flag == '-' && tmp->flag2 == '#')
			if (tmp->flag_1 == '?' || tmp->flag_1 == '0')
				ft_ox(tmp);
		if (tmp->flag == '0' && tmp->flag2 == '#' && tmp->flag_1 == '?')
			if (tmp->precision_flag == 0)
				ft_ox(tmp);
	}
}

char	*ft_print_x(t_var *tmp)
{
	int	flag_zero;

	flag_zero = ((int)ft_strlen(tmp->data) == 0) ? 1 : 0;
	ft_flag_zero3(tmp, flag_zero);
	if (tmp->precision_flag == 0 && flag_zero == 1)
	{
		tmp->data = "0";
		if (tmp->flag == '?' && tmp->flag2 == '#' && tmp->flag_1 == '0')
			while (tmp->width > (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("0", tmp->data);
	}
	if (tmp->precision_flag == 1 && flag_zero == 1)
	{
		if (tmp->flag == '0' && tmp->flag2 == '#' && tmp->flag_1 == '?')
		{
			tmp->flag = '?';
			tmp->flag2 = '?';
			if (tmp->precision != 0)
				tmp->data = "0";
		}
		if (tmp->precision == 0 && tmp->type == 'p')
			ft_ox(tmp);
	}
	tmp->data = ft_print_d(tmp);
	if (tmp->precision >= (int)ft_strlen(tmp->data) && flag_zero == 0)
		if (tmp->flag == '0' && tmp->flag2 == '#' && tmp->flag_1 == '?')
			ft_ox(tmp);
	return (tmp->data);
}
