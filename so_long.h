/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:56:19 by jfrances          #+#    #+#             */
/*   Updated: 2023/04/05 20:05:08 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "so_long_structs.h"

void	change_rem(t_parse *pr);
void	mv_pos_up(t_player *pl, t_parse *pr);
void	mv_pos_lef(t_player *pl, t_parse *pr);
void	mv_pos_down(t_player *pl, t_parse *pr);
void	mv_pos_rig(t_player *pl, t_parse *pr);
void	check_pos(t_player *pl, t_parse *pr);
void	store_sprites(t_parse *tl);
void	update_frame(t_player *pl, t_parse *pr, int i, int j);
void	store_sprites(t_parse *tl);
void	counter(t_parse *pr);
void	store_death_animation(t_parse *tl);
void	ft_window_initialize(t_parse *tl, int i, int j);
void	print_initial_map(t_parse *tl);
void	line_check(int len, int i);
void	grab_player(t_parse *tptr);
void	map_parse(char *str, t_parse *tptr);
int		grid_cpy(t_parse *tptr, char *str);
void	intialize_vars(char *str, t_parse *tools);
void	game_exit(char *pstr);
void	check_walls(t_parse *pr);
size_t	ft_strlen(const char *str);
int		open_file(char *str);
int		ft_printf(const char *a, ...);
int		ft_strchr_num(char *str, int n);
int		token(int c, int e, int p);
int		chr_count(char *str, char c);
int		ft_strstr(char *str, char *to_find);
int		key_handles(int key_code, t_parse *pr);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);
char	*get_next_line(int fd);
void	close_window(t_parse *pr);
void	free_matrix(char **map, int nm, char *str);
char	**ft_split(const char *str, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		handle_exit(t_parse *pr);
#endif
