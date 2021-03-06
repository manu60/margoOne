/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:24:55 by sgirard           #+#    #+#             */
/*   Updated: 2020/02/03 17:43:19 by sgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long i;

	i = (long)n;
	if (i < 0)
	{
		i = (i * (-1));
		ft_putchar('-');
	}
	if (i >= 0 && i < 10)
		ft_putchar(i + '0');
	if (i >= 10)
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
	return ;
}
