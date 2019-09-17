/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 08:31:14 by tlynesse          #+#    #+#             */
/*   Updated: 2018/12/09 16:59:00 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sign(const char **s)
{
	if (**s == '-')
	{
		(*s)++;
		return (-1);
	}
	else if (**s == '+')
		(*s)++;
	return (1);
}

int			ft_atoi(const char *str)
{
	long	res;
	int		fl;
	long	tmp;

	res = 0;
	while (*str == ' ' || *str == '\t' || *str == '\v' ||
			*str == '\n' || *str == '\f' || *str == '\r')
		str++;
	fl = ft_sign(&str);
	while (*str >= '0' && *str <= '9')
	{
		tmp = res;
		res = res * 10 + fl * (long)(*(str++) - '0');
		if ((tmp < 0) && (tmp < res))
			return (0);
		if ((tmp > 0) && (tmp > res))
			return (-1);
	}
	return ((int)(res));
}
