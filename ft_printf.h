/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 22:47:02 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/01 23:23:58 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <float.h>
# include <stdint.h>

typedef struct		var
{
	int				width;
	int				precision;
	int				precision_flag;
	int				arg_sign;
	char			type;
	char			flag;
	char			flag_1;
	char			flag2;
	char			size1;
	char			size2;
	char*			data;
}					var;

typedef struct		float_struct
{
	long double		num;
	long double		mantisa;
	long			sign;
	int				mantisa_len;
	int				zero_len;
	int				base;
	int				power;
	char			*res;
}					float_struct;

int					ft_printf(const char *format, ...);
char				*ft_print_c(var *s);
char				*ft_print_s(var *s);
char				*ft_print_p(var *s);
char				*ft_print_pc(var *s);
char				*ft_llitoa(long long int n, var *tmp);
char				*ft_ullitoa(uintmax_t nb, var *tmp);
char				*ft_print_d(var *s);
void				ft_if_ngtv_rgsgn_prcsn_0(var *tmp);
void				ft_if_ngtv_rgsgn_prcsn_1(var *tmp);
void				ft_if_pstv_rgsgn_prcsn_0(var *tmp);
void				ft_if_pstv_rgsgn_prcsn_1(var *tmp);
void				ft_if_pstv_rgsgn(var *tmp);
char				*ft_print_o(var *s);
char				*ft_print_u(var *s);
char				*ft_print_x(var *s);
char				*ft_print_f(var *s);
char				*ft_print_pc(var *s);
int					ft_controller(var *tmp);
int					ft_create_list_var(const char *mas, int i, va_list str);
char				*ft_create_arg_string(char *str1, var *tmp, va_list str);
int					ft_check_type(char type);
char				*ft_strjoin_char(char *str, char end);
char				*ft_strjoin_left(const char *s1, char *s2);
char				*ft_strjoin_right(char *s1, const char *s2);
char				*ft_start_double(long double n, var *var_struct);
char				*ft_fil_whitespaces(var *s, int wdth, int len);
char				*ft_end_whitespaces(var *s, int wdth, int len);
char				*ft_crop_str(char *str, int len, int crop);
var					*ft_ntlstn_var(var *tmp);
int					ft_ifprecent(const char *format, va_list str, int *i);
int					ft_ifnopercent(const char *format, int *i);
var					*ft_ifseedot(var *tmp, int *i, const char *mas);
var					*ft_srchflgs(var *tmp, int *i, const char *mas);
char				*ft_convert108(intmax_t nmb);
char				*ft_create_xi(char *s, unsigned int n, int sz);
char				*ft_get_d(char *str1, var *tmp, va_list str);
char				*ft_get_f(char *str1, var *tmp, va_list str);
char				*ft_get_c(char *str1, var *tmp, va_list str);
char				*ft_get_u(char *str1, var *tmp, va_list str);
char				*ft_get_x(char *str1, var *tmp, va_list str);
char				*ft_get_o(char *str1, var *tmp, va_list str);
char				*ft_get_p(char *str1, var *tmp, va_list str);
char				*ft_itoa_base(intmax_t value, int base, var *tmp);
char				*ft_uitoa_base(uintmax_t value, int base, char type);
int					ft_create_list_var(const char *mas, int i, va_list str);

#endif
