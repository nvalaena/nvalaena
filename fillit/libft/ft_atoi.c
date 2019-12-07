/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvalaena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 17:20:14 by nvalaena          #+#    #+#             */
/*   Updated: 2019/09/29 21:03:43 by nvalaena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long int	res;
	long				neg;

	neg = 1;
	res = 0;
	while (*str && (*str == ' ' || ((*str > 8) && (*str < 14))))
		str++;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		if (res > 9223372036854775807 && neg == 1)
			return (-1);
		else if (res > 9223372036854775807 && neg == -1)
			return (0);
		res = res * 10 + (*str - '0');
		str++;
	}
	return ((int)(res * neg));
}
