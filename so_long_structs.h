/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:45:46 by jfrances          #+#    #+#             */
/*   Updated: 2023/04/05 20:05:41 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRUCTS_H
# define SO_LONG_STRUCTS_H
# include "so_long.h"
# include <mlx.h>

typedef struct s_player
{
	int	c;
	int	x;
	int	y;
	int	steps;
}				t_player;

typedef struct s_spr
{
	void	*player;
	void	*walls;
	void	*floors;
	void	*collect;
	void	*exit;
	void	*rem;
	int		img_width;
	int		img_height;
}				t_spr;

typedef struct s_parse
{
	int			tmp_c;
	char		**map;
	int			x;
	int			y;
	char		*line;
	int			i;
	int			c;
	int			e;
	int			p;
	size_t		len;
	void		*mlx;
	void		*win;
	char		*nb;
	t_player	player;
	t_spr		spr;
}				t_parse;
#endif
