/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:37:01 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/01 23:05:46 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ngtv_argsgn(var *tmp)
{
	if (tmp->flag == '-' && tmp->flag2 == '#' && tmp->flag_1 == '?')
		tmp->data = ft_strjoin("-", tmp->data);
	if (tmp->flag == '-' && tmp->flag2 == ' ' && tmp->flag_1 == '0')
		tmp->data = ft_strjoin("-", tmp->data);
	if (tmp->flag == '-' && tmp->flag2 == ' ' && tmp->flag_1 == '#')
		tmp->data = ft_strjoin("-", tmp->data);
	if (tmp->flag == '+' && tmp->flag2 == '?' && tmp->flag_1 == '0'
		&& tmp->width <= (int)ft_strlen(tmp->data))
		tmp->data = ft_strjoin("-", tmp->data);
	if (tmp->flag == '+' && tmp->flag2 == '?' && tmp->flag_1 == '0')
	{
		tmp->flag = '0';
		tmp->flag2 = '0';
		tmp->flag_1 = '?';
		tmp->width--;
	}
}

void	ft_pstv_argsgn(var *tmp)
{
	if (tmp->flag == '0' && tmp->flag2 == '?' && tmp->flag_1 == '?')
		tmp->flag2 = '0';
	if (tmp->flag == '-' && tmp->flag2 == ' ' && tmp->flag_1 == '0')
		tmp->data = ft_strjoin(" ", tmp->data);
	if (tmp->flag == '-' && tmp->flag2 == ' ' && tmp->flag_1 == '#')
		tmp->data = ft_strjoin(" ", tmp->data);
}

void	ft_dot(var *tmp)
{
	if (tmp->precision == 0 && tmp->precision_flag == 1)
	{
		if (tmp->flag == '-')
		{
			if (tmp->flag2 == '+' && tmp->flag_1 == '#')
				tmp->data = ft_strjoin(tmp->data, ".");
			if (tmp->flag2 == '#' && tmp->flag_1 == '?')
				tmp->data = ft_strjoin(tmp->data, ".");
			if (tmp->flag2 == ' ' && tmp->flag_1 == '#')
				tmp->data = ft_strjoin(tmp->data, ".");
		}
		if (tmp->flag == '?' && tmp->flag2 == '#' && tmp->flag_1 == '?')
			tmp->data = ft_strjoin(tmp->data, ".");
	}
}

char	*ft_print_f(var *tmp)
{
	if (tmp->arg_sign == -1)
		ft_ngtv_argsgn(tmp);
	if (tmp->arg_sign == 1)
		ft_pstv_argsgn(tmp);
	if (tmp->flag == '0' && tmp->flag_1 == '?'
		&& (tmp->flag2 == ' ' || tmp->flag2 == '?'))
	{
		tmp->width--;
		tmp->precision = tmp->width;
	}
	if (tmp->flag == '+' && tmp->flag2 == '?' && tmp->flag_1 == '0')
	{
		tmp->width--;
		tmp->precision = tmp->width;
	}
	ft_dot(tmp);
	tmp->data = ft_print_d(tmp);
	if (tmp->arg_sign == -1 && tmp->flag == '0'
		&& tmp->flag2 == '0' && tmp->flag_1 == '?')
		if (tmp->width == (int)ft_strlen(tmp->data))
			tmp->data = ft_strjoin("-", tmp->data);
	return (tmp->data);
}
