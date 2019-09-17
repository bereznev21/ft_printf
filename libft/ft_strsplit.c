/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlynesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:28:48 by tlynesse          #+#    #+#             */
/*   Updated: 2018/12/09 16:54:40 by tlynesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	cnt;

	cnt = 1;
	while ((char)*s == c)
		s++;
	while (*s)
	{
		while (*s && (char)*s != c)
			s++;
		cnt++;
		while ((char)*s == c)
			s++;
	}
	return (cnt);
}

static size_t	ft_word_len_plus(char const **s, char c)
{
	size_t	len_plus;

	while ((char)**s == c)
		(*s)++;
	len_plus = 0;
	while ((*s)[len_plus] && (char)((*s)[len_plus]) != c)
		len_plus++;
	return (len_plus + 1);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	count_buf;
	size_t	i;
	size_t	length_buf;
	size_t	j;
	char	**res;

	if (!s || !c)
		return (0);
	count_buf = ft_count_words(s, c);
	if (!(res = (char**)malloc(count_buf * sizeof(char*))) || !count_buf)
		return (0);
	i = 0;
	while (i < count_buf - 1)
	{
		length_buf = ft_word_len_plus(&s, c);
		if (!(res[i] = (char*)malloc(length_buf * sizeof(char))))
			return (ft_free_matrix_mem(&res));
		j = 0;
		while (j < length_buf - 1)
			res[i][j++] = *(s++);
		res[i++][j] = 0;
	}
	res[i] = 0;
	return (res);
}
