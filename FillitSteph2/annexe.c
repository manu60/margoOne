/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annexe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirard <sgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 12:35:16 by sgirard           #+#    #+#             */
/*   Updated: 2020/11/03 11:13:02 by sgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	incre_zero(int *y, int *x)
{
	*y += 1;
	*x = 0;
}

void	zero_zero(int *a, int *b)
{
	*a = 0;
	*b = 0;
}

void	escape_norm(int *ret, int *i)
{
	ret[i[0]] = i[2] - i[1];
	i[0] += 1;
	ret[i[0]] = i[4] - i[3];
	i[0] += 1;
}

void	map_free(char **map, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		ft_memdel((void **)&(map[i]));
	ft_memdel((void **)&map);
}

int		free_buff(char *buff)
{
	free(buff);
	return (0);
}
