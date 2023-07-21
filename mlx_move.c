/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:06:57 by apeposhi          #+#    #+#             */
/*   Updated: 2023/07/21 17:44:42 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	ft_move(t_data *g_d, int i)
{
	if (i == 0)
	{
		mlx_put_image_to_window(g_d->mlx, g_d->window, g_d->images.empty,
			(g_d->map.x_p) * 64, (g_d->map.y_p) * 64 + 20);
		mlx_put_image_to_window(g_d->mlx, g_d->window, g_d->images.player,
			(g_d->map.x_p) * 64, (g_d->map.y_p) * 64 + 20);
	}
	else if (i == 2000)
	{
		mlx_put_image_to_window(g_d->mlx, g_d->window, g_d->images.empty,
			(g_d->map.x_p) * 64, (g_d->map.y_p) * 64 + 20);
		mlx_put_image_to_window(g_d->mlx, g_d->window, g_d->images.player2,
			(g_d->map.x_p) * 64, (g_d->map.y_p) * 64 + 20);
		// check for enemy hitting
	}
}

int	ft_animate(t_data *g_d)
{
	static int	i = 0;
	static int	j = 0;

	if (g_d->map.player == 0)
		return (0);
	if (i == 0 || i == 2000)
	{
		ft_move(g_d, i);
		if (i == 0)
			j = 0;
		else
			j = 1;
	}
	if (j == 0)
		i++;
	else
		i--;
	return (0);
}
