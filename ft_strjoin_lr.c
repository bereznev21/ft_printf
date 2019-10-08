/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_lr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 06:21:19 by tlynesse          #+#    #+#             */
/*   Updated: 2019/10/08 20:51:50 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_free_str(char **s)
{
	if (*s)
		free((void *)*s);
	return (0);
}

char	*ft_strjoin_left(const char *s1, char *s2)
{
	char	*res;
	size_t	i;
	int		l1;
	int		l2;

	if (!s1)
		return (s2);
	else if (!s2)
		return ((char *)s1);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	res = 0;
	if (!(res = (char*)malloc((l1 + l2 + 1) * sizeof(char))))
		return (ft_free_str(&s2));
	i = 0;
	while (++i <= l1)
		res[i - 1] = s1[i - 1];
	i = 0;
	while (++i <= l2)
		res[l1 + i - 1] = s2[i - 1];
	res[l1 + l2] = 0;
	ft_free_str(&s2);
	return (res);
}

char	*ft_strjoin_right(char *s1, const char *s2)
{
	char	*res;
	size_t	i;
	int		l1;
	int		l2;

	if (!s2)
		return (s1);
	else if (!s1)
		return ((char *)s2);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	res = 0;
	if (!(res = (char*)malloc((l1 + l2 + 1) * sizeof(char))))
		return (ft_free_str(&s1));
	i = 0;
	while (++i <= l1)
		res[i - 1] = s1[i - 1];
	i = 0;
	while (++i <= l2)
		res[l1 + i - 1] = s2[i - 1];
	res[l1 + l2] = 0;
	ft_free_str(&s1);
	return (res);
}
