/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvalaena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:01:04 by nvalaena          #+#    #+#             */
/*   Updated: 2019/11/21 20:07:53 by nvalaena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
int	main(void)
{
	int	fd;
	if (_sopen_s(&fd, "1.txt", _O_RDONLY, _SH_DENYNO, 0))
	{
		printf("error");
		return -1;
	}
	char *line;
	while (get_next_line(fd, &line))
	{
		printf("%s", line);
	}
	return 0;
}
