/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:12:51 by rpoetess          #+#    #+#             */
/*   Updated: 2019/09/13 20:00:52 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	digit_count(intmax_t nb, int base)
{
	size_t		i;

	i = 0;
	while (nb)
	{
		nb /= base;
		i++;
	}
	return (i);
}

char			*ft_itoa_base(intmax_t value, int base, char type)
{
	char	*ret;
	char	*tab_base;
	int		taille;
	int		i;
	int		sign;

	tab_base = 0;
	if (base < 2 || base > 16)
		return (0);
	if (base == 10 && value == -2147483648)
		return ("-2147483648");
	sign = 0;
	if (base == 10 && value < 0)
		sign = -1;
	if (value == 0)
		return ("0");
	tab_base = (char*)malloc(sizeof(char) * 17);
	if (type == 'X')
		tab_base = "0123456789ABCDEF";
	else
		tab_base = "0123456789abcdef";
	taille = digit_count(value, base);
	taille += (sign ? 1 : 0);
	ret = (char *)malloc(sizeof(char) * (taille + 1));
	i = 1;
	sign ? (ret[0] = '-') : 0;
	while (value != 0)
	{
		ret[taille - i++] = tab_base[value % base];
		value /= base;
	}
	ret[taille] = '\0';
	return (ret);
}
