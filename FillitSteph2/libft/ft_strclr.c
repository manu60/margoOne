/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:24:25 by sgirard           #+#    #+#             */
/*   Updated: 2020/02/03 17:26:27 by sgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int len;

	len = ft_strlen(s);
	if (s == 0)
		return ;
	else
		while (len >= 0)
		{
			s[len] = '\0';
			len--;
		}
}
