/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_ngtv_rgsgn_prcsn_z.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 21:40:31 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/01 22:39:52 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_zero_2(var *tmp)
{
	if (tmp->flag == '0')
	{
		if (tmp->flag2 == ' ' && tmp->flag_1 == '?')
			if (tmp->width > (int)ft_strlen(tmp->data))
				tmp->width--;
		if (tmp->flag2 == '?')
		{
			if (tmp->width <= (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("-", tmp->data);
			tmp->width--;
		}
		if (tmp->flag2 == '+' && tmp->flag_1 == '?')
		{
			if (tmp->width <= (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("-", tmp->data);
			if (tmp->width > (int)ft_strlen(tmp->data))
				tmp->width--;
		}
	}
}

void	ft_if_ngtv_rgsgn_prcsn_0(var *tmp)
{
	if (tmp->flag == '?')
		tmp->data = ft_strjoin_left("-", tmp->data);
	if (tmp->flag == '+')
	{
		if (tmp->flag_1 == '?')
			tmp->data = ft_strjoin_left("-", tmp->data);
		if (tmp->flag_1 == '0')
			tmp->flag = '0';
	}
	if (tmp->flag == '-')
		tmp->data = ft_strjoin_left("-", tmp->data);
	ft_flag_zero_2(tmp);
	if (tmp->flag == ' ')
		if (tmp->flag2 == '?' && tmp->flag_1 == '?')
			tmp->data = ft_strjoin_left("-", tmp->data);
}
