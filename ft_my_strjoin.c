#include <stdlib.h>
#include <unistd.h>

char	*ft_strdup(const char *src)
{
	char	*res;
	size_t	len;
	size_t	i;

	len = 0;
	while (src[len])
		len++;
	res = (char*)malloc(len + 1);
	if (!res)
		return (0);
	i = 0;
	while (src[i])
	{
		res[i] = (char)src[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

void	ft_putstr(char const *s)
{
	if (s)
		while (*s)
			write(1, s++, 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	res;

	res = 0;
	if (s)
		while (s[res])
			res++;
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*arr;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	arr = (char *)malloc(sizeof(arr) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (arr)
	{
		while (s1[i])
		{
			arr[i] = s1[i];
			i++;
		}
		while (s2[j])
		{
			arr[i + j] = s2[j];
			j++;
		}
		arr[i + j] = '\0';
		return (arr);
	}
	//free (arr);
	return (NULL);
}

int		main()
{
	char	*s1;
	char	*s2;
	char	*res;

//	s1 = ft_strdup("1234");
	s2 = ft_strdup("5678");
	res = ft_strjoin(" ", s2);
	free(s2);
	ft_putstr(res);
	free(res);
}