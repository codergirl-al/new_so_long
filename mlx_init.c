/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:30:18 by apeposhi          #+#    #+#             */
/*   Updated: 2023/07/21 17:42:04 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

static void	ft_render_map(t_data *g_d)
{
	size_t		i;
	size_t		j;
	int			*s;
	t_images	*img;

	s = &g_d->image_size;
	img = &g_d->images;
	i = 0;
	while (i < g_d->map.m_height)
	{
		j = 0;
		while (j < g_d->map.m_length)
		{
			if (g_d->c_state[i][j] == '1')
				mlx_put_image_to_window(g_d->mlx, g_d->window, img->wall, j * *s, i * *s + 20);
			if (g_d->c_state[i][j] == 'E')
				mlx_put_image_to_window(g_d->mlx, g_d->window, img->finish, j * *s, i * *s + 20);
			if (g_d->c_state[i][j] == 'P')
				mlx_put_image_to_window(g_d->mlx, g_d->window, img->player, j * *s, i * *s + 20);
			if (g_d->c_state[i][j] == 'C')
				mlx_put_image_to_window(g_d->mlx, g_d->window, img->cll, j * *s, i * *s + 20);
			if (g_d->c_state[i][j] == 'A')
				mlx_put_image_to_window(g_d->mlx, g_d->window, img->enemy, j * *s, i * *s + 20);
			j++;
		}
		i++;
	}
}

static int	ft_init_images(t_data *g_d)
{
	int			*s;
	t_images	*img;

	s = &g_d->image_size;
	img = &g_d->images;
	img->cll = mlx_xpm_file_to_image(g_d->mlx, "./img/cll.xpm", s, s);
	img->finish = mlx_xpm_file_to_image(g_d->mlx, "./img/exit.xpm", s, s);
	img->wall = mlx_xpm_file_to_image(g_d->mlx, "./img/wall.xpm", s, s);
	img->enemy = mlx_xpm_file_to_image(g_d->mlx, "./img/enemy.xpm", s, s);
	img->empty = mlx_xpm_file_to_image(g_d->mlx, "./img/del.xpm", s, s);
	img->win = mlx_xpm_file_to_image(g_d->mlx, "./img/win.xpm", s, s);
	img->player = mlx_xpm_file_to_image(g_d->mlx, "./img/player.xpm", s, s);
	img->player2 = mlx_xpm_file_to_image(g_d->mlx, "./img/player2.xpm", s, s);
	img->lose = mlx_xpm_file_to_image(g_d->mlx, "./img/loss.xpm", s, s);
	if (!(img->cll && img->finish && img->wall && img->enemy && img->win && img->lose))
		return (ft_print_error("Couldn't render images.", 1));
	return (0);
}

int	ft_initialize(t_data *g_d)
{
	g_d->image_size = 64;
	g_d->mlx = mlx_init();
	if (g_d->mlx == NULL)
		return (ft_print_error("Couldn't set up MLX", 1));
	// dont let it crash (g_d->map.m_length * g_d->image_size) > 3000; both (g_d->map.m_height * g_d->image_size)
	g_d->window = mlx_new_window(g_d->mlx, g_d->map.m_length * g_d->image_size, (g_d->map.m_height * g_d->image_size) + 30, "./so_long");
	if (g_d->window == NULL)
		return (ft_print_error("Couldn't set up window", 1));
	if (ft_init_images(g_d))
		return (1);
	mlx_string_put(g_d->mlx, g_d->window, 6, 15, 0x00ff0000, "Moves:");
	mlx_string_put(g_d->mlx, g_d->window, 52, 15, 0x00ff0000, "0");
	ft_render_map(g_d);
	return (0);
}