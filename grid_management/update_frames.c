/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_frames.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:05:59 by jfrances          #+#    #+#             */
/*   Updated: 2023/04/02 13:22:03 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	sprite_pos_check(t_parse *pr, int j, int i)
{
	if (pr->map[i][j] == '1')
		mlx_put_image_to_window (pr->mlx, pr->win, \
			pr->spr.walls, j * 64, i * 64 + 1);
	else if (pr->map[i][j] == 'E')
		mlx_put_image_to_window(pr->mlx, pr->win, \
			pr->spr.exit, j * 64, i * 64 + 1);
	else if (pr->map[i][j] == 'C')
		mlx_put_image_to_window(pr->mlx, pr->win, \
			pr->spr.collect, j * 64, i * 64 + 1);
}

void	update_frame(t_player *pl, t_parse *pr, int i, int j)
{
	_window(pr->mlx, pr->win);
	i = -1;
	while (pr->map[++i])
	{
		j = -1;
		while (pr->map[i][++j])
		{
			if (pr->map[i][j] != '\n')
				mlx_put_image_to_window(pr->mlx, pr->win, \
					pr->spr.floors, j * 64, i * 64);
		}
	}
	i = -1;
	while (pr->map[++i])
	{
		j = -1;
		while (pr->map[i][++j])
			sprite_pos_check(pr, j, i);
		mlx_put_image_to_window(pr->mlx, pr->win, \
			pr->spr.player, pl->y * 64, pl->x * 64 + 2);
	}
}

void	check_pos(t_player *pl, t_parse *pr)
{
	if (pr->map[pl->x][pl->y] == 'C')
	{
		pl->c += 1;
		pr->map[pl->x][pl->y] = '0';
	}
	if (pr->map[pl->x][pl->y] == 'E')
	{
		if (pl->c == pr->tmp_c)
		{
			free_matrix(pr->map, 0, "");
			game_exit("YOU WIN!");
		}
	}
}
