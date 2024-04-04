/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:55:47 by jfrances          #+#    #+#             */
/*   Updated: 2023/03/28 15:42:57 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	null_free(t_parse *tools)
{
	if (!tools)
		return ;
	else
		free(tools);
}

void	intialize_vars(char *str, t_parse *tools)
{
	tools->tmp_c = 0;
	tools->i = 0;
	tools->p = 0;
	tools->e = 0;
	tools->c = 0;
	tools->x = 0;
	tools->y = 0;
	tools->player.c = 0;
	tools->player.x = 0;
	tools->player.y = 0;
	tools->player.steps = 0;
	if (grid_cpy(tools, str) == 0)
		game_exit("ERROR");
}

void	game_exit(char *pstr)
{
	ft_printf("%s\n", pstr);
	exit(0);
}

int	main(int argc, char **argv)
{	
	int		i;
	int		j;
	t_parse	*tools;

	i = -1;
	j = i;
	if (argc != 2 || (ft_strstr(argv[1], ".ber") == 0))
		game_exit("Error: Invalid Input");
	tools = malloc(sizeof(t_parse));
	if (!tools)
		game_exit("Error: Malloc Error");
	intialize_vars(argv[1], tools);
	ft_window_initialize(tools, i, j);
	return (0);
}
