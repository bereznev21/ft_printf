/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:10:53 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/07 16:43:57 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_s(char *str1, t_var *tmp, va_list str)
{
	str1 = ft_strdup("");
	str1 = ft_strjoin(str1, va_arg(str, char*));
	//str1 = va_arg(str, char*);
	return (str1);
}
