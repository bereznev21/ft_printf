#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{

/*	
	ft_putchar('|');
	ft_putchar(tmp->flag);
	ft_putchar(tmp->flag_1);
	ft_putchar(tmp->flag2);
	ft_putchar('|');
*/

/*	
	ft_putchar('|');
	ft_putnbr(tmp->width);
	ft_putnbr(tmp->precision);
	ft_putnbr(tmp->precision_flag);
	ft_putnbr((int)ft_strlen(tmp->data));
	ft_putchar('|');
*/


/*
	%.0hd
	%.hd
	%18.0hd
	1.0hd
	%01.0hd
	010.20hd
	%018.0hd
	18.0ld
	%010.0lld
	%+1llx
*/
	printf("|%010.0o|\n", 2147483648);
	ft_printf("|%010.0o|\n", 2147483648);

	printf("|%01.0ho|\n", 2147483648);
	ft_printf("|%01.0ho|\n", 2147483648);

	int *a;
	*a = 10;

	printf("%%\n");
	ft_printf("%%\n");
	
	printf("%c\n", 'a');
	ft_printf("%c\n", 'a');
	
	printf("%s\n", "Hellow World!");
	ft_printf("%s\n", "Hellow World!");
	
	printf("%p\n", a);
	ft_printf("%p\n", a);
	
	printf("%d\n", 10);
	ft_printf("%d\n", 10);
	
	printf("%o\n", 10);
	ft_printf("%o\n", 10);
	
	printf("%u\n", 10);
	ft_printf("%u\n", 10);
	
	printf("%x\n", 10);
	ft_printf("%x\n", 10);
	
	printf("%X\n", 10);
	ft_printf("%X\n", 10);
	
	printf("%f\n", 10.1);
	ft_printf("%f\n", 10.1);
	
//============================================

	printf("|%018.0ho|\n", 2147483648);
	ft_printf("|%018.0ho|\n", 2147483648);

	return (0);
}
