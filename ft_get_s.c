#include "ft_printf.h"

char	*ft_get_s(char *str1, t_var *tmp, va_list str)
{
//	char *res;

//	res = ft_strdup(va_arg(str, char*));
	str1 = va_arg(str, char*);
	return (str1);
}
