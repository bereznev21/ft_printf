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
	ft_putchar('!');
	ft_putchar(mas[i]);
	ft_putchar(tmp->size1);
	ft_putchar(tmp->size2);
	ft_putchar('!');
*/


	//printf("|%010.0o|\n", 2147483648);
	//ft_printf("|%010.0o|\n", 2147483648);

	//printf("|%01.0ho|\n", 2147483648);
	//ft_printf("|%01.0ho|\n", 2147483648);

	int *a;
	*a = 10;

	printf("%f\n", 10.12);
	ft_printf("%f\n", 10.12);

	printf("|%Lf|\n", 42.5);
	ft_printf("|%Lf|\n", 42.5);

	printf("|%Lf|\n", 42.5);
	ft_printf("|%Lf|\n", 42.5);

//============================================

/*
	printf("%%\n");
	ft_printf("%%\n");

	printf("aa%%bb\n");
	ft_printf("aa%%bb\n");

	printf("%%%%%%%%%%\n");
	ft_printf("%%%%%%%%%%\n");

	printf(".%%.%%.%%.%%.%%.%%.%%.%%.\n");
	ft_printf(".%%.%%.%%.%%.%%.%%.%%.%%.\n");

	printf("%.0p, %.p\n", (void*)0, (void*)0);
	ft_printf("%.0p, %.p\n", (void*)0, (void*)0);

	printf("%.0x, %.x\n", 0, 0);
	ft_printf("%.0x, %.x\n", 0, 0);

	ft_printf("%c\n", 'a');
	ft_printf("hello, %s.", "gavin");
	ft_printf("this %x number", 0);
	ft_printf("%x\n", 10);

	ft_printf("%x\n", 1000);
	ft_printf("%7x", 33);
	ft_printf("%32s", "abc");
	ft_printf("%32.12d", 12340);
	ft_printf("%-12d\n", 12340);

	ft_printf("%2d", 3);
	ft_printf("12  |%-10d|\n", 3);
	ft_printf("15  |%10d|\n", 1);

	ft_printf("13  |% d|\n", 3);
	ft_printf("14  |%+d|\n", 3);
	ft_printf("15  |%010d|\n", 1);

  ft_printf("%-10d\n", 3);
  ft_printf("% d\n", 3);
  ft_printf("%+d\n", 3);
  ft_printf("%010d\n", 1);
*/
	return (0);
}
 