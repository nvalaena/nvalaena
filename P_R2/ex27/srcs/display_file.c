/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvalaena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:33:06 by nvalaena          #+#    #+#             */
/*   Updated: 2019/09/16 14:43:38 by nvalaena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	display(char *name_of_file)
{
	int		count_of_files;
	char	character;

	count_of_files = open(name_of_file, O_RDONLY);
	if (count_of_files < 0)
		return ;
	while (read(count_of_files, &character, 1))
		write(1, &character, 1);
	close(count_of_files);
}

int		main(int ac, char *av[])
{
	if (ac == 1)
		write(2, "File name missing.\n", 19);
	else if (ac > 2)
		write(2, "Too many arguments.\n", 20);
	else
		display(av[1]);
	return (0);
}
