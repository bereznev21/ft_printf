/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lst_mem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 15:10:03 by tlynesse          #+#    #+#             */
/*   Updated: 2018/12/09 15:10:09 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_free_lst_mem(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = *lst;
		(*lst) = (*lst)->next;
		free(tmp);
		tmp = 0;
	}
	return (*lst);
}
