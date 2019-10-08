/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:02:25 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/08 21:37:05 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t	udigit_count(uintmax_t nb, int base)
{
	intmax_t	i;

	i = 0;
	while (nb)
	{
		nb /= base;
		i++;
	}
	return (i);
}

char			*ft_uitoa_base(uintmax_t value, int base, char type)
{
	char	*ret;
	char	*tab_base;
	int		taille;
	int		i;
	int		sign;

	if (base < 2 || base > 16)
		return (0);
	sign = 0;
	if (value == 0)
		return (ft_strdup("0"));
	tab_base = (type == 'X') ? ft_strdup("0123456789ABCDEF") :
	ft_strdup("0123456789abcdef");
	taille = udigit_count(value, base) + (sign ? 1 : 0);
	ret = (char *)malloc(sizeof(char) * (taille + 1));
	i = 1;
	sign ? (ret[0] = '-') : 0;
	while (value != 0)
	{
		ret[taille - i++] = tab_base[value % base];
		value /= base;
	}
	ret[taille] = '\0';
	free(tab_base);
	return (ret);
}
