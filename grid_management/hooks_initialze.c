/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_initialze.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:22:15 by jfrances          #+#    #+#             */
/*   Updated: 2023/04/10 14:22:20 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	grid_conditionals(t_parse *tl, int j, int i)
{
	if (tl->map[i][j] == '1')
		mlx_put_image_to_window(tl->mlx, tl->win, \
			tl->spr.walls, j * 64, i * 64 + 1);
	else if (tl->map[i][j] == 'E')
		mlx_put_image_to_window(tl->mlx, tl->win, \
			tl->spr.exit, j * 64, i * 64 + 1);
	else if (tl->map[i][j] == 'C')
		mlx_put_image_to_window(tl->mlx, tl->win, \
			tl->spr.collect, j * 64, i * 64 + 1);
	else if (tl->map[i][j] == 'P')
		mlx_put_image_to_window(tl->mlx, tl->win, \
			tl->spr.player, j * 64, i * 64 + 2);
}

void	ft_window_initialize(t_parse *tl, int i, int j)
{
	tl->mlx = mlx_init();
	store_sprites(tl);
	tl->win = mlx_new_window(tl->mlx, tl->len * 64, \
		tl->i * 64, "so_long");
	while (tl->map[++i])
	{
		j = -1;
		while (tl->map[i][++j])
		{
			if (tl->map[i][j] != '\n')
				mlx_put_image_to_window(tl->mlx, tl->win, \
					tl->spr.floors, j * 64, i * 64);
		}
	}
	i = -1;
	while (tl->map[++i])
	{
		j = -1;
		while (tl->map[i][++j])
			grid_conditionals(tl, j, i);
	}
	mlx_key_hook(tl->win, key_handles, tl);
	mlx_hook(tl->win, 17, 0, &handle_exit, tl);
	mlx_loop(tl->mlx);
}

void	store_sprites(t_parse *tl)
{
	tl->spr.player = mlx_xpm_file_to_image(tl->mlx, "sprites_xpm/player.xpm", \
		&tl->spr.img_width, &tl->spr.img_height);
	tl->spr.walls = mlx_xpm_file_to_image(tl->mlx, "sprites_xpm/wall.xpm", \
		&tl->spr.img_width, &tl->spr.img_height);
	tl->spr.floors = mlx_xpm_file_to_image(tl->mlx, "sprites_xpm/floor.xpm", \
		&tl->spr.img_width, &tl->spr.img_height);
	tl->spr.collect = mlx_xpm_file_to_image(tl->mlx, "sprites_xpm/collect.xpm", \
		&tl->spr.img_width, &tl->spr.img_height);
	tl->spr.exit = mlx_xpm_file_to_image(tl->mlx, "sprites_xpm/exit.xpm", \
		&tl->spr.img_width, &tl->spr.img_height);
}
