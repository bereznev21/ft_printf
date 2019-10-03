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


//	printf("%5");
//	ft_printf("%5");

	printf("%+05.0f\n", 7.3);
	ft_printf("%+05.0f", 7.3);

	return (0);
}
