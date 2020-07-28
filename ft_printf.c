/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssacrist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 18:16:14 by ssacrist          #+#    #+#             */
/*   Updated: 2020/07/28 03:04:33 by ssacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	This program emulates the behaviour of the "printf" function, only
**	with formats cspdiuxX% and flags -0.*
**
**	How does it?
**	1) There's only one function to print: ft_putchar (with 'write')
**	2) Uses the 'carrier' structure to save the necessary information a lot of
**		times.
**	3) Works with convers with different states, even by similar ways.
**	4) Any conversion uses a "different" ft_ (function):
**		jotdown_dec, jotdown_char, jotdown_string, jotdown_unsign, etc.
*/

#include "libftprintf.h"

static void	flags_init(t_format *carrier)
{
	carrier->flagstr[0] = *("");
	carrier->largeflag = 0;
	carrier->large_arg = 0;
	carrier->convers = ' ';
	carrier->percent = 0;
	carrier->minus = 0;
	carrier->zero = 0;
	carrier->dot = 0;
	carrier->pos_dot = 0;
	carrier->asterisk = 0;
	carrier->pos_asterisk = 0;
	carrier->width = 0;
	carrier->precision = -1;
	carrier->code_zmpw = 0;
	carrier->arg_null = ' ';
}

static void	carrier_init(t_format *carrier)
{
	carrier->where = 0;
	carrier->how_many = 0;
	flags_init(carrier);
}

/*
**	This ft_ have a double function:
**		1) Return the type of conversion: d,s,c,x...
**		2) Save the string-flag in t_format carrier->flagstr
**
**	The program always check the flags in this new string: it never
**	checks on the original string.
*/

static char	ft_look4format(const char *str, t_format *carrier)
{
	int		i;
	int		j;

	while (*str)
	{
		j = 0;
		carrier->where++;
		carrier->largeflag++;
		i = carrier->largeflag;
		while (j <= 8)
		{
			if (str[i] != PRINTF_VALID_FORMATS[j])
				if (j++ == 8)
					carrier->flagstr[i - 1] = str[i];
			if (str[i] == PRINTF_VALID_FORMATS[j])
			{
				carrier->flagstr[i - 1] = '\0';
				return (str[i]);
			}
		}
	}
	return (str[i]);
}

static void	is_percent(const char **str, t_format *carrier)
{
	flags_init(carrier);
	carrier->convers = ft_look4format(*str, carrier);
	if (carrier->convers == 'c')
		jotdown_c(carrier);
	else if (carrier->convers == 's')
		jotdown_s(carrier);
	else if (carrier->convers == 'p')
		jotdown_p(carrier);
	else if (carrier->convers == 'd')
		jotdown_d(carrier);
	else if (carrier->convers == 'u')
		jotdown_u(carrier);
	else if (carrier->convers == 'i')
		jotdown_d(carrier);
	else if (carrier->convers == 'x' || carrier->convers == 'X')
		jotdown_x(carrier);
	else if (carrier->convers == '%')
		jotdown_pct(carrier);
	*str = *str + carrier->largeflag;
}

int			ft_printf(const char *str, ...)
{
	t_format	carrier;

	if (!str || !*str)
		return (0);
	va_start(carrier.arguments, str);
	carrier_init(&carrier);
	while (*str != '\0')
	{
		carrier.where++;
		if (*str == '%')
			is_percent(&str, &carrier);
		else
			ft_putchar(*str, &carrier);
		str++;
	}
	va_end(carrier.arguments);
	return (carrier.how_many);
}
