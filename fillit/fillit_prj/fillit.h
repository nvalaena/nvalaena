/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 18:47:19 by romarash          #+#    #+#             */
/*   Updated: 2019/12/07 16:41:04 by nvalaena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include "../libft/libft.h"
# include "get_next_line.h"

typedef struct	s_tetraminka
{
	int					*coord;
	char				c;
	struct s_tetraminka	*next;
	struct s_tetraminka	*last;
}				t_tetraminka;
void			ft_lstiters(t_tetraminka *list, void (*f)(t_tetraminka *elem));
void			ft_lstdels(t_tetraminka **alst);
t_tetraminka	*ft_lstnews();
void			ft_write(t_tetraminka *start);
int				ft_minx(int *coord);
int				ft_miny(int *coord);
void			ft_coord_to_null (t_tetraminka *start);
char			**ft_create_map(int x);
void			ft_write_arr(char **res);
int				ft_put_1tetraminka(t_tetraminka *start, char **map, int x0,
		int y0);
int				ft_put(t_tetraminka *start, int razmer, char **map);
int				*ft_find_start_coord(char **map, t_tetraminka *tetra,
		int razmer);
void			ft_dostat(char **map, int razmer, t_tetraminka *tetra);
int				ft_move(t_tetraminka *tetra, int razmer, char **map);
void			ft_putt(t_tetraminka *start, int razmer);
int				main(int argc, char **argv);

#endif
