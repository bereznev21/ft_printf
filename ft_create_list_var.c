/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list_var.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 23:24:26 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/08 16:31:01 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_zero_char(t_var *tmp, char *str1)
{
	int	nul;

	nul = 1;
	if (tmp->flag != '-')
	{
		while (tmp->width-- > 1)
		{
			ft_putchar(' ');
			nul++;
		}
	}
	write(1, &str1, 1);
	if (tmp->flag == '-')
	{
		while (tmp->width-- > 1)
		{
			ft_putchar(' ');
			nul++;
		}
	}
	return (nul);
}

int		ft_create_list_var(const char *mas, int i, va_list str)
{
	char	*str1;
	t_var	*tmp;

	str1 = 0;
	tmp = (t_var*)malloc(sizeof(t_var));
	tmp = ft_srchflgs(tmp, &i, mas);
	/*if (!ft_check_type(mas[(i)]))
		return (0);*/
	/*if (mas[i] == '\0')
		exit(0);*/
	if (!ft_check_type(mas[(i)]) || mas[i] == '\0')
		return (0);
	tmp->type = mas[i];
	if (mas[i] == '%')
	{
		tmp->data = ft_strnew(0);
		if (tmp->data)
			tmp->data = ft_strjoin_char(tmp->data, mas[i]);
		return (ft_controller(tmp));
	}
	str1 = ft_create_arg_string(str1, tmp, str);
	if (!str)
		str1 = 0;
	if (!(tmp->data))
		tmp->data = ft_strdup(str1);
	if (str1 == 0 && tmp->type == 'c')
		return (ft_zero_char(tmp, str1));
	else
		free(str1);
	return (ft_controller(tmp));
}
