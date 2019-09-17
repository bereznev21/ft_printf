/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 03:37:29 by tlynesse          #+#    #+#             */
/*   Updated: 2018/11/27 13:02:13 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	nb;
	char			c;

	if (n < 0)
	{
		write(1, "-", 1);
		nb = (unsigned int)(-n);
	}
	else
		nb = (unsigned int)n;
	if (nb < 10)
	{
		c = '0' + nb;
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}
