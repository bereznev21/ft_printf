/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:10:55 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/07 14:58:17 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write(char *res)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (res[i] != '\0')
	{
		ft_putchar(res[i++]);
		len++;
	}
	//free(res);
	return (len);
}

int	ft_controller(t_var *tmp)
{
	char *res;
	//res = ft_strdup("");
	if (tmp->type == '%')
		res = ft_print_c(tmp);
	else if (tmp->type == 'c')
		res = ft_print_c(tmp);
	else if (tmp->type == 's')
		res = ft_print_s(tmp);
	else if (tmp->type == 'p')
		res = ft_print_p(tmp);
	else if (tmp->type == 'd' || tmp->type == 'i')
		res = ft_print_d(tmp);
	else if (tmp->type == 'o')
		res = ft_print_o(tmp);
	else if (tmp->type == 'u' || tmp->type == 'U')
		res = ft_print_u(tmp);
	else if (tmp->type == 'x' || tmp->type == 'X')
		res = ft_print_x(tmp);
	if (tmp->type == 'f')
		res = ft_print_f(tmp);
	//if (ft_strlen(tmp->data) != 0)
	//free(tmp->data);
	free(tmp);
	return (ft_write(res));
}
