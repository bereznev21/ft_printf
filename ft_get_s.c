/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:10:53 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/08 15:36:03 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_s(char *str1, t_var *tmp, va_list str)
{
	str1 = va_arg(str, char*);
	str1 = !(str1) ? ft_strdup("(null)") : str1;
	str1 = ft_strjoin("", str1);
	return (str1);
}
