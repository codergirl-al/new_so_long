/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 10:24:31 by apeposhi          #+#    #+#             */
/*   Updated: 2023/07/21 21:49:12 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h" 

void	ft_cleanup(t_data *g_d)
{
	if (g_d->mlx == NULL)
		return ;
	mlx_clear_window(g_d->mlx, g_d->wdw);
	if (g_d->images.pl)
		mlx_destroy_image(g_d->mlx, g_d->images.pl);
	if (g_d->images.pl2)
		mlx_destroy_image(g_d->mlx, g_d->images.pl2);
	if (g_d->images.enemy)
		mlx_destroy_image(g_d->mlx, g_d->images.enemy);
	if (g_d->images.wall)
		mlx_destroy_image(g_d->mlx, g_d->images.wall);
	if (g_d->images.empty)
		mlx_destroy_image(g_d->mlx, g_d->images.empty);
	if (g_d->images.cll)
		mlx_destroy_image(g_d->mlx, g_d->images.cll);
	if (g_d->images.fnsh)
		mlx_destroy_image(g_d->mlx, g_d->images.fnsh);
	if (g_d->images.win)
		mlx_destroy_image(g_d->mlx, g_d->images.win);
	if (g_d->images.lose)
		mlx_destroy_image(g_d->mlx, g_d->images.lose);
	mlx_destroy_window(g_d->mlx, g_d->wdw);
}

void	ft_init(t_data *g_d)
{
	g_d->mlx = NULL;
	g_d->wdw = NULL;
	g_d->c_state = NULL;
	g_d->images.cll = NULL;
	g_d->images.empty = NULL;
	g_d->images.enemy = NULL;
	g_d->images.fnsh = NULL;
	g_d->images.lose = NULL;
	g_d->images.pl2 = NULL;
	g_d->images.pl = NULL;
	g_d->images.wall = NULL;
	g_d->images.win = NULL;
}

int	ft_free(t_data *g_d, int return_value)
{
	int	i;

	if (g_d->c_state != NULL)
	{
		i = 0;
		while (g_d->c_state[i] != 0)
			free(g_d->c_state[i++]);
		free(g_d->c_state);
		g_d->c_state = NULL;
	}
	ft_cleanup(g_d);
	return (return_value);
}
