/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 22:07:33 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/01 21:47:03 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"

extern int	g_zero;
extern int	g_align_left;
extern int	g_width;
extern int	g_pre;
extern int	g_len;

int			ft_printf(const char *str, ...);
char		find_type(const char *str, int *len);
int			initial(int l);
int			find_per(va_list ap, int *len, const char **str);
int			ft_isdigit_div0(int c);
int			ft_strchr_int(char *str, int c);
char		*ft_utoa(unsigned int n);
int			count_16(unsigned long long x);
void		set_format(const char **str, int per_idx, int type_idx, va_list ap);
void		check_asterisk(char *str, int *i, va_list ap);
int			arg_by_type(va_list ap, char type);
void		is_digit(char *temp, int *i);
int			d_print(va_list ap);
char		*align_d(char *str);
char		*align_right_d(char *str);
char		*precision_apply_d(char *str_d);
char		*free_str(char *zero_str, char *str_d, char *pre_apply_str);
int			u_print(va_list ap);
char		*free_ano(char *str);
int			c_print(va_list ap, int per);
void		apply_g_len(void);
char		is_per(va_list ap, int per);
int			s_print(va_list ap);
void		align_s(char *str_s);
int			x_print(va_list ap, int x);
char		*big_x_print(char *str_x, int x);
char		*to_16(unsigned int x);
char		*zero_x(void);
int			x_print_sub(char *str_x, int x);
int			p_print(va_list ap);
char		*add_0x(char *str_p);
char		*to_16_llu(unsigned long long x);
#endif
