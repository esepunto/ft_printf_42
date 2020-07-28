/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_intmin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssacrist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 17:24:56 by ssacrist          #+#    #+#             */
/*   Updated: 2020/07/27 17:28:37 by ssacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libftprintf.h"

void	print_int_min_pos(int arg, t_format *carrier)
{
	if (arg != -2147483648)
		ft_putnbr(arg, carrier);
	else
	{
		write(1, "2147483648", 10);
		carrier->how_many = carrier->how_many + 10;
	}
}

void	print_int_min_neg(int arg, t_format *carrier)
{
	if (arg != -2147483648)
		ft_putnbr(arg, carrier);
	else
	{
		write(1, "-2147483648", 11);
		carrier->how_many = carrier->how_many + 11;
	}
}
