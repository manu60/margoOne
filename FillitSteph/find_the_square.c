/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_the_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirard <sgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:45:41 by sgirard           #+#    #+#             */
/*   Updated: 2020/10/21 15:47:18 by sgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_find_the_square(int n)
{
	int ret;

	ret = 0;
	while (ret * ret < n)
		ret++;
	return (ret);
}
