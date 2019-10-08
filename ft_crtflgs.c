/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crtflgs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 20:20:30 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/08 23:17:26 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_crtflgs2(t_var *tmp, t_flags flgs)
{
	if (flgs.zero)
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
		tmp->flag = ' ';
	else if (flgs.grab)
	{
		tmp->flag2 = '#';
		if (flgs.zero)
			tmp->flag = '0';
	}
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
		tmp->flag_1 = (flgs.zero) ? '0' : '?';
	}
	else
		ft_crtflgs2(tmp, flgs);
}

void				ft_crtflgs(int *i, t_var *tmp, const char *mas)
{
	t_flags	flgs;

	flgs.minus = 0;
	flgs.plus = 0;
	flgs.space = 0;
	flgs.zero = 0;
	flgs.grab = 0;
	while (mas[*i] == '-' || mas[*i] == '+' || mas[*i] == ' '
	|| mas[*i] == '#' || mas[*i] == '0' || mas[*i] == '*')
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
