/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 16:39:07 by rpoetess          #+#    #+#             */
/*   Updated: 2019/09/29 17:28:39 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_u(var *tmp)
{

	if (tmp->precision == 0 && tmp->precision_flag == 1)
	{
		free(tmp->data);
		tmp->data = "";
	}
	if (tmp->flag == ' ' || tmp->flag == '+')
		tmp->flag = '?';
	tmp->data = ft_print_d(tmp);
	return (tmp->data);
}
