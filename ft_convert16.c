#include "ft_printf.h"

void	ft_xsi(var *s, unsigned long long int num, int w)
{
	unsigned short int	remainder;
	unsigned short int	localnum;

	localnum = (unsigned short int)num;
	if (localnum == 0)
		s->data[--w] = '0' + localnum;
	while (localnum != 0)
	{
		remainder = localnum % 16;
		if (remainder < 10)
			s->data[--w] = '0' + remainder;
		else if (s->type == 'x')
			s->data[--w] = 'a' - 10 + remainder;
		else if (s->type == 'X')
			s->data[--w] = 'A' - 10 + remainder;
		localnum = localnum / 16;
	}
}

void	ft_xc(var *s, unsigned long long int num, int w)
{
	unsigned char	remainder;
	unsigned char	localnum;

	localnum = (unsigned char)num;
	if (localnum == 0)
		s->data[--w] = '0' + localnum;
	while (localnum != 0)
	{
		remainder = localnum % 16;
		if (remainder < 10)
			s->data[--w] = '0' + remainder;
		else if (s->type == 'x')
			s->data[--w] = 'a' - 10 + remainder;
		else if (s->type == 'X')
			s->data[--w] = 'A' - 10 + remainder;
		localnum = localnum / 16;
	}
}

void	ft_xlli(var *s, unsigned long long int num, int w)
{
	unsigned long long int	remainder;
	unsigned long long int	localnum;

	localnum = (unsigned long long int)num;
	if (localnum == 0)
		s->data[--w] = '0' + localnum;
	while (localnum != 0)
	{
		remainder = localnum % 16;
		if (remainder < 10)
			s->data[--w] = '0' + remainder;
		else if (s->type == 'x')
			s->data[--w] = 'a' - 10 + remainder;
		else if (s->type == 'X')
			s->data[--w] = 'A' - 10 + remainder;
		localnum = localnum / 16;
	}
}
