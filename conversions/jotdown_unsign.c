/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jotdown_unsign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssacrist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 17:48:37 by ssacrist          #+#    #+#             */
/*   Updated: 2020/07/23 17:49:22 by ssacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	jotdown_u(t_format *carrier)
{
	unsigned int		arg;

	flag(carrier->flagstr, 0, carrier);
	adjust_flags(carrier);
	arg = va_arg(carrier->arguments, unsigned int);
	carrier->large_arg = ft_strlen(ft_itoa_u(arg));
	print_u(arg, carrier);
}

void	print_u(unsigned int arg, t_format *carrier)
{
	if (carrier->precision == 0 && arg == 0)
		writespaces(carrier->width, carrier);
	else if (carrier->minus == 1)
		if_minus_u(arg, carrier);
	else
		if_nominus_noneg_u(arg, carrier);
}
