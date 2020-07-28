/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssacrist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 18:25:59 by ssacrist          #+#    #+#             */
/*   Updated: 2020/07/28 02:59:49 by ssacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

# define PRINTF_VALID_FORMATS	"cspdiuxX\%"
# define PRINTF_VALID_FLAGS		" -.*0123456789"
# define HEXALOWER	"0123456789abcdef"
# define HEXAUPPER	"0123456789ABCDEF"

typedef struct	s_format
{
	char	convers;
	int		percent;
	int		minus;
	int		zero;
	int		dot;
	int		pos_dot;
	int		asterisk;
	int		pos_asterisk;
	int		width;
	int		precision;
	va_list	arguments;
	int		large_arg;
	char	arg_null;
	int		code_zmpw;
	int		where;
	int		how_many;
	int		largeflag;
	char	flagstr[1276];
}				t_format;

int				ft_printf(const char *str, ...);

void			jotdown_c(t_format *carrier);

void			jotdown_s(t_format *carrier);
void			flag_s(char *flag, int c, t_format *carrier);
void			adjust_flags_s(t_format *carrier);
void			print_s(char *arg, t_format *carrier);
void			writespaces_s(t_format *carrier);
void			asterisks_s(t_format *carrier);
void			if_writezeros_s(t_format *carrier);
void			if_writespaces_s(t_format *carrier);
void			adjust_prec_width(t_format *carrier);

void			jotdown_d(t_format *carrier);
void			flag(char *flag, int c, t_format *carrier);
void			adjust_flags(t_format *carrier);
void			print_d(int arg, t_format *carrier);
void			writespaces(int c, t_format *carrier);
void			writezeros(int c, t_format *carrier);
void			print_int_min_pos(int arg, t_format *carrier);
void			print_int_min_neg(int arg, t_format *carrier);
void			aux_print_spaces(int arg, t_format *carrier);
void			if_minus_d(int arg, t_format *carrier);
void			if_nominus_noneg_d(int arg, t_format *carrier);
void			if_neg_d(int arg, t_format *carrier);

void			jotdown_p(t_format *carrier);
void			asterisks_p(t_format *carrier);
char			*dec_to_hexa_p(long unsigned int arg);
void			code_zmpw_p(t_format *carrier);
void			choose_code_to_print_p(char *arg, t_format *carrier);
void			zmpw_11_p(char *arg, t_format *carrier);
void			zmpw_110_p(char *arg, t_format *carrier);
void			zmpw_111_p(char *arg, t_format *carrier);
void			zmpw_1001_p(char *arg, t_format *carrier);

void			jotdown_i(t_format *carrier);

void			jotdown_u(t_format *carrier);
void			print_u(unsigned int arg, t_format *carrier);
void			aux_print_spaces_u(unsigned int arg, t_format *carrier);
void			if_nominus_noneg_u(unsigned int arg, t_format *carrier);
void			if_minus_u(unsigned int arg, t_format *carrier);

void			jotdown_x(t_format *carrier);
char			*dec_to_hexa(unsigned long arg, t_format *carrier);
void			print_x(char *arg, t_format *carrier);
void			aux_print_spaces_x(char *arg, t_format *carrier);
void			if_minus_x(char *arg, t_format *carrier);
void			if_nominus_noneg_x(char *arg, t_format *carrier);

void			jotdown_pct(t_format *carrier);

size_t			ft_strlen(const char *str);
int				ft_isdigit(int c);
char			*ft_itoa(int n);
char			*ft_itoa_u(unsigned int n);

void			ft_putchar(int c, t_format *carrier);
void			ft_putnbr(int nb, t_format *carrier);
void			ft_putstr(char *str, t_format *carrier);
void			ft_puthex(char *str, t_format *carrier);
void			ft_putnbr_u(unsigned int nb, t_format *carrier);

#endif
