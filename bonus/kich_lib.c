/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kich_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrances <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:35:36 by jfrances          #+#    #+#             */
/*   Updated: 2023/04/02 14:49:07 by jfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	open_file(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		game_exit("READ ERROR");
	return (fd);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strstr(char *str, char *to_find)
{
	int	i;
	int	k;

	i = 0;
	if (to_find[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		k = 0;
		while (str[i + k] == to_find[k])
		{
			if (to_find[k + 1] == '\0')
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr_num(char *s, int c)
{
	size_t	i;
	int		count;

	count = 0;
	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
		{
			if (s[i] == '\n')
				return (1);
		}
		i++;
	}
	return (0);
}
