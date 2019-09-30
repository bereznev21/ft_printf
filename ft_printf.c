/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:35:51 by rpoetess          #+#    #+#             */
/*   Updated: 2019/09/13 18:11:22 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_create_arg_string(char *str1, var *tmp,
								va_list str)
{
	if (tmp->type == 'c' || tmp->type == '%')
		str1 = ft_get_c(str1, tmp, str);
	else if (tmp->type == 's')
		str1 = va_arg(str, char*);
	else if (tmp->type == 'd' || tmp->type == 'i')
		str1 = ft_get_d(str1, tmp, str);
	else if (tmp->type == 'u' || tmp->type == 'U')
		str1 = ft_get_u(str1, tmp, str);
	else if (tmp->type == 'o')
		str1 = ft_get_o(str1, tmp, str);
	else if (tmp->type == 'f')
		str1 = ft_get_f(str1, tmp, str);
	else if (tmp->type == 'x' || tmp->type == 'X' || tmp->type == 'p')
		str1 = ft_get_x(str1, tmp, str);
	return (str1);
}

int			ft_ifnopercent(const char *format, int *i)
{
	int len;

	len = 0;
	while (format[*i] != '%' && format[*i] != '\0')
	{
		write(1, &format[(*i)++], 1);
		len++;
	}
	return (len);
}

int			ft_ifprecent(const char *format, va_list str, int *i)
{
	int	len;

	len = 0;
	len = ft_create_list_var(format, ++(*i), str);
	while (!ft_check_type(format[*i]) && format[*i] != '\0')
		(*i)++;
	(*i)++;
	return (len);
}

int				ft_printf(const char *format, ...)
{
	va_list		str;
	int			i;
	int			len;

	i = 0;
	len = 0;
	va_start(str, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%' && format[i] != '\0')
			len += ft_ifnopercent(format, &i);
		if (format[i] == '%')
			len += ft_ifprecent(format, str, &i);
	}
	va_end(str);
	return (len);
}