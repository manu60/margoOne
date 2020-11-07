/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirard <sgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:31:19 by sgirard           #+#    #+#             */
/*   Updated: 2020/10/21 15:31:35 by sgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_map(int size)
{
	char	**ret;
	int		i;

	i = 0;
	if (!(ret = (char **)ft_memalloc(sizeof(ret) * size + 1)))
		return (NULL);
	while (i < size)
	{
		ret[i] = ft_strnew(size);
		ft_memset(ret[i], '.', size);
		i++;
	}
	return (ret);
}
