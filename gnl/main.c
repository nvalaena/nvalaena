/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvalaena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:35:25 by nvalaena          #+#    #+#             */
/*   Updated: 2019/11/14 20:42:24 by nvalaena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		fd;
	char	*line;

	(void)ac;
	if ((fd = open(av[1], O_RDONLY)) <= 0)
	{
		ft_putstr("Open() failed.\n");
		return (-1);
	}
	line = NULL;
	while (get_next_line(fd, &line))
	{
		ft_putstr("line:");
		ft_putendl(line);
		ft_strdel(&line);
	}
	close(fd);
	return (0);
}
