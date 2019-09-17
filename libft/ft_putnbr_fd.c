/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 11:23:07 by tlynesse          #+#    #+#             */
/*   Updated: 2018/11/27 13:00:20 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;
	char			c;

	if (fd)
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			nb = (unsigned int)(-n);
		}
		else
			nb = (unsigned int)n;
		if (nb < 10)
		{
			c = '0' + nb;
			write(fd, &c, 1);
		}
		else
		{
			ft_putnbr_fd(nb / 10, fd);
			ft_putnbr_fd(nb % 10, fd);
		}
	}
}
