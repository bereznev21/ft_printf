/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:12:51 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/01 19:35:01 by rpoetess         ###   ########.fr       */
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

char			*ft_itoa_base(intmax_t value, int base, var *tmp)
{
	char	*ret;
	char	*tab_base;
	int		taille;
	int		i;
	int		sign;

	tab_base = 0;
	i = 1;
	sign = (base == 10 && value < 0) ? -1 : 0;
	if (base < 2 || base > 16)
		return (0);
	if (value == 0)
		return ("0");
	tab_base = (char*)malloc(sizeof(char) * 17);
	tab_base = (tmp->type == 'X') ? "0123456789ABCDEF" : "0123456789abcdef";
	taille = digit_count(value, base) + sign;
	ret = (char *)malloc(sizeof(char) * (taille + 1));
	sign ? (ret[0] = '-') : 0;
	while (value != 0)
	{
		ret[taille - i++] = tab_base[value % base];
		value /= base;
	}
	ret[taille] = '\0';
	return (ret);
}
