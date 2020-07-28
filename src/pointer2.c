/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssacrist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 19:38:11 by ssacrist          #+#    #+#             */
/*   Updated: 2020/07/28 02:32:07 by ssacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void	zmp_11_p_aux(char *arg, t_format *carrier)
{
	int	c;

	c = 0;
	if (arg[0] == '0' && arg[1] == '\0')
		c = carrier->width - 2;
	else if (carrier->width > carrier->precision
						&& carrier->width >= carrier->large_arg
						&& carrier->large_arg - 2 >= carrier->precision)
		c = carrier->width - carrier->large_arg;
	else if (carrier->precision > 0 && carrier->width >= carrier->precision)
		c = carrier->width - carrier->precision - 2;
	if (c > 0)
		writespaces(c, carrier);
	c = carrier->precision - carrier->large_arg;
	ft_puthex("0x", carrier);
	c = c + 2;
	if (carrier->precision >= carrier->large_arg - 2)
		writezeros(c, carrier);
	if (carrier->precision != 0 || (arg[0] != '0' && arg[1] != '\0'))
		ft_puthex(arg, carrier);
}

void		zmpw_11_p(char *arg, t_format *carrier)
{
	if (carrier->large_arg > carrier->width
						&& carrier->large_arg > carrier->precision)
	{
		ft_puthex("0x", carrier);
		if (carrier->precision != 0 || (arg[0] != '0' && arg[1] != '\0'))
			ft_puthex(arg, carrier);
	}
	else
		zmp_11_p_aux(arg, carrier);
}

void		zmpw_110_p(char *arg, t_format *carrier)
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

void		zmpw_111_p(char *arg, t_format *carrier)
{
	int	c;

	if (arg[0] == '0' && arg[1] == '\0')
		carrier->large_arg = 2;
	c = carrier->precision - carrier->large_arg;
	ft_puthex("0x", carrier);
	if (carrier->precision > carrier->large_arg)
		writezeros(c, carrier);
	if (!(carrier->precision == 0 && carrier->dot == 1
						&& carrier->arg_null != ' '))
		ft_puthex(arg, carrier);
	if (carrier->precision >= carrier->large_arg)
		c = carrier->width - carrier->precision;
	if (carrier->large_arg > carrier->precision)
		c = carrier->width - carrier->large_arg;
	writespaces(c, carrier);
}

void		zmpw_1001_p(char *arg, t_format *carrier)
{
	int	c;

	c = carrier->width - carrier->large_arg;
	ft_puthex("0x", carrier);
	writezeros(c, carrier);
	ft_puthex(arg, carrier);
}
