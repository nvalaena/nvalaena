/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvalaena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:57:58 by nvalaena          #+#    #+#             */
/*   Updated: 2019/12/07 16:35:07 by nvalaena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>

# define BUFF_SIZE 32
# define FD_MAX 10240

int	get_next_line(const int fd, char **line);

#endif
