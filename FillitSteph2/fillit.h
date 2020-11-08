/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirard <sgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 11:18:12 by mtacnet           #+#    #+#             */
/*   Updated: 2020/11/03 11:26:56 by sgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct		s_env
{
	int		x;
	int		y;
	int		nbp;
	int		map_size;
	int		cur;
	int		offsetx;
	int		offsety;
	char	**map;
	int		**tetros;
}					t_env;

int					ft_split_tetro(char *str);
int					ft_find_the_square(int n);
int					ft_verif(char *file);
int					stock_tetris(char *file, t_env *env1);
int					ft_is_tetro(char *str);
int					ft_verif_line(char *str);
int					ft_verif_char(char *str);
int					ft_count_htag(char *str);
char				**ft_create_tab(char *buff);
char				**ft_map(int size);
void				ft_go_backtracking(t_env *env1, int **tetro);
int					actual_x(char **map, int cur);
int					actual_y(char **map, int cur);
char				**clear_map(char **map, int cur);
void				put_map(char **map, int size);
void				incre_zero(int *incre, int *zero);
void				zero_zero(int *a, int *b);
void				escape_norm(int *ret, int *i);
int					*ft_get_pos_tab(char **tab, int nb, int *i);
int					**get_pos(char ***tab);
int					ft_nb_sharp(char *str);
int					ft_check_char(char *str);
int					ft_check_line(char *str, int nb_read);
int					ft_tetri_valid(char *str);
int					correct_file(char *file);
void				map_free(char **map, int size);
int					free_buff(char *buff);
void				bigger_map(t_env *env1);
#endif
