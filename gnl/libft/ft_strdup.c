/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvalaena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:19:13 by nvalaena          #+#    #+#             */
/*   Updated: 2019/09/29 22:22:47 by nvalaena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*arr;
	int		i;

	if (!(arr = (char *)malloc(sizeof(*arr) * ft_strlen(s) + 1)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		arr[i] = s[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
