/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jotdown_hexadec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssacrist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 17:05:20 by ssacrist          #+#    #+#             */
/*   Updated: 2020/07/23 17:09:22 by ssacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	jotdown_x(t_format *carrier)
{
	char			*arg;
	unsigned long	aux;

	flag(carrier->flagstr, 0, carrier);
	aux = va_arg(carrier->arguments, unsigned int);
	arg = dec_to_hexa(aux, carrier);
	carrier->large_arg = ft_strlen(arg);
	adjust_flags(carrier);
	print_x(arg, carrier);
}

void	print_x(char *arg, t_format *carrier)
{
	if (carrier->precision == 0 && arg[0] == '0' && arg[1] == '\0')
		writespaces(carrier->width, carrier);
	else if (carrier->minus == 1)
		if_minus_x(arg, carrier);
	else
		if_nominus_noneg_x(arg, carrier);
}
