/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jotdown_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssacrist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 17:42:07 by ssacrist          #+#    #+#             */
/*   Updated: 2020/07/28 02:25:25 by ssacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	jotdown_p(t_format *carrier)
{
	char				*arg;
	long unsigned int	aux;

	flag(carrier->flagstr, 0, carrier);
	aux = va_arg(carrier->arguments, long unsigned int);
	if (aux == (long unsigned int)NULL)
	{
		arg = "0\0";
		carrier->arg_null = 'y';
	}
	else
		arg = dec_to_hexa_p(aux);
	carrier->large_arg = ft_strlen(arg);
	code_zmpw_p(carrier);
	choose_code_to_print_p(arg, carrier);
}
