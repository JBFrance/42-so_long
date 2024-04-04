/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:45:11 by jfrances          #+#    #+#             */
/*   Updated: 2023/04/02 13:20:42 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_handles(int key_code, t_parse *pr)
{
	if (key_code == 53)
	{
		free_matrix(pr->map, 0, "");
		game_exit("Thanks for Playing!");
	}
	else if (key_code == 13 || key_code == 126)
		mv_pos_up(&pr->player, pr);
	else if (key_code == 0 || key_code == 123)
		mv_pos_lef(&pr->player, pr);
	else if (key_code == 2 || key_code == 124)
		mv_pos_rig(&pr->player, pr);
	else if (key_code == 1 || key_code == 125)
		mv_pos_down(&pr->player, pr);
	return (0);
}

void	mv_pos_up(t_player *pl, t_parse *pr)
{
	if (pr->map[pl->x - 1][pl->y] != '1')
	{
		pl->x -= 1;
		update_frame(pl, pr, 0, 0);
		counter(pr);
		check_pos(pl, pr);
	}
	else
		return ;
}	

void	mv_pos_lef(t_player *pl, t_parse *pr)
{
	if (pr->map[pl->x][pl->y - 1] != '1')
	{
		pl->y -= 1;
		update_frame(pl, pr, 0, 0);
		counter(pr);
		check_pos(pl, pr);
	}
	else
		return ;
}

void	mv_pos_down(t_player *pl, t_parse *pr)
{
	if (pr->map[pl->x + 1][pl->y] != '1')
	{
		pl->x += 1;
		update_frame(pl, pr, 0, 0);
		counter(pr);
		check_pos(pl, pr);
	}
	else
		return ;
}

void	mv_pos_rig(t_player *pl, t_parse *pr)
{
	if (pr->map[pl->x][pl->y + 1] != '1')
	{
		pl->y += 1;
		update_frame(pl, pr, 0, 0);
		counter(pr);
		check_pos(pl, pr);
	}
	else
		return ;
}
