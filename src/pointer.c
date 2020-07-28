/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssacrist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 19:35:05 by ssacrist          #+#    #+#             */
/*   Updated: 2020/07/28 02:30:45 by ssacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

/*
** 	The code zmpw identify Zero, Minus, Precision and Width in the flag
**
** 	If the flag have Zero, the first digit = 1, else = 0
** 	If have Minus, second digit = 1, else = 0
** 	3th = 1 if have Precision, else = 0
** 	4th = 1 if have Width, else = 0
**	(Not all the combinations are posible)
**
** 	Examples:
** 		If zmpw == 1011 => Zero + Precision + Width
** 		If zmpw == 0110 => Minus + Precision
**
** 				***The print depends by the code zmpw***
*/

static void	zmpw_1_p(char *arg, t_format *carrier)
{
	int	c;

	c = carrier->width - carrier->large_arg;
	writespaces(c, carrier);
	ft_puthex("0x", carrier);
	ft_puthex(arg, carrier);
}

static void	zmpw_10_p(char *arg, t_format *carrier)
{
	int	c;

	ft_puthex("0x", carrier);
	c = carrier->precision - carrier->large_arg + 2;
	if (carrier->precision > carrier->large_arg)
		writezeros(c, carrier);
	if (!(carrier->precision == 0 && carrier->dot == 1
					&& carrier->arg_null != ' '))
		ft_puthex(arg, carrier);
}

static void	zmpw_101_p(char *arg, t_format *carrier)
{
	int	c;

	ft_puthex("0x", carrier);
	ft_puthex(arg, carrier);
	c = carrier->width - carrier->large_arg;
	if (carrier->width > carrier->large_arg)
		writespaces(c, carrier);
}

void		choose_code_to_print_p(char *arg, t_format *carrier)
{
	int		zmpw;

	zmpw = carrier->code_zmpw;
	carrier->large_arg = carrier->large_arg + 2;
	if (zmpw == 0 || zmpw == 100 || zmpw == 1000)
	{
		ft_puthex("0x", carrier);
		ft_puthex(arg, carrier);
	}
	else if (zmpw == 1)
		zmpw_1_p(arg, carrier);
	else if (zmpw == 10 || zmpw == 110 || zmpw == 1010)
		zmpw_10_p(arg, carrier);
	else if (zmpw == 11 || zmpw == 1011)
		zmpw_11_p(arg, carrier);
	else if (zmpw == 101)
		zmpw_101_p(arg, carrier);
	else if (zmpw == 110)
		zmpw_110_p(arg, carrier);
	else if (zmpw == 111)
		zmpw_111_p(arg, carrier);
	else if (zmpw == 1001)
		zmpw_1001_p(arg, carrier);
}

void		code_zmpw_p(t_format *carrier)
{
	if (carrier->zero == 1 && carrier->minus == 1)
		carrier->zero = 0;
	if (carrier->zero > 0)
		carrier->code_zmpw = 1000;
	if (carrier->minus > 0)
		carrier->code_zmpw = 100;
	if (carrier->precision > 0 || carrier->dot == 1)
		carrier->code_zmpw = carrier->code_zmpw + 10;
	if (carrier->width > 0)
		carrier->code_zmpw = carrier->code_zmpw + 1;
}
