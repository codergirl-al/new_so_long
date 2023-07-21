/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:30:18 by apeposhi          #+#    #+#             */
/*   Updated: 2023/07/21 22:12:49 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

static void	ft_render_map(t_data *g_d, t_images *img, size_t i, size_t j)
{
	size_t		yv;
	size_t		xv;

	i = -1;
	while (++i < g_d->map.h)
	{
		j = -1;
		while (++j < g_d->map.l)
		{
			yv = i * g_d->i_s + 20;
			xv = j * g_d->i_s;
			if (g_d->c_state[i][j] == '1')
				mlx_put_image_to_window(g_d->mlx, g_d->wdw, img->wall, xv, yv);
			if (g_d->c_state[i][j] == 'E')
				mlx_put_image_to_window(g_d->mlx, g_d->wdw, img->fnsh, xv, yv);
			if (g_d->c_state[i][j] == 'P')
				mlx_put_image_to_window(g_d->mlx, g_d->wdw, img->pl, xv, yv);
			if (g_d->c_state[i][j] == 'C')
				mlx_put_image_to_window(g_d->mlx, g_d->wdw, img->cll, xv, yv);
			if (g_d->c_state[i][j] == 'A')
				mlx_put_image_to_window(g_d->mlx, g_d->wdw, img->enemy, xv, yv);
		}
	}
}

static int	ft_init_images(t_data *g_d)
{
	int			*s;
	t_images	*img;

	s = &g_d->i_s;
	img = &g_d->images;
	img->cll = mlx_xpm_file_to_image(g_d->mlx, "./img/cll.xpm", s, s);
	img->fnsh = mlx_xpm_file_to_image(g_d->mlx, "./img/exit.xpm", s, s);
	img->wall = mlx_xpm_file_to_image(g_d->mlx, "./img/wall.xpm", s, s);
	img->enemy = mlx_xpm_file_to_image(g_d->mlx, "./img/enemy.xpm", s, s);
	img->empty = mlx_xpm_file_to_image(g_d->mlx, "./img/del.xpm", s, s);
	img->win = mlx_xpm_file_to_image(g_d->mlx, "./img/win.xpm", s, s);
	img->pl = mlx_xpm_file_to_image(g_d->mlx, "./img/pl.xpm", s, s);
	img->pl2 = mlx_xpm_file_to_image(g_d->mlx, "./img/pl2.xpm", s, s);
	img->lose = mlx_xpm_file_to_image(g_d->mlx, "./img/loss.xpm", s, s);
	if (!(img->cll && img->fnsh && img->wall
			&& img->enemy && img->win && img->lose))
		return (ft_print_error("Couldn't render images.", 1));
	return (0);
}

int	ft_initialize(t_data *g_d)
{
	size_t	v;
	size_t	i;
	size_t	j;

	g_d->i_s = 64;
	v = (g_d->map.h * g_d->i_s) + 30;
	g_d->mlx = mlx_init();
	if (g_d->mlx == NULL)
		return (ft_print_error("Couldn't set up MLX", 1));
	g_d->wdw = mlx_new_window(g_d->mlx, g_d->map.l * g_d->i_s, v, "./so_long");
	if (g_d->wdw == NULL
		|| (g_d->map.l * g_d->i_s) > 3000
		|| (g_d->map.h * g_d->i_s) > 3000)
		return (ft_print_error("Couldn't set up window", 1));
	if (ft_init_images(g_d))
		return (1);
	mlx_string_put(g_d->mlx, g_d->wdw, 6, 15, 0x00ff0000, "Moves:");
	mlx_string_put(g_d->mlx, g_d->wdw, 52, 15, 0x00ff0000, "0");
	i = -1;
	j = -1;
	ft_render_map(g_d, &g_d->images, i, j);
	return (0);
}
