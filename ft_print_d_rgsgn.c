/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_rgsgn.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 23:04:43 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/08 23:04:49 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_d_flg_s_ask(t_var *tmp)
{
	if (tmp->flag2 == ' ')
	{
		if (tmp->flag_1 == '?')
			tmp->data = ft_strjoin_left(" ", tmp->data);
		if (tmp->flag_1 == '+'
		&& tmp->precision == (int)ft_strlen(tmp->data))
			tmp->data = ft_strjoin_left("+", tmp->data);
		if (tmp->flag_1 == '0' || tmp->flag_1 == 'p')
			if (tmp->width == (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("+", tmp->data);
	}
	if (tmp->flag2 == '?')
	{
		if (tmp->flag_1 == '+' && tmp->precision ==
		(int)ft_strlen(tmp->data) && tmp->precision_flag == 1)
			tmp->data = ft_strjoin_left("+", tmp->data);
		if (tmp->flag_1 == ' ' && tmp->precision ==
		(int)ft_strlen(tmp->data) && tmp->precision_flag == 1)
			tmp->data = ft_strjoin_left(" ", tmp->data);
		if (tmp->flag_1 == '0' && tmp->width ==
		(int)ft_strlen(tmp->data) && tmp->precision_flag == 0)
			tmp->data = ft_strjoin_left("+", tmp->data);
		if (tmp->flag_1 == 's')
			tmp->data = ft_strjoin_left(" ", tmp->data);
	}
}

void	ft_print_d_rgsgn4(t_var *tmp)
{
	if (tmp->arg_sign == -1)
	{
		if (tmp->flag == '0')
		{
			if (tmp->flag2 == '?' && tmp->width == (int)ft_strlen(tmp->data)
			&& tmp->precision_flag == 0)
				tmp->data = ft_strjoin_left("-", tmp->data);
			if (tmp->flag2 == '+' && tmp->width
				== (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("-", tmp->data);
			if (tmp->flag2 == ' ' && tmp->flag_1 == '+'
			&& tmp->precision == (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("-", tmp->data);
			if (tmp->flag2 == ' ' && tmp->flag_1 == '?')
				tmp->data = ft_strjoin_left("-", tmp->data);
			if (tmp->flag2 == '?' && tmp->precision
			>= (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("-", tmp->data);
		}
	}
}
