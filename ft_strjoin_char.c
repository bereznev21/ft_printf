/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:46:09 by rpoetess          #+#    #+#             */
/*   Updated: 2019/09/04 13:46:11 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_strjoin_char(char *str, char end)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i])
		i++;
	tmp = (char*)malloc(sizeof(char) * i + 2);
	tmp = ft_strcpy(tmp, str);
	tmp[i] = end;
	tmp[i + 1] = '\0';
	free(str);
	str = tmp;
	return (str);
}
