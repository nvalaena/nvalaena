/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvalaena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 20:28:25 by nvalaena          #+#    #+#             */
/*   Updated: 2019/09/29 21:08:17 by nvalaena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int					i;
	unsigned const char	*buff_s1;
	unsigned const char	*buff_s2;

	buff_s1 = s1;
	buff_s2 = s2;
	i = 0;
	while (n--)
	{
		if (buff_s1[i] != buff_s2[i])
			return ((int)(buff_s1[i] - buff_s2[i]));
		i++;
	}
	return (0);
}
