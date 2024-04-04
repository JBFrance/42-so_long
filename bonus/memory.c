/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:11:28 by jfrances          #+#    #+#             */
/*   Updated: 2023/04/01 18:11:30 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	handle_exit(t_parse *pr)
{
	if (!pr)
		game_exit("Thanks for playing");
	close_window (pr);
	return (0);
}

void	close_window(t_parse *pr)
{
	mlx_destroy_image(pr->mlx, pr->spr.player);
	mlx_destroy_image(pr->mlx, pr->spr.walls);
	mlx_destroy_image(pr->mlx, pr->spr.floors);
	mlx_destroy_image(pr->mlx, pr->spr.collect);
	mlx_destroy_image(pr->mlx, pr->spr.exit);
	mlx_destroy_window(pr->mlx, pr->win);
	mlx_destroy_image(pr->mlx, pr->spr.rem);
	free_matrix(pr->map, 0, "");
	if (pr->mlx)
		free(pr->mlx);
	game_exit("Play Again Soon");
}

void	free_matrix(char **map, int nm, char *str)
{
	int	i;

	if (!map && nm == 1)
	{
		ft_printf("Error %s", str);
		game_exit ("");
	}
	i = 0;
	while (map[i])
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	if (map)
		free(map);
	map = NULL;
	if (nm == 1)
	{
		ft_printf("Error %s", str);
		game_exit ("");
	}
}
