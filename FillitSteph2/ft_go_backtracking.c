/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_backtracking.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirard <sgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:24:12 by sgirard           #+#    #+#             */
/*   Updated: 2020/11/08 17:30:44 by sgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	put_map(char **table, int size)
{
	int		i;

	i = 0;
	while (i < size)
		ft_putendl(table[i++]);
	map_free(table, size);
	exit(1);
}

int		check_enter(t_env *env1, int *t, int x, int y)
{
	if (env1->map[y][x] != '.')
		return (0);
	if (x + t[0] < 0 || x + t[0] >= env1->map_size || y + t[1] < 0 || y + t[1]
			>= env1->map_size || env1->map[y + t[1]][x + t[0]] != '.')
		return (0);
	if (x + t[2] < 0 || x + t[2] >= env1->map_size || y + t[3] < 0 || y + t[3]
			>= env1->map_size || env1->map[y + t[3]][x + t[2]] != '.')
		return (0);
	if (x + t[4] < 0 || x + t[4] >= env1->map_size || y + t[5] < 0 || y + t[5]
			>= env1->map_size || env1->map[y + t[5]][x + t[4]] != '.')
		return (0);
	return (1);
}

void	put_tetro(char **map, int *t, int *x, int *y)
{
	int		a;
	int		b;

	b = *y;
	a = *x;
	*y = 0;
	*x = 0;
	map[b][a] = 'A' + t[6];
	map[b + t[1]][a + t[0]] = 'A' + t[6];
	map[b + t[3]][a + t[2]] = 'A' + t[6];
	map[b + t[5]][a + t[4]] = 'A' + t[6];
}

void	backtracking(t_env *env1, int x, int y, int cur)
{
	env1->map = clear_map(env1->map, cur);
	if (x == env1->map_size)
		incre_zero(&y, &x);
	while (cur < env1->nbp)
	{
		if (env1->map[y][x] == '.' &&
				check_enter(env1, env1->tetros[cur], x, y))
			put_tetro(env1->map, env1->tetros[cur++], &x, &y);
		else
		{
			if (x++ == env1->map_size)
				incre_zero(&y, &x);
			if (y == env1->map_size && cur == 0)
			{
				//map_free(env1->map, env1->map_size);
				env1->map_size++;
				env1->map = ft_map(env1->map_size);
				backtracking(env1, 0, 0, 0);
			}
			if (y == env1->map_size)
				backtracking(env1, actual_x(env1->map, cur - 1) + 1,
					actual_y(env1->map, cur - 1), cur - 1);
		}
		if (cur == env1->nbp)
			put_map(env1->map, env1->map_size);
	}
}

void	ft_go_backtracking(t_env *env1, int **tetro)
{
	env1->tetros = tetro;
	env1->map = malloc(sizeof(env1->map) * 3);
	if (env1->map == NULL)
		return ;
	env1->map_size = ft_find_the_square(env1->nbp * 4);
	free(env1->map);
	env1->map = ft_map(env1->map_size);
	backtracking(env1, 0, 0, 0);
}
