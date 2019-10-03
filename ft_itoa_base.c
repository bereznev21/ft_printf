/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:12:51 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/03 19:51:36 by tlynesse         ###   ########.fr       */
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

void			ft_alf_maker(char *alf, char type)
{
	int i;

	i = -1;
	while (++i <= 9)
		alf[i] = '0' + i;
	if (type == 'X')
		while (++i <= 15)
			alf[i] = 'A' + i - 10;
	else if (type == 'x')
		while (++i <= 15)
			alf[i] = 'a' + i - 10;
	alf[i] = 0;
}

char			*ft_itoa_base(intmax_t value, int base, t_var *tmp)
{
	char		*ret;
	char		tab_base[17];
	int			taille;
	int			i;
	int			sign;

	i = 1;
	sign = (base == 10 && value < 0) ? -1 : 0;
	if (base < 2 || base > 16)
		return (0);
	if (value == 0)
		return ("0");
	ft_alf_maker(tab_base, tmp->type);
	taille = digit_count(value, base) + sign;
	if (!(ret = ft_strnew((size_t)taille)))
		return (0);
	sign ? ret[0] = '-' : 0;
	while (value)
	{
		ret[taille - i++] = tab_base[value % base];
		value /= base;
	}
	ret[taille] = 0;
	return (ret);
}
