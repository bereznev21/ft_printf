/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntlstn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:10:33 by rpoetess          #+#    #+#             */
/*   Updated: 2019/09/28 21:51:57 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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

int				ft_create_list_var(const char *mas, int i,
					va_list str)
{
	char	*str1;
	var		*tmp;
	int		nul;

	nul = 1;
	str1 = 0;
	tmp = (var*)malloc(sizeof(var));
	tmp = ft_srchflgs(tmp, &i, mas);
	if (!ft_check_type(mas[(i)]) || mas[i] == '\0')
		exit(0);
	tmp->type = mas[i];
	if (mas[i] == '%')
	{
		tmp->data = ft_strnew(0);
		if (tmp->data)
			tmp->data = ft_strjoin_char(tmp->data, mas[i]);
		return (ft_controller(tmp));
	}
	str1 = ft_create_arg_string(str1, tmp, str);
	if (str1 == 0 && tmp->type == 'c')
	{
		if (tmp->flag != '-')
		{
			while (tmp->width-- > 1)
			{
				ft_putchar(' ');
				nul++;
			}
		}
		write (1, &str1, 1);
		if (tmp->flag == '-')
		{
			while (tmp->width-- > 1)
			{
				ft_putchar(' ');
				nul++;
			}
		}
		return (nul);
	}
	if (!str)
		str1 = 0;
	if (!(tmp->data))
		tmp->data = str1;
	return (ft_controller(tmp));
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

var				*ft_srchflgs(var *tmp, int *i, const char *mas)
{
	tmp = ft_ntlstn_var(tmp);
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
		if ((tmp->flag == '+' || tmp->flag == '-' || tmp->flag == ' ') && tmp->flag2 == '#')
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
	if (mas[*i] >= '0' && mas[*i] <= '9')
		while (mas[*i] >= '0' && mas[*i] <= '9')
			tmp->width = tmp->width * 10 + mas[(*i)++] - '0';
	else if (mas[*i] == '*')
		tmp->width = mas[*i++];
	if (mas[*i] == '.')
		tmp = ft_ifseedot(tmp, i, mas);
	if (mas[*i] == 'h' || mas[*i] == 'l' || mas[(*i)] == 'L' || mas[*i] == 'j' || mas[*i] == 'z')
	{
		tmp->size1 = mas[(*i)++];
		if ((mas[*i] == 'h' || mas[*i] == 'l') && tmp->size1 != 'L' && tmp->size1 != 'j' && tmp->size1 != 'z')
			tmp->size2 = mas[(*i)++];
	}
	return (tmp);
}
