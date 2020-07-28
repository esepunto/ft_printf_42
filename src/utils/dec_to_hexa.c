/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_to_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssacrist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 19:55:35 by ssacrist          #+#    #+#             */
/*   Updated: 2020/07/28 01:44:58 by ssacrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libftprintf.h"

static char	*invert_str(char *str)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i <= j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
	return (str);
}

char		*dec_to_hexa(unsigned long arg, t_format *carrier)
{
	static char		result[20];
	int				i;
	unsigned long	temp;

	i = 0;
	if (arg == 0)
		return ("0\0");
	while (arg != 0)
	{
		temp = arg % 16;
		if (carrier->convers == 'x')
			result[i] = HEXALOWER[temp];
		else if (carrier->convers == 'X')
			result[i] = HEXAUPPER[temp];
		i++;
		arg = arg / 16;
	}
	result[i] = '\0';
	return (invert_str(result));
}

char		*dec_to_hexa_p(long unsigned int arg)
{
	static char		result[25];
	int				i;
	int				temp;

	i = 0;
	if (arg == 0)
		return ("\0");
	while (arg != 0)
	{
		temp = arg % 16;
		result[i] = HEXALOWER[temp];
		i++;
		arg = arg / 16;
	}
	result[i] = '\0';
	return (invert_str(result));
}
