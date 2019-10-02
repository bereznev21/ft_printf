/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_ngtv_rgsgn_prcsn_1.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 21:44:25 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/01 22:14:58 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_qstn(var *tmp)
{
	if (tmp->flag == '?')
	{
		if (tmp->precision < (int)ft_strlen(tmp->data))
			tmp->data = ft_strjoin_left("-", tmp->data);
		if (tmp->precision >= (int)ft_strlen(tmp->data))
		{
			if (tmp->width > 0)
			{
				if (tmp->width <= (int)ft_strlen(tmp->data)
					&& tmp->precision < tmp->width)
					tmp->data = ft_strjoin_left("-", tmp->data);
				if (tmp->precision > tmp->width
					&& tmp->precision > (int)ft_strlen(tmp->data))
					tmp->flag = '0';
			}
			if (tmp->width == 0)
				if (tmp->precision <= (int)ft_strlen(tmp->data))
					tmp->data = ft_strjoin_left("-", tmp->data);
		}
	}
}

void	ft_flag_minus_space(var *tmp)
{
	if (tmp->flag == '-')
	{
		if (tmp->flag2 == '?')
			if (tmp->precision < (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("-", tmp->data);
		if (tmp->flag2 == '+')
			if (tmp->precision < (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("-", tmp->data);
		if (tmp->flag2 == ' ' && tmp->flag_1 == '?')
			if (tmp->precision < (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("-", tmp->data);
	}
	if (tmp->flag == ' ')
		if (tmp->flag2 == '?' && tmp->flag_1 == '?')
			if (tmp->precision < (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("-", tmp->data);
}

void	ft_flag_zero_1(var *tmp)
{
	if (tmp->flag2 == '?' && tmp->flag_1 == '?')
	{
		if (tmp->precision <= (int)ft_strlen(tmp->data)
			&& tmp->width < tmp->precision)
			tmp->data = ft_strjoin_left("-", tmp->data);
		tmp->flag = '?';
		if (tmp->width == tmp->precision
			&& tmp->width < (int)ft_strlen(tmp->data))
		{
			tmp->data = ft_strjoin_left("-", tmp->data);
			tmp->width--;
		}
		if (tmp->width > tmp->precision
			&& tmp->precision < (int)ft_strlen(tmp->data))
			tmp->data = ft_strjoin_left("-", tmp->data);
	}
	if (tmp->flag2 == '+')
	{
		if (tmp->flag_1 == '?')
			tmp->flag = '?';
		if (tmp->precision <= (int)ft_strlen(tmp->data))
			tmp->data = ft_strjoin_left("-", tmp->data);
	}
}

void	ft_if_ngtv_rgsgn_prcsn_1(var *tmp)
{
	ft_flag_qstn(tmp);
	ft_flag_minus_space(tmp);
	if (tmp->flag == '0')
	{
		ft_flag_zero_1(tmp);
		if (tmp->flag2 == ' ')
		{
			tmp->flag = '?';
			if (tmp->precision <= (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("-", tmp->data);
		}
	}
	if (tmp->flag == '+')
	{
		if (tmp->flag2 == '?' && (tmp->flag_1 == '?' || tmp->flag_1 == '0'))
			if (tmp->precision < (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("-", tmp->data);
		if (tmp->flag2 == ' ' && tmp->flag_1 == '?')
			if (tmp->precision < (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("-", tmp->data);
	}
}
