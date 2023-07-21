/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:45:57 by apeposhi          #+#    #+#             */
/*   Updated: 2023/06/17 16:15:59 by apeposhi         ###   ########.fr       */
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
	int		player;
	size_t	x_position;
	size_t	y_position;
	size_t	finish;
	size_t	collectibles;
	size_t	m_length;
	size_t	m_height;
} t_map;

typedef struct s_images
{
	void	*player; //P
	void	*player2; //P
	void	*enemy; // A
	void	*collectible;
	void	*wall; //1
	void	*empty; //C
	void	*finish; //E
	void	*win;
	void	*lose;
} t_images;

typedef struct s_data
{
	void		*mlx;
	void		*window;
	int			image_size;
	t_map		map;
	t_images	images;
	char		**current_state;
} t_data;

typedef struct s_map_cp
{
	size_t	exit;
	size_t	col;
}	t_map_cp;

int		ft_print_error(char *message, int r_value);
int		ft_read_map(t_data *game_data, char *map);
int		ft_validate_map(t_data *game_data);
int		ft_is_map_winnable(t_map *map, char **current_state);
void	ft_init(t_data *game_data);
int		ft_free(t_data *game_data, int return_value);
int		ft_initialize(t_data *game_data);
int		ft_animate(t_data *game_data);
int		ft_hooks(int keycode, t_data *game_data);
int		ft_hooks_x(t_data *game_data);
int		ft_count_moves(t_data *game_data);
int		ft_move_up(t_data *game_data);
int		ft_move_down(t_data *game_data);
int		ft_move_left(t_data *game_data);
int		ft_move_right(t_data *game_data);

#endif