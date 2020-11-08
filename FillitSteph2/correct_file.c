/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirard <sgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 12:24:08 by sgirard           #+#    #+#             */
/*   Updated: 2020/11/03 10:27:07 by sgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

int		ft_nb_sharp(char *str)
{
	int		i;
	int		j;

	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '#')
			j++;
		i++;
	}
	if (j == 4)
		return (1);
	return (0);
}

int		ft_check_char(char *str)
{
	int		i;
	int		nb_chr;

	if (!str)
		return (0);
	i = 0;
	nb_chr = 0;
	while (str[i])
	{
		if (str[i] == '.' || str[i] == '#')
			nb_chr++;
		i++;
	}
	if (nb_chr == 16)
		return (1);
	return (0);
}

int		ft_check_line(char *str, int nb_read)
{
	int		i;
	int		j;

	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (str[i])
	{
		i += 4;
		if (str[i] == '\n')
			j++;
		i++;
	}
	if (j == 4 || nb_read == 19)
		return (1);
	return (0);
}

int		ft_tetri_valid(char *str)
{
	size_t	i;
	int		touch;

	i = 0;
	touch = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if ((i - 5 >= 0) && (str[i - 5] == '#'))
				touch++;
			if ((i - 1 >= 0) && (str[i - 1] == '#'))
				touch++;
			if ((i + 5 < ft_strlen(str)) && (str[i + 5] == '#'))
				touch++;
			if ((i + 1 < ft_strlen(str)) && (str[i + 1] == '#'))
				touch++;
		}
		i++;
	}
	if (touch >= 6)
		return (1);
	return (0);
}

int		correct_file(char *file)
{
	char	*buff;
	int		fd;
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	buff = ft_strnew(21);
	if (!(fd = open(file, O_RDONLY)) && (fd < 0))
		return (free_buff(buff));
	while ((ret = read(fd, buff, 21)))
	{
		i++;
		buff[ret] = '\0';
		if ((ft_nb_sharp(buff) == 0) || (ft_check_char(buff) == 0) ||
				(ft_check_line(buff, ret) == 0) || (ft_tetri_valid(buff) == 0))
			return (free_buff(buff));
	}
	if ((buff[20] != '\0' && buff[19] != '\0') || ((!i) || (i > 26)))
		return (free_buff(buff));
	free(buff);
	close(fd);
	return (1);
}
