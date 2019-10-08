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

	//printf("|%010.0o|\n", 2147483648);
	//ft_printf("|%010.0o|\n", 2147483648);

	//printf("|%01.0ho|\n", 2147483648);
	//ft_printf("|%01.0ho|\n", 2147483648);

	int *a;
	*a = 10;

	//printf("%%\n");
	//ft_printf("%%\n");
	
//	printf("%c\n", 'a');
//	ft_printf("%c\n", 'a');
	
/*	printf("%s\n", "Hellow World!");
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
*/
//============================================


	//printf("|%Lf|\n", 42.5);
	//ft_printf("|%Lf|\n", 42.5);

	//printf("|%Lf|\n", 42.5);
	//ft_printf("|%Lf|\n", 42.5);

/*
	printf("%%\n");
	ft_printf("%%\n");

	printf("aa%%bb\n");
	ft_printf("aa%%bb\n");

	printf("%%%%%%%%%%\n");
	ft_printf("%%%%%%%%%%\n");

	printf(".%%.%%.%%.%%.%%.%%.%%.%%.\n");
	ft_printf(".%%.%%.%%.%%.%%.%%.%%.%%.\n");
*/
/*	printf("%.0p, %.p\n", (void*)0, (void*)0);
	ft_printf("%.0p, %.p\n", (void*)0, (void*)0);

	printf("%.0x, %.x\n", 0, 0);
	ft_printf("%.0x, %.x\n", 0, 0);
*/
	//ft_printf("%c\n", 'a');
	//ft_printf("hello, %s.", "gavin");
	//ft_printf("this %x number", 0);
	//ft_printf("%x\n", 10);

	//ft_printf("%x\n", 1000);
	//ft_printf("%7x", 33);
	//ft_printf("%32s", "abc");
	//ft_printf("%d", 0);


/*
	ft_printf("1   ||\n");
	ft_printf("2   |%%|\n");
	ft_printf("3   |%d|\n", 42);
	ft_printf("4   |%d%d|\n", 42, 41);
	ft_printf("5   |%d%d%d|\n", 42, 43, 44);
	ft_printf("6   |%ld|\n", 2147483647);
	ft_printf("7   |%lld|\n", 9223372036854775807);
	ft_printf("8   |%x|\n", 505);
	ft_printf("9   |%X|\n", 505);
	ft_printf("10  |%p|\n", &ft_printf);
	ft_printf("11  |%20.15d|\n", 54321);
	ft_printf("12  |%-10d|\n", 3);
	ft_printf("13  |% d|\n", 3);
	ft_printf("14  |%+d|\n", 3);
	ft_printf("15  |%010d|\n", 1);
	ft_printf("16  |%hhd|\n", 0);
	ft_printf("17  |%jd|\n", 9223372036854775807);
	ft_printf("18  |%zd|\n", 4294967295);
	ft_printf("19  |%|\n");
	ft_printf("20  |%U|\n", 4294967295);
	ft_printf("21  |%u|\n", 4294967295);
	ft_printf("22  |%o|\n", 40);
	ft_printf("23  |%%#08x|\n", 42);
	ft_printf("24  |%x|\n", 1000);
	ft_printf("25  |%#X|\n", 1000);
	ft_printf("26  |%s|\n", NULL);
	ft_printf("27  |%S|\n", L"ݗݜशব");
	ft_printf("28  |%s%s|\n", "test", "test");
	ft_printf("29  |%s%s%s|\n", "test", "test", "test");
	ft_printf("30  |%C|\n", 15000);
	*/
	//printf("%-5c\n", 0);
	ft_printf("%-5c", 0);

	return (0);
}
 