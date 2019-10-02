/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntlstn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:10:33 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/01 23:42:54 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

var				*ft_ntlstn_var(var *tmp)
{
	tmp->width = 0;
	tmp->data = 0;
	tmp->arg_sign = 1;
	tmp->flag = '?';
	tmp->flag2 = '?';
	tmp->flag_1 = '?';
	tmp->precision = 0;
	tmp->precision_flag = 0;
	tmp->size1 = '0';
	tmp->size2 = '0';
	return (tmp);
}

var				*ft_ifseedot(var *tmp, int *i, const char *mas)
{
	(*i)++;
	tmp->precision_flag = 1;
	if (mas[*i] == '0')
	{
		(*i)++;
		if (ft_check_type(mas[(*i)]))
			return (tmp);
	}
	if ((mas[*i] >= '0' && mas[*i] <= '9'))
	{
		tmp->precision = 0;
		while (mas[*i] >= '0' && mas[*i] <= '9')
			tmp->precision = tmp->precision * 10 + mas[(*i)++] - '0';
	}
	else if (mas[*i] == '*')
		tmp->precision = -1;
	else if (ft_check_type(mas[(*i)]))
		tmp->precision = 0;
	return (tmp);
}

void			ft_srchflgs2(var *tmp, int *i, const char *mas)
{
	if (mas[*i] == '-' || mas[*i] == '+' || mas[*i] == ' '
		|| mas[*i] == '0')
	{
		if (tmp->flag == ' ')
			tmp->flag2 = ' ';
		tmp->flag = mas[(*i)++];
	}
	if (mas[*i] == '+' || mas[*i] == ' ' || mas[*i] == '#')
		tmp->flag2 = mas[(*i)++];
	if (mas[*i] == ' ' && tmp->flag == '+')
		(*i)++;
	if (mas[*i] == '-')
	{
		if ((tmp->flag == '+' || tmp->flag == '-'
			|| tmp->flag == ' ') && tmp->flag2 == '#')
		{
			tmp->flag2 = tmp->flag;
			tmp->flag_1 = '#';
		}
		if (tmp->flag == '+')
			tmp->flag2 = '+';
		if (tmp->flag == '-')
			tmp->flag2 = '-';
		tmp->flag = mas[(*i)++];
	}
}

var				*ft_srchflgs(var *tmp, int *i, const char *mas)
{
	tmp = ft_ntlstn_var(tmp);
	while (mas[*i] == ' ')
		tmp->flag = mas[(*i)++];
	ft_srchflgs2(tmp, i, mas);
	if (mas[*i] == '0')
		tmp->flag_1 = mas[(*i)++];
	if (mas[*i] == '-' && tmp->flag_1 == '0')
		tmp->flag = mas[(*i)++];
	if (mas[*i] >= '0' && mas[*i] <= '9')
		while (mas[*i] >= '0' && mas[*i] <= '9')
			tmp->width = tmp->width * 10 + mas[(*i)++] - '0';
	else if (mas[*i] == '*')
		tmp->width = mas[*i++];
	if (mas[*i] == '.')
		tmp = ft_ifseedot(tmp, i, mas);
	if (mas[*i] == 'h' || mas[*i] == 'l' || mas[(*i)] == 'L'
		|| mas[*i] == 'j' || mas[*i] == 'z')
	{
		tmp->size1 = mas[(*i)++];
		if ((mas[*i] == 'h' || mas[*i] == 'l') && tmp->size1 != 'L'
			&& tmp->size1 != 'j' && tmp->size1 != 'z')
			tmp->size2 = mas[(*i)++];
	}
	return (tmp);
}
