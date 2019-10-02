/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_pstv_rgsgn_prcsn_0.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 21:15:19 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/01 21:29:46 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_minus(var *tmp)
{
	if (tmp->flag == '-')
	{
		if (tmp->flag2 == ' ')
		{
			if (tmp->flag_1 == ' ')
				if (tmp->width <= (int)ft_strlen(tmp->data))
					tmp->data = ft_strjoin_left(" ", tmp->data);
			if (tmp->flag_1 == '?')
			{
				if (tmp->width <= (int)ft_strlen(tmp->data))
					tmp->data = ft_strjoin_left(" ", tmp->data);
				tmp->width--;
			}
		}
		if (tmp->flag2 == '+' && tmp->flag_1 == '?')
			tmp->data = ft_strjoin_left("+", tmp->data);
	}
}

void	ft_flag_zero(var *tmp)
{
	if (tmp->flag == '0')
	{
		if (tmp->flag2 == '+' && tmp->flag_1 == '0')
			tmp->width--;
		if (tmp->flag2 == '+' && tmp->flag_1 == '?')
		{
			if (tmp->width > (int)ft_strlen(tmp->data))
			{
				tmp->precision--;
				tmp->width--;
			}
			if (tmp->width < (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("+", tmp->data);
		}
		if (tmp->flag2 == ' ' && tmp->flag_1 == '?')
			tmp->width--;
	}
}

void	ft_flag_space(var *tmp)
{
	if (tmp->flag2 == ' ')
	{
		if (tmp->width <= (int)ft_strlen(tmp->data))
			tmp->data = ft_strjoin_left("+", tmp->data);
		if (tmp->width > (int)ft_strlen(tmp->data))
		{
			if (tmp->flag_1 == '0')
			{
				tmp->flag = '0';
				tmp->flag_1 = 'p';
				tmp->width--;
			}
			if (tmp->flag_1 == '?')
				tmp->data = ft_strjoin_left("+", tmp->data);
		}
	}
}

void	ft_if_pstv_rgsgn_prcsn_0(var *tmp)
{
	if (tmp->flag == ' ' && tmp->flag2 == '?')
		if (tmp->width <= (int)ft_strlen(tmp->data))
			tmp->data = ft_strjoin_left(" ", tmp->data);
	if (tmp->flag == '+')
	{
		ft_flag_space(tmp);
		if (tmp->flag2 == '?')
		{
			if (tmp->flag_1 == '?')
				tmp->data = ft_strjoin_left("+", tmp->data);
			if (tmp->flag_1 == '0')
			{
				if (tmp->width <= (int)ft_strlen(tmp->data))
					tmp->data = ft_strjoin_left("+", tmp->data);
				tmp->flag = '0';
				tmp->width--;
			}
		}
		if (tmp->flag2 == '+' && tmp->flag_1 == '?')
			tmp->data = ft_strjoin_left("+", tmp->data);
	}
	ft_flag_zero(tmp);
	ft_flag_minus(tmp);
}
