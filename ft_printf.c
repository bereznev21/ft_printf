/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:35:51 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/08 16:18:31 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_create_arg_string(char *str1, t_var *tmp, va_list str)
{
	//char	*res;

	//res = ft_strdup("");
	if (tmp->type == 'c' || tmp->type == '%')
		str1 = ft_get_c(str1, tmp, str);
	else if (tmp->type == 's')
		str1 = ft_get_s(str1, tmp, str);
	else if (tmp->type == 'd' || tmp->type == 'i')
		str1 = ft_get_d(str1, tmp, str);
	else if (tmp->type == 'u' || tmp->type == 'U')
		str1 = ft_get_u(str1, tmp, str);
	else if (tmp->type == 'o')
		str1 = ft_get_o(str1, tmp, str);
	else if (tmp->type == 'f')
		str1 = ft_get_f(str1, tmp, str);
	else if (tmp->type == 'x' || tmp->type == 'X')
		str1 = ft_get_x(str1, tmp, str);
	else if (tmp->type == 'p')
		str1 = ft_get_p(str1, tmp, str);
	//str1 = ft_strjoin_left(res, str1);
	//free(res);
	//free(str);
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
	while (format[*i] == ' ' || (format[*i] >= '0' && format[*i] <= '9')
	|| format[*i] == '#' || format[*i] == '-' || format[*i] == '+'
	|| format[*i] == '.' || format[*i] == 'h' || format[*i] == 'l'
	|| format[*i] == 'L' || format[*i] == 'j' || format[*i] == 'z')
		(*i)++;
	if (ft_check_type(format[*i]))
		(*i)++;
	else
		return (0);
	return (len);
}

int			ft_printf(const char *format, ...)
{
	int			i;
	int			len;
	va_list		str;

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
