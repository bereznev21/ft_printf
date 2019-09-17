/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:16:11 by tlynesse          #+#    #+#             */
/*   Updated: 2018/12/09 12:20:12 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_lst;

	if (!(new_lst = (t_list*)malloc(sizeof(t_list))))
		return (0);
	if (!content || !content_size)
	{
		new_lst->content = 0;
		new_lst->content_size = 0;
	}
	else
	{
		if (!(new_lst->content = (void*)malloc(content_size * sizeof(void))))
		{
			free(new_lst);
			new_lst = 0;
			return (0);
		}
		ft_memcpy(new_lst->content, (void*)content, content_size);
		new_lst->content_size = content_size;
	}
	new_lst->next = 0;
	return (new_lst);
}
