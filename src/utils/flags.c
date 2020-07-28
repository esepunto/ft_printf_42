/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssacrist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 19:42:36 by ssacrist          #+#    #+#             */
/*   Updated: 2020/07/28 02:21:49 by ssacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libftprintf.h"

static int	flagdot(int c, t_format *carrier)
{
	char *flag;

	flag = carrier->flagstr;
	carrier->dot = 1;
	carrier->pos_dot = c;
	c++;
	carrier->precision = 0;
	if (flag[c] == '-')
		carrier->precision = -1;
	if (flag[c] == '*')
		carrier->precision = va_arg(carrier->arguments, int);
	else if (ft_isdigit(flag[c]))
	{
		while (ft_isdigit(flag[c]))
			carrier->precision = (carrier->precision * 10) + (flag[c++] - 48);
	}
	c--;
	return (c);
}

void		flag(char *flag, int c, t_format *carrier)
{
	while (flag[c])
	{
		if (flag[c] == '-')
			carrier->minus = 1;
		else if (flag[c] == '0')
			carrier->zero = 1;
		else if (flag[c] == '.')
			c = flagdot(c, carrier);
		else if (flag[c] == '*' && carrier->dot == 0)
		{
			carrier->width = va_arg(carrier->arguments, int);
			if (carrier->width < 0)
			{
				carrier->width = carrier->width * -1;
				carrier->minus = 1;
			}
		}
		else if (ft_isdigit(flag[c]) && carrier->dot == 0)
		{
			while (ft_isdigit(flag[c]))
				carrier->width = (carrier->width * 10) + (flag[c++] - 48);
			c--;
		}
		c++;
	}
}

void		adjust_flags(t_format *carrier)
{
	if (carrier->zero == 1 && carrier->minus == 1)
		carrier->zero = 0;
	if (carrier->zero == 1 && carrier->precision > 0)
		carrier->zero = 0;
}

void		adjust_flags_s(t_format *carrier)
{
	if (carrier->zero == 1 && carrier->minus == 1)
		carrier->zero = 0;
}
