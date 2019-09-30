/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:43:57 by rpoetess          #+#    #+#             */
/*   Updated: 2019/09/28 23:17:18 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_if_ngtv_rgsgn(var *tmp)
{
	if (tmp->precision_flag == 1)
	{
		if (tmp->width)
		{
			if (tmp->flag == '0' && tmp->precision < tmp->width)
				tmp->width--;
			if (tmp->precision < (int)ft_strlen(tmp->data) && tmp->width < tmp->precision)
			{
				if (tmp->flag == ' ')
					tmp->data = ft_strjoin_left("-", tmp->data);
				if (tmp->flag == '-')
					{
						if (tmp->flag2 == '?' || tmp->flag2 == ' ')
							tmp->data = ft_strjoin_left("-", tmp->data);
					}
				if (tmp->flag == '+' && tmp->flag2 == '?')
					tmp->data = ft_strjoin_left("-", tmp->data);
				if (tmp->flag == '0' && tmp->flag2 == '?')
					tmp->data = ft_strjoin_left("-", tmp->data);
				if (tmp->flag == '0' && tmp->flag2 == ' ')
					tmp->data = ft_strjoin_left("-", tmp->data);
			}
		}
		if (tmp->width >= tmp->precision || tmp->precision >= (int)ft_strlen(tmp->data) || tmp->width == 0)
			tmp->arg_sign = -2;
		if (tmp->flag == '-' && tmp->flag2 == '+')
		{
			tmp->width--;
			if (tmp->precision > tmp->width)
				tmp->precision--;
		}
		if (tmp->flag == '?' && tmp->arg_sign == -1)
			tmp->data = ft_strjoin_left("-", tmp->data);
	}
	if (tmp->precision_flag == 0)
	{
		if (tmp->flag == ' ')
		{
			tmp->data = ft_strjoin_left("-", tmp->data);
			tmp->width--;
			if (tmp->width == (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left(" ", tmp->data);
		}
		if (tmp->flag == '+')
		{
			if (tmp->width)
			{
				if (tmp->width < (int)ft_strlen(tmp->data))
					tmp->data = ft_strjoin_left("-", tmp->data);
				if (tmp->width >= (int)ft_strlen(tmp->data))
				{
					tmp->data = ft_strjoin_left("-", tmp->data);
					tmp->width--;
				}
			}
			else if (tmp->flag2 == '?' || tmp->flag2 == ' ')
				tmp->data = ft_strjoin_left("-", tmp->data);
			else if (tmp->flag2 == '+')
				tmp->data = ft_strjoin_left("-", tmp->data);
		}
		if (tmp->flag == '-')
		{
			tmp->data = ft_strjoin_left("-", tmp->data);
			tmp->width--;
		}
		if (tmp->flag == '?')
		{
			tmp->data = ft_strjoin_left("-", tmp->data);
			tmp->width--;
		}
		if (tmp->flag == '0' && (tmp->flag2 == '?' || tmp->flag2 == ' '))
		{
			if (tmp->width <= (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("-", tmp->data);
			tmp->arg_sign = -2;
			if (tmp->flag2 == ' ' && tmp->width < (int)ft_strlen(tmp->data))
				tmp->width -= 1;
			tmp->width -= 1;
		}
		if (tmp->flag == '0' && tmp->flag2 == '+')
		{
			tmp->width -= 2;
		}
	/*	if (tmp->flag == '0' && tmp->flag2 == ' ')
		{
			if (tmp->width <= (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("-", tmp->data);
			tmp->arg_sign = -2;
			if (tmp->flag2 == ' ' && tmp->width < (int)ft_strlen(tmp->data))
				tmp->width -= 1;
			tmp->width -= 1;
		}*/
		if (tmp->flag != '-' && tmp->flag != '0' && tmp->width == (int)ft_strlen(tmp->data))
			tmp->data = ft_strjoin_left(" ", tmp->data);
	}
}

