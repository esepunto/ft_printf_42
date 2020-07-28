/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jotdown_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssacrist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 17:39:00 by ssacrist          #+#    #+#             */
/*   Updated: 2020/07/28 01:51:38 by ssacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	jotdown_pct(t_format *carrier)
{
	char	*arg;
	int		c;

	flag(carrier->flagstr, 0, carrier);
	arg = "%";
	carrier->large_arg = ft_strlen(arg);
	if (carrier->zero == 1 && carrier->minus == 0)
	{
		c = carrier->width - carrier->large_arg;
		writezeros(c, carrier);
	}
	else if (carrier->minus == 0)
		if (carrier->large_arg < carrier->width
					|| carrier->precision < carrier->width)
			writespaces_s(carrier);
	ft_putstr(arg, carrier);
	if (carrier->minus == 1)
		if (carrier->large_arg < carrier->width
					|| carrier->precision < carrier->width)
			writespaces_s(carrier);
}
