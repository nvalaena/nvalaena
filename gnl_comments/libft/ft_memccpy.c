/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvalaena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 19:28:29 by nvalaena          #+#    #+#             */
/*   Updated: 2019/09/29 21:07:43 by nvalaena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int i;

	i = 0;
	while (n--)
	{
		((unsigned char *)dst)[i] = ((unsigned const char *)src)[i];
		if (((unsigned char *)src)[i] == ((unsigned char)c))
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
