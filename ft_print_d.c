/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:43:57 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/08 23:02:33 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_d_rgsgn(t_var *tmp)
{
	if (tmp->arg_sign == -1)
	{
		if (tmp->precision_flag == 0)
			ft_if_ngtv_rgsgn_prcsn_0(tmp);
		if (tmp->precision_flag == 1)
			ft_if_ngtv_rgsgn_prcsn_1(tmp);
	}
	if (tmp->arg_sign == 1)
	{
		if (tmp->precision_flag == 0)
			ft_if_pstv_rgsgn_prcsn_0(tmp);
		if (tmp->precision_flag == 1)
			ft_if_pstv_rgsgn_prcsn_1(tmp);
	}
	if ((int)ft_strlen(tmp->data) < tmp->precision && tmp->precision_flag == 1)
		while (((int)ft_strlen(tmp->data) < tmp->precision
		&& tmp->precision <= tmp->width))
			tmp->data = ft_strjoin_left("0", tmp->data);
}

void	ft_print_d_rgsgn1(t_var *tmp)
{
	if (tmp->arg_sign == 1 && tmp->precision == (int)ft_strlen(tmp->data))
	{
		if (tmp->flag == '+')
		{
			if (tmp->flag2 == '?')
				tmp->data = ft_strjoin_left("+", tmp->data);
			if (tmp->flag2 == ' ' && tmp->flag_1 == '?')
				tmp->data = ft_strjoin_left("+", tmp->data);
		}
		if (tmp->flag == '-' && tmp->flag2 == '+')
			tmp->data = ft_strjoin_left("+", tmp->data);
		if (tmp->flag == ' ')
		{
			if (tmp->flag2 == '?' && tmp->flag_1 == '?')
				tmp->data = ft_strjoin_left(" ", tmp->data);
			if (tmp->flag2 == ' ' && tmp->flag_1 == '?')
				tmp->data = ft_strjoin_left(" ", tmp->data);
		}
	}
}

void	ft_print_d_rgsgn2(t_var *tmp)
{
	if (tmp->arg_sign == -1 && tmp->precision_flag == 1
	&& tmp->precision == (int)ft_strlen(tmp->data))
	{
		if (tmp->flag == '?' && tmp->width > 0)
			tmp->data = ft_strjoin_left("-", tmp->data);
		if (tmp->flag == '-')
		{
			if (tmp->flag2 == '?' || tmp->flag2 == '+')
				tmp->data = ft_strjoin_left("-", tmp->data);
			if (tmp->flag2 == ' ' && tmp->flag_1 == '?')
				tmp->data = ft_strjoin_left("-", tmp->data);
		}
		if (tmp->flag == '+')
		{
			if (tmp->flag2 == '?')
				if (tmp->flag_1 == '0' || tmp->flag_1 == '?')
					tmp->data = ft_strjoin_left("-", tmp->data);
			if (tmp->flag2 == ' ' && tmp->flag_1 == '?')
				tmp->data = ft_strjoin_left("-", tmp->data);
		}
		if (tmp->flag == ' ' && tmp->flag2 == '?' && tmp->flag_1 == '?')
			tmp->data = ft_strjoin_left("-", tmp->data);
	}
}

void	ft_print_d_rgsgn3(t_var *tmp)
{
	tmp->width = (tmp->width == 0) ? tmp->precision : tmp->width;
	if (tmp->width)
	{
		if (tmp->precision > (int)ft_strlen(tmp->data))
		{
			if (tmp->flag == '+')
				tmp->flag_1 = '+';
			if (tmp->flag == ' ' && tmp->flag_1 == '?' && tmp->flag2 == '?')
				tmp->flag_1 = ' ';
			if (tmp->flag == ' ' && tmp->flag2 == '-' && tmp->flag2 == '?')
				tmp->flag_1 = 's';
			tmp->flag = '0';
		}
		if (tmp->precision > tmp->width)
			tmp->width = tmp->precision;
		if (tmp->width && tmp->width > (int)ft_strlen(tmp->data))
		{
			if (tmp->flag != '-')
				tmp->data = ft_fil_whitespaces(tmp, tmp->width,
				(int)ft_strlen(tmp->data));
			else if (tmp->flag == '-')
				tmp->data = ft_end_whitespaces(tmp, tmp->width,
				(int)ft_strlen(tmp->data));
		}
	}
}

void	ft_print_d(t_var *tmp)
{
	ft_print_d_rgsgn(tmp);
	ft_print_d_rgsgn1(tmp);
	ft_print_d_rgsgn2(tmp);
	ft_print_d_rgsgn3(tmp);
	if (tmp->arg_sign == 1)
	{
		if (tmp->flag == '0')
		{
			if (tmp->flag2 == '+' && tmp->flag_1 == '?'
			&& tmp->width == (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("+", tmp->data);
			if (tmp->flag2 == '+' && tmp->flag_1 == '0'
			&& tmp->width == (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("+", tmp->data);
			ft_print_d_flg_s_ask(tmp);
		}
		if (tmp->flag == '+')
			if (tmp->flag2 == '?' && tmp->precision == (int)ft_strlen(tmp->data)
				&& tmp->precision_flag == 1)
				tmp->data = ft_strjoin_left("+", tmp->data);
		if (tmp->flag == '-' && tmp->flag_1 == '?' && tmp->flag2 == ' ')
			if (tmp->width == (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left(" ", tmp->data);
	}
	ft_print_d_rgsgn4(tmp);
}
