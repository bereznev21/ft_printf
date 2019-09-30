#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "libft/libft.h"

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <stdint.h>

typedef struct	var
{
	int						width;
	int						precision;
	int						precision_flag;
	int						arg_sign;
	char					type;
	char					flag;
	char					flag_1;
	char					flag2;
	char					size1;
	char					size2;
	char*					data;
} var;

typedef struct	float_struct
{
	long double				num;
	long double				mantisa;
	long					sign;
	int						mantisa_len;
	int						zero_len;
	int						base;
	int						power;
	char					*res;
}	float_struct;

int		ft_printf(const char *format, ...);
char	*ft_print_c(var *s);
char	*ft_print_s(var *s);
char	*ft_print_p(var *s);
char	*ft_print_pc(var *s);
char	*ft_llitoa(long long int n, var *tmp);
char	*ft_ullitoa(uintmax_t nb, var *tmp);
char	*ft_print_d(var *s);
char	*ft_print_o(var *s);
char	*ft_print_u(var *s);
char	*ft_print_x(var *s);
char	*ft_print_f(var *s);
char	*ft_print_pc(var *s);
int		ft_controller(var *tmp);
int		ft_create_list_var(const char *mas, int i, va_list str);
char	*ft_create_arg_string(char *str1, var *tmp, va_list str);
int		ft_check_type(char type);
char	*ft_strjoin_char(char *str, char end);
char	*ft_strjoin_left(const char *s1, char *s2);
char	*ft_strjoin_right(char *s1, const char *s2);
char	*ft_start_double(long double n, var *var_struct);
char	*ft_fil_whitespaces(var *s, int wdth, int len);
char	*ft_end_whitespaces(var *s, int wdth, int len);
char	*ft_crop_str(char *str, int len, int crop);
var		*ft_ntlstn_var(var *tmp);
char	ft_ulli_to_size(unsigned long long int num, char size1, char size2);
int		ft_ifprecent(const char *format, va_list str, int *i);
int		ft_ifnopercent(const char *format, int *i);
var		*ft_ifseedot(var *tmp, int *i, const char *mas);
var		*ft_srchflgs(var *tmp, int *i, const char *mas);
void	ft_i(var *s, int num);
void	ft_si(var *s, short int num);
void	ft_c(var *s, char num);
void	ft_li(var *s, long int num);
void	ft_lli(var *s, long long int num);
void	ft_ui(var *s, unsigned int num);
void	ft_usi(var *s, unsigned short int num);
void	ft_uc(var *s, unsigned char num);
void	ft_uli(var *s, unsigned long int num);
void	ft_ulli(var *s, unsigned long long int num);
void	ft_xui(var *s, unsigned long long int num, int sz);
void	ft_xusi(var *s, unsigned long long int num, int sz);
void	ft_xuc(var *s, unsigned long long int num, int sz);
void	ft_xuli(var *s, unsigned long long int num, int sz);
void	ft_xulli(var *s, unsigned long long int num, int sz);
void	ft_oi(var *s, unsigned int num);
void	ft_osi(var *s, unsigned short int num);
void	ft_oc(var *s, unsigned char num);
void	ft_oli(var *s, unsigned long int num);
void	ft_olli(var *s, unsigned long long int num);
void	ft_create_i(var *s, int n);
void	ft_create_si(var *s, short int n);
void	ft_create_c(var *s, char n);
void	ft_create_li(var *s, long int n);
void	ft_create_lli(var *s, long long int n);
void	ft_create_ui(var *s, unsigned int n);
void	ft_create_usi(var *s, unsigned short int n);
void	ft_create_uc(var *s, unsigned char n);
void	ft_create_uli(var *s, unsigned long int n);
void	ft_create_ulli(var *s, unsigned long long int n);
void	ft_create_xui(var *s, unsigned int n);
void	ft_create_xui(var *s, unsigned int n);
void	ft_create_xusi(var *s, unsigned short int n);
void	ft_create_xuc(var *s, unsigned char n);
void	ft_create_xuli(var *s, unsigned long int n);
void	ft_create_xulli(var *s, unsigned long long int n);
void	ft_create_oi(var *s, unsigned int n);
void	ft_create_osi(var *s, unsigned short int n);
void	ft_create_oc(var *s, unsigned char n);
void	ft_create_oli(var *s, unsigned long int n);
void	ft_create_olli(var *s, unsigned long long int n);
char	*ft_convert108(intmax_t nmb);
char	*ft_create_xi(char *s, unsigned int n, int sz);
char	*ft_get_d(char *str1, var *tmp, va_list str);
char	*ft_get_f(char *str1, var *tmp, va_list str);
char	*ft_get_c(char *str1, var *tmp, va_list str);
char	*ft_get_u(char *str1, var *tmp, va_list str);
char	*ft_get_x(char *str1, var *tmp, va_list str);
char	*ft_get_o(char *str1, var *tmp, va_list str);
void	ft_xsi(var *s, unsigned long long int num, int w);
void	ft_xc(var *s, unsigned long long int num, int w);
void	ft_xlli(var *s, unsigned long long int num, int w);
char	*ft_itoa_base(intmax_t value, int base, char type);
char	*ft_uitoa_base(uintmax_t value, int base, char type);

#endif