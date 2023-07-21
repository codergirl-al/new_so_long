/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_functionalities.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:27:34 by apeposhi          #+#    #+#             */
/*   Updated: 2023/07/21 17:44:42 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	ft_move_player(t_data *g_d, size_t x, size_t y)
{
	int			*s;
	t_images	*img;

	s = &g_d->image_size;
	img = &g_d->images;
	mlx_put_image_to_window(g_d->mlx, g_d->window, img->empty, g_d->map.x_p * *s, g_d->map.y_p * *s + 20);	
	mlx_put_image_to_window(g_d->mlx, g_d->window, img->player, x * *s, y * *s + 20);
	if (g_d->c_state[y][x] == 'C')
		g_d->map.clls = g_d->map.clls - 1;
	g_d->c_state[y][x] = 'P';
	g_d->c_state[ g_d->map.y_p][g_d->map.x_p] = '0';
	g_d->map.x_p = x;
	g_d->map.y_p = y;
}

int	ft_move_up(t_data *g_d)
{
	size_t	*x;
	size_t	*y;

	x = &g_d->map.x_p;
	y = &g_d->map.y_p;
	if (g_d->c_state[*y - 1][*x] == '1')
		return (0);
	else if (g_d->c_state[*y - 1][*x] == '0' || g_d->c_state[*y - 1][*x] == 'C')
	{
		ft_move_player(g_d, *x, *y - 1);
	}
	else if (g_d->c_state[*y - 1][*x] == 'A')
	{
		ft_move_player(g_d, *x, *y - 1);
		write(1, "lose\n", 5);
		exit (ft_free(g_d, 0));
	}
	else if (g_d->c_state[*y - 1][*x] == 'E' && g_d->map.clls == 0)
	{
		ft_move_player(g_d, *x, *y - 1);
		write(1, "win\n", 4); 
		exit (ft_free(g_d, 0));
	}
	return (0);
}

int	ft_move_left(t_data *g_d)
{
	size_t	*x;
	size_t	*y;

	x = &g_d->map.x_p;
	y = &g_d->map.y_p;
	if (g_d->c_state[*y][*x - 1] == '1')
		return (0);
	else if (g_d->c_state[*y][*x - 1] == '0' || g_d->c_state[*y][*x - 1] == 'C')
	{
		ft_move_player(g_d, *x - 1, *y);
	}
	else if (g_d->c_state[*y][*x - 1] == 'A')
	{
		ft_move_player(g_d, *x - 1, *y);
		write(1, "lose\n", 5);
		exit (ft_free(g_d, 0));
	}
	else if (g_d->c_state[*y][*x - 1] == 'E' && g_d->map.clls == 0)
	{
		ft_move_player(g_d, *x - 1, *y);
		write(1, "win\n", 4); 
		exit (ft_free(g_d, 0));
	}
	return (0);
}

int	ft_move_down(t_data *g_d)
{
	size_t	*x;
	size_t	*y;

	x = &g_d->map.x_p;
	y = &g_d->map.y_p;
	if (g_d->c_state[*y + 1][*x] == '1')
		return (0);
	else if (g_d->c_state[*y + 1][*x] == '0' || g_d->c_state[*y + 1][*x] == 'C')
	{
		ft_move_player(g_d, *x, *y + 1);
	}
	else if (g_d->c_state[*y + 1][*x] == 'A')
	{
		ft_move_player(g_d, *x, *y + 1);
		write(1, "lose\n", 5); // not done
		exit (ft_free(g_d, 0));
	}
	else if (g_d->c_state[*y + 1][*x] == 'E' && g_d->map.clls)
	{
		ft_move_player(g_d, *x, *y + 1);
		write(1, "win\n", 4);
		exit (ft_free(g_d, 0));
	}
	return (0);
}

int	ft_move_right(t_data *g_d)
{
	size_t	*x;
	size_t	*y;

	x = &g_d->map.x_p;
	y = &g_d->map.y_p;
	if (g_d->c_state[*y][*x + 1] == '1')
		return (0);
	else if (g_d->c_state[*y][*x + 1] == '0' || g_d->c_state[*y][*x + 1] == 'C')
	{
		ft_move_player(g_d, *x + 1, *y);
	}
	else if (g_d->c_state[*y][*x + 1] == 'E' && g_d->map.clls == 0)
	{
		ft_move_player(g_d, *x + 1, *y);
		write(1, "win\n", 4); 
		exit (ft_free(g_d, 0));
	}
	else if (g_d->c_state[*y][*x + 1] == 'A')
	{
		ft_move_player(g_d, *x + 1, *y);
		write(1, "lose\n", 5); // not done
		exit (ft_free(g_d, 0));
	}
	return (0);
}
