/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvalaena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 14:43:04 by nvalaena          #+#    #+#             */
/*   Updated: 2019/09/29 21:02:04 by nvalaena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	unsigned int	i;
	size_t			buff;
	unsigned int	j;

	i = ft_strlen(dst);
	buff = i + ft_strlen(src);
	j = 0;
	if (n < i)
		return (ft_strlen(src) + n);
	if (n > i + 1)
	{
		while (src[j] && j < n - i - 1)
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = '\0';
	}
	return (buff);
}
