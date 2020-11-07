/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_tetris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirard <sgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 10:51:02 by sgirard           #+#    #+#             */
/*   Updated: 2020/10/23 10:25:02 by sgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <stdlib.h>

/*
**	ret[0] = position du 2eme # par rapport au premier (x)
**	ret[1] = position du 2eme # par rapport au premier (y)
**	ret[2] = position du 3eme # par rapport au premier (x)
**	ret[3] = position du 3eme # par rapport au premier (y)
**	ret[4] = position du 4eme # par rapport au premier (x)
**	ret[5] = position du 4eme # par rapport au premier (y)
**	i[0] = i
**	i[1] = x[0]
**	i[2] = x[1]
**	i[3] = y[0]
**	i[4] = y[1]
*/

int		*ft_get_pos_tab(char **tab, int nb, int *i)
{
	int		*ret;

	if (!(ret = (int *)ft_memalloc(sizeof(ret) * 8)))
		return (NULL);
	while (tab[i[3]][i[1]] != '#')
	{
		while (i[1] < 4 && tab[i[3]][i[1]] != '#')
			i[1]++;
		if (tab[i[3]][i[1]] != '#')
			incre_zero(&i[3], &i[1]);
	}
	i[2] = i[1] + 1;
	i[4] = i[3];
	while (i[4] < 4)
	{
		while (i[2] < 4)
		{
			if (tab[i[4]][i[2]] == '#')
				escape_norm(ret, i);
			i[2]++;
		}
		incre_zero(&i[4], &i[2]);
	}
	ret[6] = nb;
	return (ret);
}

int		**get_pos(char ***tab)
{
	int		**ret;
	int		i;
	int		t[5];
	int		j;

	j = 0;
	while (tab[j])
		j++;
	i = 0;
	if (!(ret = (int **)ft_memalloc(sizeof(ret) * (j + 1))))
		return (NULL);
	while (i < j)
	{
		t[0] = 0;
		t[1] = 0;
		t[2] = 0;
		t[3] = 0;
		t[4] = 0;
		ret[i] = ft_get_pos_tab(tab[i], i, t);
		i++;
	}
	return (ret);
}

int		numb_tetris(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			i++;
			if (str[i] == '\n')
				j++;
		}
		i++;
	}
	return (j);
}

char	**create_tab(char *buff)
{
	char	**tab;
	int		i;

	tab = ft_memalloc(sizeof(*tab) * 5);
	i = 0;
	while (i < 4)
	{
		tab[i] = ft_strsub(buff, i * 5, 4);
		i++;
	}
	return (tab);
}

int		stock_tetris(char *file, t_env *env1)
{
	char	***tetri;
	char	buff[1024];
	int		fd;
	int		ret;
	int		i;

	env1->nbp = 0;
	i = -1;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	while ((ret = read(fd, buff, 1024)))
		buff[ret] = '\0';
	env1->nbp = numb_tetris(buff);
	tetri = (char ***)ft_memalloc(sizeof(char**) * (env1->nbp + 1));
	if (!tetri)
		return (0);
	while (++i < env1->nbp)
		tetri[i] = create_tab(&buff[i * 21]);
	ft_go_backtracking(env1, get_pos(tetri));
	return (0);
}
