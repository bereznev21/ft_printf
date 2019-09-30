/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:43:57 by rpoetess          #+#    #+#             */
/*   Updated: 2019/09/28 19:33:32 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_if_ngtv_rgsgn(var *tmp)
{
	if (tmp->precision_flag == 0)
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
		if (tmp->flag == '0')
		{
			if (tmp->flag2 == ' ' && tmp->flag_1 == '?')
			{
				if (tmp->width > (int)ft_strlen(tmp->data))
					tmp->width--;
			}
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
		if (tmp->flag == ' ')
			if (tmp->flag2 == '?' && tmp->flag_1 == '?')
				tmp->data = ft_strjoin_left("-", tmp->data);
	}
	if (tmp->precision_flag == 1)
	{
		if (tmp->flag == '?')
		{	
			if (tmp->precision < (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("-", tmp->data);
			if (tmp->precision >= (int)ft_strlen(tmp->data))
			{
				if (tmp->width)
				{
					if (tmp->width <= (int)ft_strlen(tmp->data) && tmp->precision < tmp->width)
						tmp->data = ft_strjoin_left("-", tmp->data);
					if (tmp->precision > tmp->width && tmp->precision > (int)ft_strlen(tmp->data))
						tmp->flag = '0';
				}
				else if (tmp->width == 0)
				{
					if (tmp->precision <= (int)ft_strlen(tmp->data))
						tmp->data = ft_strjoin_left("-", tmp->data);
				}
			}
		}
		if (tmp->flag == '-')
		{
			if (tmp->flag2 == '?')
				if (tmp->precision < (int)ft_strlen(tmp->data))
					tmp->data = ft_strjoin_left("-", tmp->data);
			if (tmp->flag2 == '+')
				if (tmp->precision < (int)ft_strlen(tmp->data))
					tmp->data = ft_strjoin_left("-", tmp->data);
			if (tmp->flag2 == ' ' && tmp->flag_1 == '?' )
				if (tmp->precision < (int)ft_strlen(tmp->data))
					tmp->data = ft_strjoin_left("-", tmp->data);
		}
		if (tmp->flag == ' ')
		{
			if (tmp->flag2 == '?' && tmp->flag_1 == '?')
				if (tmp->precision < (int)ft_strlen(tmp->data))
					tmp->data = ft_strjoin_left("-", tmp->data);
		}
		if (tmp->flag == '0')
		{
			if (tmp->flag2 == '?')
			{
				if (tmp->flag_1 == '?')
				{
					if (tmp->precision <= (int)ft_strlen(tmp->data) && tmp->width < tmp->precision)
						tmp->data = ft_strjoin_left("-", tmp->data);
					tmp->flag = '?';
					if (tmp->width == tmp->precision && tmp->width < (int)ft_strlen(tmp->data))
					{
						tmp->data = ft_strjoin_left("-", tmp->data);
						tmp->width--;
					}
					if (tmp->width > tmp->precision && tmp->precision < (int)ft_strlen(tmp->data))
						tmp->data = ft_strjoin_left("-", tmp->data);
				}
			}
			if (tmp->flag2 == '+')
			{
				if (tmp->flag_1 == '?')
					tmp->flag = '?';
				if (tmp->precision <= (int)ft_strlen(tmp->data))
					tmp->data = ft_strjoin_left("-", tmp->data);
			}
			if (tmp->flag2 == ' ')
			{
				tmp->flag = '?';
				if (tmp->precision <= (int)ft_strlen(tmp->data))
					tmp->data = ft_strjoin_left("-", tmp->data);
			}
		}
		if (tmp->flag == '+')
		{
			if (tmp->flag2 == '?')
			{
				if (tmp->flag_1 == '?')
					if (tmp->precision < (int)ft_strlen(tmp->data))
						tmp->data = ft_strjoin_left("-", tmp->data);
				if (tmp->flag_1 == '0')
					if (tmp->precision < (int)ft_strlen(tmp->data))
						tmp->data = ft_strjoin_left("-", tmp->data);
			}
			if (tmp->flag2 == ' ' && tmp->flag_1 == '?')
			{
				if (tmp->precision < (int)ft_strlen(tmp->data))
					tmp->data = ft_strjoin_left("-", tmp->data);
			}
		}
	}
}

void	ft_if_pstv_rgsgn(var *tmp)
{
	if (tmp->precision_flag == 0)
	{
		if (tmp->flag == ' ')
		{
			if (tmp->flag2 == '?')
			{
				if (tmp->width <= (int)ft_strlen(tmp->data))
					tmp->data = ft_strjoin_left(" ", tmp->data);
			}
		}
		if (tmp->flag == '+')
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
	if (tmp->precision_flag == 1)
	{
		if (tmp->flag == '+')
		{
			if (tmp->flag2 == '?' && tmp->flag_1 == '?')
			{
				if (tmp->precision < (int)ft_strlen(tmp->data))
					tmp->data = ft_strjoin_left("+", tmp->data);
				if (tmp->precision > (int)ft_strlen(tmp->data) && tmp->precision > tmp->width)
					tmp->flag_1 = '+';
			}
			if (tmp->flag2 == '?' && tmp->flag_1 == '0')
				if (tmp->precision < (int)ft_strlen(tmp->data))
					tmp->data = ft_strjoin_left("+", tmp->data);
			if (tmp->flag2 == ' ' && tmp->flag_1 == '?' && tmp->precision < (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("+", tmp->data);
		}
		if (tmp->flag == '0')
		{
			if (tmp->flag2 == '?')
				tmp->flag = '?';
			if (tmp->flag2 == '+' && tmp->flag_1 == '?')
			{
				if (tmp->precision < (int)ft_strlen(tmp->data))
					tmp->data = ft_strjoin_left("+", tmp->data);
				tmp->flag = '+';
				tmp->flag2 = '?';
			}
			if (tmp->flag2 == ' ' && tmp->flag_1 == '?')
			{
				tmp->flag = ' ';
				if (tmp->width <= (int)ft_strlen(tmp->data) && tmp->precision < (int)ft_strlen(tmp->data))
					tmp->data = ft_strjoin_left(" ", tmp->data);
			}
		}
		if (tmp->flag == '?')
		{
			if (tmp->precision > tmp->width && tmp->precision > (int)ft_strlen(tmp->data))
				tmp->flag = '0';
		}
		if (tmp->flag == '-')
		{
			if (tmp->flag2 == '+')
		 	{	
				if (tmp->precision < (int)ft_strlen(tmp->data))
					tmp->data = ft_strjoin_left("+", tmp->data);
			}
			if (tmp->flag2 == ' ' && tmp->flag_1 == '?')
			{
				if (tmp->width <= (int)ft_strlen(tmp->data) && tmp->precision < (int)ft_strlen(tmp->data))
					tmp->data = ft_strjoin_left(" ", tmp->data);
				tmp->width--;
			}
		}
		if (tmp->flag == ' ')
		{
			if (tmp->flag2 == '?' && tmp->flag_1 == '?')
				if (tmp->precision < (int)ft_strlen(tmp->data))
					tmp->data = ft_strjoin_left(" ", tmp->data);
		}
	}
}

char	*ft_print_d(var *tmp)
{
	if (tmp->arg_sign == -1)
		ft_if_ngtv_rgsgn(tmp);
	if (tmp->arg_sign == 1)
		ft_if_pstv_rgsgn(tmp);
	if ((int)ft_strlen(tmp->data) < tmp->precision && tmp->precision_flag == 1)
		while (((int)ft_strlen(tmp->data) < tmp->precision && tmp->precision <= tmp->width))
			tmp->data = ft_strjoin_left("0", tmp->data);
/*
	ft_putchar('|');
	ft_putchar(tmp->flag);
	ft_putchar(tmp->flag_1);
	ft_putchar(tmp->flag2);
	ft_putchar('|');
	*/
	if (tmp->arg_sign == 1 && tmp->precision == (int)ft_strlen(tmp->data))
	{
		if (tmp->flag == '+')
		{
			if (tmp->flag2 == '?')
				tmp->data = ft_strjoin_left("+", tmp->data);
			if (tmp->flag2 == ' ' && tmp->flag_1 == '?')
				tmp->data = ft_strjoin_left("+", tmp->data);
		}
		if (tmp->flag == '-')
			if (tmp->flag2 == '+')
				tmp->data = ft_strjoin_left("+", tmp->data);
		if (tmp->flag == ' ')
		{
			if (tmp->flag2 == '?' && tmp->flag_1 == '?')
				tmp->data = ft_strjoin_left(" ", tmp->data);
			if (tmp->flag2 == ' ' && tmp->flag_1 == '?')
				tmp->data = ft_strjoin_left(" ", tmp->data);
		}
	}
	if (tmp->arg_sign == -1 && tmp->precision_flag == 1 && tmp->precision == (int)ft_strlen(tmp->data))
	{
		if (tmp->flag == '?')
			if (tmp->width > 0)
				tmp->data = ft_strjoin_left("-", tmp->data);
		if (tmp->flag == '-')
		{
			if (tmp->flag2 == '?')
				tmp->data = ft_strjoin_left("-", tmp->data);
			if (tmp->flag2 == '+')
				tmp->data = ft_strjoin_left("-", tmp->data);
			if (tmp->flag2 == ' ' && tmp->flag_1 == '?')
				tmp->data = ft_strjoin_left("-", tmp->data);
		}
		if (tmp->flag == '+')
		{
			if (tmp->flag2 == '?')
				if (tmp->flag_1 == '0' || tmp->flag_1 == '?')
					tmp->data = ft_strjoin_left("-", tmp->data);
			if (tmp->flag2 == ' ' && tmp->flag_1 == '?')
				tmp->data = ft_strjoin_left("-", tmp->data);
		}
		if (tmp->flag == ' ')
		{
			if (tmp->flag2 == '?' && tmp->flag_1 == '?')
				tmp->data = ft_strjoin_left("-", tmp->data);
		}
	}
	if (tmp->width == 0)
		tmp->width = tmp->precision;
	if (tmp->width)
	{
		if (tmp->precision > (int)ft_strlen(tmp->data))
		{
			if (tmp->flag == '+')
				tmp->flag_1 = '+';
			if (tmp->flag == ' ' && tmp->flag_1 == '?' && tmp->flag2 == '?')
				tmp->flag_1 = ' ';
			if (tmp->flag == ' ' && tmp->flag2 == '-' && tmp->flag2 == '?')
				tmp->flag_1 = 's';
			tmp->flag = '0';
		}
		if (tmp->precision > tmp->width)
			tmp->width = tmp->precision;
		if (tmp->width && tmp->width > (int)ft_strlen(tmp->data))
		{
			if (tmp->flag != '-')
				tmp->data = ft_fil_whitespaces(tmp, tmp->width, (int)ft_strlen(tmp->data));
			else if (tmp->flag == '-')
				tmp->data = ft_end_whitespaces(tmp, tmp->width, (int)ft_strlen(tmp->data));
		}
	}
	if (tmp->arg_sign == 1)
	{
		if (tmp->flag == '0')
		{

			if (tmp->flag2 == '+' && tmp->flag_1 == '?' && tmp->width == (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("+", tmp->data);
			if (tmp->flag2 == '+' && tmp->flag_1 == '0'&& tmp->width == (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("+", tmp->data);
			if (tmp->flag2 == ' ')
			{
				if (tmp->flag_1 == '?')
					tmp->data = ft_strjoin_left(" ", tmp->data);
				if (tmp->flag_1 == '+' && tmp->precision == (int)ft_strlen(tmp->data))
					tmp->data = ft_strjoin_left("+", tmp->data);
				if (tmp->flag_1 == '0' && tmp->width == (int)ft_strlen(tmp->data))
					tmp->data = ft_strjoin_left("+", tmp->data);
				if (tmp->flag_1 == 'p')
				{
					if (tmp->width == (int)ft_strlen(tmp->data))
						tmp->data = ft_strjoin_left("+", tmp->data);
				}
			}
			if (tmp->flag2 == '?')
			{

				if (tmp->flag_1 == '+' && tmp->precision == (int)ft_strlen(tmp->data) && tmp->precision_flag == 1)
					tmp->data = ft_strjoin_left("+", tmp->data);
				if (tmp->flag_1 == '0' && tmp->width == (int)ft_strlen(tmp->data) && tmp->precision_flag == 0)
					tmp->data = ft_strjoin_left("+", tmp->data);
				if (tmp->flag_1 == 's')
					tmp->data = ft_strjoin_left(" ", tmp->data);
				if (tmp->flag_1 == ' ' && tmp->precision == (int)ft_strlen(tmp->data) && tmp->precision_flag == 1)
					tmp->data = ft_strjoin_left(" ", tmp->data);
			}
		}
		if (tmp->flag == '+')
			if (tmp->flag2 == '?' && tmp->precision == (int)ft_strlen(tmp->data) && tmp->precision_flag == 1)
				tmp->data = ft_strjoin_left("+", tmp->data);
		if (tmp->flag == '-')
		{
			if (tmp->flag_1 == '?' && tmp->flag2 == ' ' && tmp->width == (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left(" ", tmp->data);
		}
	}
	if (tmp->arg_sign == -1)
	{
		if (tmp->flag == '0')
		{
			if (tmp->flag2 == '?' && tmp->width == (int)ft_strlen(tmp->data) && tmp->precision_flag == 0)
				tmp->data = ft_strjoin_left("-", tmp->data);
			if (tmp->flag2 == '+' && tmp->width == (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("-", tmp->data);
			if (tmp->flag2 == ' ' && tmp->flag_1 == '+' && tmp->precision == (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("-", tmp->data);
			if (tmp->flag2 == ' ' && tmp->flag_1 == '?')
				tmp->data = ft_strjoin_left("-", tmp->data);
			if (tmp->flag2 == '?' && tmp->precision >= (int)ft_strlen(tmp->data))
				tmp->data = ft_strjoin_left("-", tmp->data);
		}
	}
	return (tmp->data);
}
