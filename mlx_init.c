/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:30:18 by apeposhi          #+#    #+#             */
/*   Updated: 2023/06/18 16:04:44 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

static void	ft_render_map(t_data *game_data)
{
	size_t		i;
	size_t		j;
	int			*s;
	t_images	*img;

	s = &game_data->image_size;
	img = &game_data->images;
	i = 0;
	while (i < game_data->map.m_height)
	{
		j = 0;
		while (j < game_data->map.m_length)
		{
			if (game_data->current_state[i][j] == '1')
				mlx_put_image_to_window(game_data->mlx, game_data->window, img->wall, j * *s, i * *s + 20);
			if (game_data->current_state[i][j] == 'E')
				mlx_put_image_to_window(game_data->mlx, game_data->window, img->finish, j * *s, i * *s + 20);
			if (game_data->current_state[i][j] == 'P')
				mlx_put_image_to_window(game_data->mlx, game_data->window, img->player, j * *s, i * *s + 20);
			if (game_data->current_state[i][j] == 'C')
				mlx_put_image_to_window(game_data->mlx, game_data->window, img->collectible, j * *s, i * *s + 20);
			if (game_data->current_state[i][j] == 'A')
				mlx_put_image_to_window(game_data->mlx, game_data->window, img->enemy, j * *s, i * *s + 20);
			j++;
		}
		i++;
	}
}

static int	ft_init_images(t_data *game_data)
{
	int			*s;
	t_images	*img;

	s = &game_data->image_size;
	img = &game_data->images;
	img->collectible = mlx_xpm_file_to_image(game_data->mlx, "./img/collectible.xpm", s, s);
	img->finish = mlx_xpm_file_to_image(game_data->mlx, "./img/exit.xpm", s, s);
	img->wall = mlx_xpm_file_to_image(game_data->mlx, "./img/wall.xpm", s, s);
	img->enemy = mlx_xpm_file_to_image(game_data->mlx, "./img/enemy.xpm", s, s);
	img->empty = mlx_xpm_file_to_image(game_data->mlx, "./img/del.xpm", s, s);
	img->win = mlx_xpm_file_to_image(game_data->mlx, "./img/win.xpm", s, s);
	img->player = mlx_xpm_file_to_image(game_data->mlx, "./img/player.xpm", s, s);
	img->player2 = mlx_xpm_file_to_image(game_data->mlx, "./img/player2.xpm", s, s);
	img->lose = mlx_xpm_file_to_image(game_data->mlx, "./img/loss.xpm", s, s);
	if (!(img->collectible && img->finish && img->wall && img->enemy && img->win && img->lose))
		return (ft_print_error("Couldn't render images.", 1));
	return (0);
}

int	ft_initialize(t_data *game_data)
{
	game_data->image_size = 64;
	game_data->mlx = mlx_init();
	if (game_data->mlx == NULL)
		return (ft_print_error("Couldn't set up MLX", 1));
	// dont let it crash (game_data->map.m_length * game_data->image_size) > 3000; both (game_data->map.m_height * game_data->image_size)
	game_data->window = mlx_new_window(game_data->mlx, game_data->map.m_length * game_data->image_size, (game_data->map.m_height * game_data->image_size) + 30, "./so_long");
	if (game_data->window == NULL)
		return (ft_print_error("Couldn't set up window", 1));
	if (ft_init_images(game_data))
		return (1);
	mlx_string_put(game_data->mlx, game_data->window, 6, 15, 0x00ff0000, "Moves:");
	mlx_string_put(game_data->mlx, game_data->window, 52, 15, 0x00ff0000, "0");
	ft_render_map(game_data);
	return (0);
}