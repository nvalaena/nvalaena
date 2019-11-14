/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvalaena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:02:09 by nvalaena          #+#    #+#             */
/*   Updated: 2019/09/26 19:08:27 by nvalaena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*arr;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(arr = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[i])
	{
		arr[i] = f(i, s[i]);
		i++;
	}
	return (arr);
}
