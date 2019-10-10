/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list_var.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 23:24:26 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/09 15:02:50 by rpoetess         ###   ########.fr       */
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
	free(tmp->data);
	free(tmp);
	return (nul);
}

int		ft_free_mas(t_var *tmp)
{
	free(tmp->data);
	free(tmp);
	return (0);
}

int		ft_create_list_var(const char *mas, int i, va_list str)
{
	char	*str1;
	t_var	*tmp;

	str1 = 0;
	tmp = (t_var*)malloc(sizeof(t_var));
	tmp = ft_srchflgs(tmp, &i, mas);
	if (!ft_check_type(mas[(i)]) || mas[i] == '\0')
		return (ft_free_mas(tmp));
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
		str1 = ft_strdup("0");
	if (str1 == 0 && tmp->type == 'c')
		return (ft_zero_char(tmp, str1));
	if (!(tmp->data))
		tmp->data = ft_strdup(str1);
	free(str1);
	return (ft_controller(tmp));
}
