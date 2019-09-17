/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:11:30 by rpoetess          #+#    #+#             */
/*   Updated: 2019/09/04 18:11:32 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_check_type(char type)
{
	if (type == 'c' || type == 'd' || type == 'i' ||
		type == 'e' || type == 'E' || type == 'f' ||
		type == 'g' || type == 'G' || type == 'o' ||
		type == 's' || type == 'u' || type == 'x' ||
		type == 'X' || type == 'p' || type == 'n' ||
		type == '%' || type == 'U')
		return (1);
	return (0);
}
