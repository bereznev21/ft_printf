/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:30:58 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/07 16:26:38 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_fil_whitespaces(t_var *s, int wdth, int len)
{
	int		i;
	char	*res;

	i = 0;
	if (s->flag != '0')
		while (wdth - len > i++)
			//s->data = ft_strjoin_left(" ", s->data);
			s->data = ft_strjoin(" ", s->data);
	else
		while (wdth - len > i++)
			//s->data = ft_strjoin_left("0", s->data);
			s->data = ft_strjoin("0", s->data);
	return (s->data);
}

char	*ft_end_whitespaces(t_var *s, int wdth, int len)
{
	int		i;

	i = 0;
	while (wdth - len > i++)
		//s->data = ft_strjoin_right(s->data, " ");
		s->data = ft_strjoin(s->data, " ");
	return (s->data);
}

char	*ft_crop_str(char *str, int len, int crop)
{
	char	*tmp;

	if (len > crop)
	{
		tmp = ft_strnew(crop);
		tmp = ft_strncpy(tmp, str, crop);
	}
	str = tmp;
	return (str);
}

void	ft_print_s(t_var *s)
{
	int		wdth;
	int		len;

	wdth = (s->width > 0) ? s->width : 0;
	s->data = (!(s->data)) ? ft_strdup("(null)") : s->data;
	if (s->precision == 0 && s->precision_flag == 1 && s->type == 's')
		s->data = ft_strdup("");
	len = ft_strlen(s->data);
	len = (s->arg_sign == -1 || s->flag2 == '+') ? len-- : len;
	s->precision = (s->precision >= len) ? 0 : s->precision;
	if (s->precision)
	{
		s->data = ft_crop_str(s->data, len, s->precision);
		len = (len > s->precision) ? s->precision : len;
	}
	if (s->width && s->width > (int)ft_strlen(s->data))
		s->data = (s->flag != '-') ? ft_fil_whitespaces(s, wdth, len) :
		ft_end_whitespaces(s, wdth, len);
}
