/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <tlynesse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:13:29 by rpoetess          #+#    #+#             */
/*   Updated: 2019/09/13 20:04:29 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_p(var *tmp)
{
	int w;
	int slen;

	if (tmp->data != 0)
	{
		if ((int)ft_strlen(tmp->data) != 1 )
			tmp->data = ft_strjoin("7fff", tmp->data);
		tmp->data = ft_strjoin("0x", tmp->data);
	}
	tmp->flag = tmp->flag == '-' ? tmp->flag : '?';
	slen = ft_strlen(tmp->data);
	w = tmp->width > slen ? tmp->width : slen;
	if (tmp->flag == '-')
		ft_end_whitespaces(tmp, w, slen);
	else
		ft_fil_whitespaces(tmp, w, slen);
	return (tmp->data);
}
