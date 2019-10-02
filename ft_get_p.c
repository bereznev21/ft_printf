/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:27:13 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/02 22:27:21 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_p(char *str1, t_var *tmp, va_list str)
{
	int long long	nb;

	nb = (uintmax_t)va_arg(str, void *);
	str1 = ft_uitoa_base(nb, 16, tmp->type);
	return (str1);
}
