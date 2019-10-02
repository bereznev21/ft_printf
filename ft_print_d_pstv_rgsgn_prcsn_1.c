/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_pstv_rgsgn_prcsn_1.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 21:15:26 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/01 21:22:35 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_plus(var *tmp)
{
	if (tmp->flag == '+')
	{
		if (tmp->flag2 == '?' && tmp->flag_1 == '?')
		{
			if (tmp->precision < (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("+", tmp->data);
			if (tmp->precision > (int)ft_strlen(tmp->data)
				&& tmp->precision > tmp->width)
				tmp->flag_1 = '+';
		}
		if (tmp->flag2 == '?' && tmp->flag_1 == '0')
			if (tmp->precision < (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("+", tmp->data);
		if (tmp->flag2 == ' ' && tmp->flag_1 == '?'
			&& tmp->precision < (int)ft_strlen(tmp->data))
			tmp->data = ft_strjoin_left("+", tmp->data);
	}
}

void	ft_flag_0(var *tmp)
{
	if (tmp->flag == '0')
	{
		if (tmp->flag2 == '?')
			tmp->flag = '?';
		if (tmp->flag2 == '+' && tmp->flag_1 == '?')
		{
			if (tmp->precision < (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("+", tmp->data);
			tmp->flag = '+';
			tmp->flag2 = '?';
		}
		if (tmp->flag2 == ' ' && tmp->flag_1 == '?')
		{
			tmp->flag = ' ';
			if (tmp->width <= (int)ft_strlen(tmp->data)
				&& tmp->precision < (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left(" ", tmp->data);
		}
	}
}

void	ft_if_pstv_rgsgn_prcsn_1(var *tmp)
{
	ft_flag_plus(tmp);
	ft_flag_0(tmp);
	if (tmp->flag == '?')
		if (tmp->precision > tmp->width
			&& tmp->precision > (int)ft_strlen(tmp->data))
			tmp->flag = '0';
	if (tmp->flag == '-')
	{
		if (tmp->flag2 == '+')
			if (tmp->precision < (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("+", tmp->data);
		if (tmp->flag2 == ' ' && tmp->flag_1 == '?')
		{
			if (tmp->width <= (int)ft_strlen(tmp->data)
				&& tmp->precision < (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left(" ", tmp->data);
			tmp->width--;
		}
	}
	if (tmp->flag == ' ')
	{
		if (tmp->flag2 == '?' && tmp->flag_1 == '?')
			if (tmp->precision < (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left(" ", tmp->data);
	}
}
