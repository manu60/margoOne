/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirard <sgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 10:28:24 by sgirard           #+#    #+#             */
/*   Updated: 2020/10/23 10:28:43 by sgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_env		*env1;

	env1 = NULL;
	env1 = (t_env*)malloc(sizeof(t_env));
	if (argc != 2)
	{
		ft_putstr("Usage: ./fillit [source file]\n");
		free(env1);
		return (1);
	}
	else
	{
		if (correct_file(argv[1]) == 0)
		{
			ft_putstr("error\n");
			free(env1);
			return (1);
		}
		else
			stock_tetris(argv[1], env1);
	}
	free(env1);
	return (0);
}
