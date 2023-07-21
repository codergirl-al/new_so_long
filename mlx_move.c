/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:06:57 by apeposhi          #+#    #+#             */
/*   Updated: 2023/06/17 15:25:56 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	ft_move(t_data *game_data, int i)
{
	if (i == 0)
	{
		mlx_put_image_to_window(game_data->mlx, game_data->window, game_data->images.empty,
			(game_data->map.x_position) * 64, (game_data->map.y_position) * 64 + 20);
		mlx_put_image_to_window(game_data->mlx, game_data->window, game_data->images.player,
			(game_data->map.x_position) * 64, (game_data->map.y_position) * 64 + 20);
	}
	else if (i == 2000)
	{
		mlx_put_image_to_window(game_data->mlx, game_data->window, game_data->images.empty,
			(game_data->map.x_position) * 64, (game_data->map.y_position) * 64 + 20);
		mlx_put_image_to_window(game_data->mlx, game_data->window, game_data->images.player2,
			(game_data->map.x_position) * 64, (game_data->map.y_position) * 64 + 20);
		// check for enemy hitting
	}
}

int	ft_animate(t_data *game_data)
{
	static int	i = 0;
	static int	j = 0;

	if (game_data->map.player == 0)
		return (0);
	if (i == 0 || i == 2000)
	{
		ft_move(game_data, i);
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
