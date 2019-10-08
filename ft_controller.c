/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:10:55 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/08 19:42:34 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write(t_var *tmp)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (tmp->data[i] != '\0')
	{
		ft_putchar(tmp->data[i++]);
		len++;
	}
	free(tmp->data);
	free(tmp);
	return (len);
}

int	ft_controller(t_var *tmp)
{
	if (tmp->type == '%')
		ft_print_c(tmp);
	else if (tmp->type == 'c')
		ft_print_c(tmp);
	else if (tmp->type == 's')
		ft_print_s(tmp);
	else if (tmp->type == 'p')
		ft_print_p(tmp);
	else if (tmp->type == 'd' || tmp->type == 'i')
		ft_print_d(tmp);
	else if (tmp->type == 'o')
		ft_print_o(tmp);
	else if (tmp->type == 'u' || tmp->type == 'U')
		ft_print_u(tmp);
	else if (tmp->type == 'x' || tmp->type == 'X')
		ft_print_x(tmp);
	if (tmp->type == 'f')
		ft_print_f(tmp);
	return (ft_write(tmp));
}
