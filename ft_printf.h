/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 22:47:02 by rpoetess          #+#    #+#             */
/*   Updated: 2019/10/03 20:23:57 by rpoetess         ###   ########.fr       */
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

typedef struct		s_flags
{
	int				minus;
	int				plus;
	int				space;
	int				zero;
	int				grab;
}					t_flags;

typedef struct		s_var
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
	char			*data;
}					t_var;

typedef struct		s_float_struct
{
	long double		num;
	long double		mantisa;
	long			sign;
	int				mantisa_len;
	int				zero_len;
	int				base;
	int				power;
	char			*res;
}					t_float_struct;

int					ft_printf(const char *format, ...);
char				*ft_print_c(t_var *s);
char				*ft_print_s(t_var *s);
char				*ft_print_p(t_var *s);
char				*ft_print_pc(t_var *s);
char				*ft_llitoa(long long int n, t_var *tmp);
char				*ft_ullitoa(uintmax_t nb, t_var *tmp);
char				*ft_print_d(t_var *s);
void				ft_if_ngtv_rgsgn_prcsn_0(t_var *tmp);
void				ft_if_ngtv_rgsgn_prcsn_1(t_var *tmp);
void				ft_if_pstv_rgsgn_prcsn_0(t_var *tmp);
void				ft_if_pstv_rgsgn_prcsn_1(t_var *tmp);
void				ft_if_pstv_rgsgn(t_var *tmp);
char				*ft_print_o(t_var *s);
char				*ft_print_u(t_var *s);
char				*ft_print_x(t_var *s);
char				*ft_print_f(t_var *s);
char				*ft_print_pc(t_var *s);
int					ft_controller(t_var *tmp);
int					ft_create_list_var(const char *mas, int i, va_list str);
char				*ft_create_arg_string(char *str1, t_var *tmp, va_list str);
int					ft_check_type(char type);
char				*ft_strjoin_char(char *str, char end);
char				*ft_strjoin_left(const char *s1, char *s2);
char				*ft_strjoin_right(char *s1, const char *s2);
char				*ft_start_double(long double n, t_var *var_struct);
char				*ft_fil_whitespaces(t_var *s, int wdth, int len);
char				*ft_end_whitespaces(t_var *s, int wdth, int len);
char				*ft_crop_str(char *str, int len, int crop);
t_var				*ft_ntlstn_var(t_var *tmp);
int					ft_ifprecent(const char *format, va_list str, int *i);
int					ft_ifnopercent(const char *format, int *i);
void				ft_crtflgs(int *i, t_var *tmp, const char *mas);
t_var				*ft_ifseedot(t_var *tmp, int *i, const char *mas);
t_var				*ft_srchflgs(t_var *tmp, int *i, const char *mas);
char				*ft_convert108(intmax_t nmb);
char				*ft_create_xi(char *s, unsigned int n, int sz);
char				*ft_get_d(char *str1, t_var *tmp, va_list str);
char				*ft_get_f(char *str1, t_var *tmp, va_list str);
char				*ft_get_c(char *str1, t_var *tmp, va_list str);
char				*ft_get_u(char *str1, t_var *tmp, va_list str);
char				*ft_get_x(char *str1, t_var *tmp, va_list str);
char				*ft_get_o(char *str1, t_var *tmp, va_list str);
char				*ft_get_p(char *str1, t_var *tmp, va_list str);
char				*ft_itoa_base(intmax_t value, int base, t_var *tmp);
char				*ft_uitoa_base(uintmax_t value, int base, char type);
int					ft_create_list_var(const char *mas, int i, va_list str);

#endif
