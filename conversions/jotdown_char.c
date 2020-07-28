/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jotdown_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssacrist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 16:21:25 by ssacrist          #+#    #+#             */
/*   Updated: 2020/07/23 16:21:45 by ssacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	jotdown_c(t_format *carrier)
{
	int		arg;

	flag(carrier->flagstr, 0, carrier);
	if (carrier->minus == 0 && carrier->width > 0)
		writespaces(carrier->width - 1, carrier);
	arg = va_arg(carrier->arguments, int);
	ft_putchar(arg, carrier);
	if (carrier->minus == 1 && carrier->width > 0)
		writespaces(carrier->width - 1, carrier);
}
