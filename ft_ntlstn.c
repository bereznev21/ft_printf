/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntlstn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:10:33 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/06 18:27:20 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	tmp->size1 = '?';
	tmp->size2 = '?';
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
	while (mas[*i] == 'h' || mas[*i] == 'l' || mas[(*i)] == 'L'
	|| mas[*i] == 'j' || mas[*i] == 'z')
	{
		tmp->size1 = mas[(*i)++];
		if ((mas[*i] == 'h' || mas[*i] == 'l') && tmp->size1 != 'L'
			&& tmp->size1 != 'j' && tmp->size1 != 'z')
			tmp->size2 = mas[(*i)++];
	}
	return (tmp);
}