void	ft_if_pstv_rgsgn(var *tmp)
{
/*	ft_putchar('|');
	ft_putchar(tmp->flag);
	ft_putchar(tmp->flag_1);
	ft_putchar(tmp->flag2);
	ft_putchar('|');
*/
	if (tmp->flag2 == '+' && tmp->flag != '-')
		tmp->width -= 2;
	if (tmp->flag2 == ' ' && tmp->flag != '+')
	{
		if (tmp->precision_flag == 0)
		{
			if (tmp->flag == '0' && tmp->width > (int)ft_strlen(tmp->data))
			{
				tmp->flag_1 = ' ';
				tmp->width--;
			}
			else if (tmp->flag == '0' && tmp->width <= (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left(" ", tmp->data);
			if (tmp->flag != '0')
				tmp->data = ft_strjoin_left(" ", tmp->data);
		}
		if (tmp->precision_flag == 1)
		{
			if (tmp->flag != '0' && tmp->flag != '-')
				tmp->data = ft_strjoin_left(" ", tmp->data);
			if (tmp->flag == '-' && tmp->flag2 == ' ')
				tmp->flag_1 = ' ';
			if (tmp->flag == '-' && tmp->width > (int)ft_strlen(tmp->data))
			{
				tmp->flag_1 = ' ';
				tmp->width--;
			}
			if (tmp->flag == '0')
			{
				if (tmp->width <= tmp->precision && tmp->width < (int)ft_strlen(tmp->data))
					tmp->data = ft_strjoin_left(" ", tmp->data);
				else if (tmp->width < (int)ft_strlen(tmp->data) && tmp->precision < (int)ft_strlen(tmp->data))
					tmp->data = ft_strjoin_left(" ", tmp->data);
				else if (tmp->width == (int)ft_strlen(tmp->data) && tmp->width > tmp->precision)
					tmp->data = ft_strjoin_left(" ", tmp->data);
			}
		}
	}
	if (tmp->flag == '+')
	{
		if (tmp->precision <= tmp->width)
			tmp->data = ft_strjoin_left("+", tmp->data);
		if (tmp->precision > tmp->width)
			tmp->arg_sign = 2;
	}
	if (tmp->flag == '-' && tmp->flag2 == '+' && tmp->precision_flag == 1 && tmp->precision > (int)ft_strlen(tmp->data))
		tmp->precision--;
	/*ft_putchar('|');
	ft_putnbr(tmp->width);
	ft_putnbr(tmp->precision);
	ft_putnbr((int)ft_strlen(tmp->data));
	ft_putchar('|');
*/
	//if (tmp->precision > (int)ft_strlen(tmp->data))
	//	tmp->width--;
	//	tmp->precision--;
	/*	
	ft_putchar('|');
	ft_putstr(tmp->data);
	ft_putchar('|');
	ft_putnbr(tmp->precision);
	ft_putchar('|');
	*/
	/*ft_putchar('|');
	ft_putstr(tmp->data);
	ft_putchar('|');
*/
	if (tmp->flag == ' ' && tmp->precision_flag == 0)
		tmp->data = ft_strjoin_left(" ", tmp->data);
	if (tmp->flag == ' ' && tmp->flag2 == '?' && tmp->precision_flag == 1)
	{
		if (tmp->precision <= (int)ft_strlen(tmp->data))
			tmp->data = ft_strjoin_left(" ", tmp->data);
		else if (tmp->flag_1)
			tmp->flag_1 = ' ';
	}
}

void	ft_rgsgn1(var *tmp)
{
	if (tmp->arg_sign <= -1)
	{
		if (tmp->precision_flag == 0 && tmp->flag != ' ' && tmp->width)
		{
			if ((tmp->flag == '0' && tmp->flag2 != ' ' && tmp->width >= (int)ft_strlen(tmp->data)) && tmp->width)
				tmp->data = ft_strjoin_left("-", tmp->data);
			if (tmp->flag == '0' && tmp->flag2 == ' ' && tmp->width >= (int)ft_strlen(tmp->data) && tmp->width)
				tmp->data = ft_strjoin_left("-", tmp->data);
			if (tmp->flag == '0' && tmp->flag2 == '+')
				tmp->data = ft_strjoin_left("-", tmp->data);
		}
		if (tmp->precision_flag == 1)
		{
			if (tmp->precision >= (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("-", tmp->data);
			if (tmp->arg_sign == -2 && tmp->flag_1 != '0')
				tmp->data = ft_strjoin_left("-", tmp->data);
		}
	}
	if (tmp->arg_sign >= 1)
	{
	/*	if (tmp->flag == '0' && tmp->flag2 == ' ' && tmp->precision_flag == 1)
		{
			tmp->data = ft_strjoin_left(" ", tmp->data);
			tmp->precision--;
		}*/
		if (tmp->flag2 == '+' && tmp->flag == '-')
			tmp->data = ft_strjoin_left("+", tmp->data);
		if (tmp->arg_sign == 2 || tmp->flag_1 == '+')
			tmp->data = ft_strjoin_left("+", tmp->data);
		if (tmp->flag == '0' && tmp->flag2 == '+' && tmp->arg_sign == 1 && tmp->precision_flag == 0)
			tmp->data = ft_strjoin_left("+", tmp->data);
	}
}

char	*ft_print_d(var *tmp)
{
/*	
	ft_putchar('|');
	ft_putchar(tmp->flag);
	ft_putchar(tmp->flag_1);
	ft_putchar(tmp->flag2);
	ft_putchar('|');
	*/

	if (tmp->arg_sign == -1)
		ft_if_ngtv_rgsgn(tmp);
	if ((int)ft_strlen(tmp->data) < tmp->precision && tmp->precision_flag == 1)
		while (((int)ft_strlen(tmp->data) < tmp->precision && tmp->precision <= tmp->width))
			tmp->data = ft_strjoin_left("0", tmp->data);
	if (tmp->arg_sign == -1 && tmp->width > tmp->precision && tmp->precision_flag == 1)
		tmp->data = ft_strjoin_left("-", tmp->data);
	if (tmp->flag == '+' && (int)ft_strlen(tmp->data) < tmp->precision)
	{
		tmp->flag = '0';
		tmp->flag2 = '+';
	}
	if (tmp->flag == '0' && tmp->precision > 0 && tmp->precision_flag == 1)
	{
		while ((int)ft_strlen(tmp->data) < tmp->precision)
			tmp->data = ft_strjoin_left("0", tmp->data);
		if (tmp->flag == '0' && tmp->flag2 == '+' && tmp->arg_sign == 1)
			tmp->data = ft_strjoin_left("+", tmp->data);
		if (tmp->arg_sign == -2)
		{
			tmp->arg_sign = -1;
			tmp->width++;
			tmp->data = ft_strjoin_left("-", tmp->data);
		}
		if (tmp->flag2 == ' ' && tmp->arg_sign >= 1)
			tmp->width--;
		while (tmp->width > (int)ft_strlen(tmp->data))
			tmp->data = ft_strjoin_left(" ", tmp->data);
	}
	if (tmp->flag_1 == '0' && tmp->flag == '+')
	{
		if (tmp->flag != '?')
			tmp->width--;
		while ((int)ft_strlen(tmp->data) < tmp->width)
			tmp->data = ft_strjoin_left("0", tmp->data);
	}
	if (tmp->arg_sign == 1)
		ft_if_pstv_rgsgn(tmp);
	if (tmp->precision_flag == 1)
	{
		if (tmp->precision > (int)ft_strlen(tmp->data))
		{
			if (tmp->flag2 == '+' && tmp->flag_1 != ' ')
				tmp->flag_1 = tmp->flag2;
			tmp->flag = '0';
			tmp->width = (tmp->arg_sign == -1) ? tmp->precision - 1 : tmp->precision;
		}
		//if (tmp->precision <= (int)ft_strlen(tmp->data))
		//	tmp->precision = 0;
		if (tmp->arg_sign == -2 && tmp->precision < tmp->width)
		{
			tmp->arg_sign = -3;
			tmp->data = ft_strjoin_left("-", tmp->data);
		}
	}
	if (tmp->width && tmp->width > (int)ft_strlen(tmp->data))
	{
		if (tmp->flag != '-')
			tmp->data = ft_fil_whitespaces(tmp, tmp->width, (int)ft_strlen(tmp->data));
		else if (tmp->flag == '-')
			tmp->data = ft_end_whitespaces(tmp, tmp->width, (int)ft_strlen(tmp->data));
	}
	ft_rgsgn1(tmp);
	if (tmp->flag_1 == ' ')
		tmp->data = ft_strjoin_left(" ", tmp->data);
	return (tmp->data);
}
