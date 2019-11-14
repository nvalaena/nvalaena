/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvalaena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 21:22:13 by nvalaena          #+#    #+#             */
/*   Updated: 2019/09/28 16:59:13 by nvalaena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		begin;
	int		length;
	int		count3;
	char	*newstr;

	begin = 0;
	count3 = 0;
	newstr = NULL;
	if (s == NULL)
		return (NULL);
	length = ft_strlen(s) - 1;
	while (ft_isspace(s[begin]))
		begin++;
	while (ft_isspace(s[length]) && length >= begin)
		length--;
	if ((newstr = (char*)malloc(sizeof(char) * (length - begin + 2))) == NULL)
		return (NULL);
	while (begin <= length && length > 0)
		newstr[count3++] = s[begin++];
	newstr[count3] = '\0';
	return (newstr);
}
