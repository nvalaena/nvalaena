/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvalaena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:14:07 by nvalaena          #+#    #+#             */
/*   Updated: 2019/09/28 18:22:20 by nvalaena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *arr;

	if (size + 1 == 0)
		return (NULL);
	if (!(arr = (char *)ft_memalloc(sizeof(*arr) * size + 1)))
		return (NULL);
	return (arr);
}
