/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:45:57 by apeposhi          #+#    #+#             */
/*   Updated: 2023/07/21 21:51:09 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <memory.h>
# include <mlx.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_map
{
	int		pl;
	size_t	x_p;
	size_t	y_p;
	size_t	fnsh;
	size_t	clls;
	size_t	l;
	size_t	h;
}			t_map;

typedef struct s_images
{
	void	*pl;
	void	*pl2;
	void	*enemy;
	void	*cll;
	void	*wall;
	void	*empty;
	void	*fnsh;
	void	*win;
	void	*lose;
}	t_images;

typedef struct s_data
{
	void		*mlx;
	void		*wdw;
	int			i_s;
	t_map		map;
	t_images	images;
	char		**c_state;
}	t_data;

typedef struct s_map_cp
{
	size_t	exit;
	size_t	col;
}	t_map_cp;

int		ft_print_error(char *message, int r_value);
int		ft_read_map(t_data *g_d, char *map);
int		ft_validate_map(t_data *g_d);
int		ft_is_map_winnable(t_map *map, char **c_state);
void	ft_init(t_data *g_d);
int		ft_free(t_data *g_d, int return_value);
int		ft_initialize(t_data *g_d);
int		ft_animate(t_data *g_d);
int		ft_hooks(int keycode, t_data *g_d);
int		ft_hooks_x(t_data *g_d);
int		ft_count_moves(t_data *g_d);
int		ft_move_up(t_data *g_d);
int		ft_move_down(t_data *g_d);
int		ft_move_left(t_data *g_d);
int		ft_move_right(t_data *g_d);

#endif
