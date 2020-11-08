/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirard <sgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:37:50 by sgirard           #+#    #+#             */
/*   Updated: 2020/11/08 17:20:21 by sgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**clear_map(char **map, int cur)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] >= 'A' + cur)
				map[y][x] = '.';
			x++;
		}
		x = 0;
		y++;
	}
	return (map);
}

int		actual_x(char **map, int cur)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (map[y][x] != 'A' + cur)
	{
		if (!map[y][x++])
		{
			x = 0;
			y++;
		}
	}
	return (x);
}

int		actual_y(char **map, int cur)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (map[y][x] != 'A' + cur)
	{
		if (!map[y][x++])
		{
			x = 0;
			y++;
		}
	}
	return (y);
}

void	bigger_map(t_env *env1)
{
	//map_free(env1->map, taille);
	env1->map = ft_map(env1->map_size++);
}
