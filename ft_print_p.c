/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:13:29 by rpoetess          #+#    #+#             */
/*   Updated: 2019/09/18 19:44:15 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_p(var *tmp)
{
	int     w;
	int     slen;
	int     prec;
	char    *temp;
	/*
	prec = tmp->precision;
	if (tmp->data)
	{
		if (tmp->data[0] != '0' && !tmp->precision_flag && slen < tmp->width)
			tmp->data = ft_strjoin_left("7fff", tmp->data);
	//	else if (ft_strlen(tmp->data) >= 6)
	//		tmp->data = ft_strjoin_left("10", tmp->data);
		else
			while (prec-- > slen)
				tmp->data = ft_strjoin_left("0", tmp->data);
		tmp->data = ft_strjoin_left("0x", tmp->data);
	}
	tmp->flag = tmp->flag == '-' ? tmp->flag : '?';
	slen = ft_strlen(tmp->data);
	w = tmp->width > slen ? tmp->width : slen;
	if (tmp->flag == '-')
		ft_end_whitespaces(tmp, w - tmp->precision, slen);
	else
		ft_fil_whitespaces(tmp, w - tmp->precision, slen);
	*/
	//if (tmp->flag == '-')
	//	tmp->data = ft_strjoin_left("0x", tmp->data);
	tmp->flag2 = '#';
	tmp->data = ft_print_x(tmp);
	return (tmp->data);
}

/*
char	*ft_print_p(var *tmp)
{
	int w;
	int slen;

	tmp->data = ft_strjoin("0x", tmp->data);
	tmp->flag = tmp->flag == '-' ? tmp->flag : '?';
	slen = ft_strlen(tmp->data);
	w = tmp->width > slen ? tmp->width : slen;
	if (tmp->flag == '-')
		ft_end_whitespaces(tmp, w, slen);
	else
		ft_fil_whitespaces(tmp, w, slen);
	return (tmp->data);
}
*/
