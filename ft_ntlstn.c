/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntlstn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:10:33 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/03 19:00:11 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

t_var				*ft_ntlstn_var(t_var *tmp)
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

t_var				*ft_ifseedot(t_var *tmp, int *i, const char *mas)
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

void				ft_srchflgs2(t_var *tmp, int *i, const char *mas)
{
	while (mas[*i] == ' ')
		tmp->flag = mas[(*i)++];
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
	if (mas[*i] == '0')
		tmp->flag_1 = mas[(*i)++];
	if (mas[*i] == '-' && tmp->flag_1 == '0')
		tmp->flag = mas[(*i)++];
}

void				ft_crtflgs1(t_var *tmp, t_flags flgs)
{
	if (flgs.minus)
	{
		tmp->flag = '-';
		if (flgs.plus)
		{
			tmp->flag2 = '+';
			if (flgs.grab)
				tmp->flag_1 = '#';
		}
		else if (flgs.space)
		{
			tmp->flag2 = ' ';
			if (flgs.grab)
				tmp->flag_1 = '#';
		}
		else if (flgs.grab)
			tmp->flag2 = '#';
	}
	else if (flgs.plus)
	{
		tmp->flag = '+';
		if (flgs.zero)
			tmp->flag_1 = '0';
	}
	else if (flgs.zero)
	{
		tmp->flag = '0';
		if (flgs.grab)
			tmp->flag2 = '#';
		else if (flgs.plus)
			tmp->flag2 = '+';
		else if (flgs.space)
			tmp->flag2 = ' ';
	}
	else if (flgs.space)
	{
		tmp->flag = ' ';
	}
	else if (flgs.grab)
	{
		tmp->flag2 = '#';
		if (flgs.zero)
			tmp->flag = '0';
	}
}

void				ft_crtflgs(int *i, t_var *tmp, const char *mas)
{
	t_flags	flgs;

	flgs.minus = 0;
	flgs.plus = 0;
	flgs.space = 0;
	flgs.zero = 0;
	flgs.grab = 0;
	while (mas[*i] == '-' || mas[*i] == '+'
	|| mas[*i] == ' ' || mas[*i] == '#' || mas[*i] == '0')
	{
		if (mas[*i] == '-')
			flgs.minus = 1;
		else if (mas[*i] == '+')
			flgs.plus = 1;
		else if (mas[*i] == ' ')
			flgs.space = 1;
		else if (mas[*i] == '#')
			flgs.grab = 1;
		else if (mas[*i] == '0')
			flgs.zero = 1;
		(*i)++;
	}
	ft_crtflgs1(tmp, flgs);
}

t_var				*ft_srchflgs(t_var *tmp, int *i, const char *mas)
{
	tmp = ft_ntlstn_var(tmp);
	ft_crtflgs(i, tmp, mas);
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
