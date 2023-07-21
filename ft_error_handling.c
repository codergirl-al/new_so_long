/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 10:24:31 by apeposhi          #+#    #+#             */
/*   Updated: 2023/06/26 12:26:24 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h" 

void	ft_cleanup(t_data *game_data)
{

	mlx_clear_window(game_data->mlx, game_data->window); 		//FIX UR FUCKING SEGFAULT
	if (game_data->images.player)
		mlx_destroy_image(game_data->mlx, game_data->images.player);
	if (game_data->images.player2)
		mlx_destroy_image(game_data->mlx, game_data->images.player2);
	if (game_data->images.enemy)
		mlx_destroy_image(game_data->mlx, game_data->images.enemy);
	if (game_data->images.wall)
		mlx_destroy_image(game_data->mlx, game_data->images.wall);
	if (game_data->images.empty)
		mlx_destroy_image(game_data->mlx, game_data->images.empty);
	if (game_data->images.collectible)
		mlx_destroy_image(game_data->mlx, game_data->images.collectible);
	if (game_data->images.finish)
		mlx_destroy_image(game_data->mlx, game_data->images.finish);
	if (game_data->images.win)
		mlx_destroy_image(game_data->mlx, game_data->images.win);
	if (game_data->images.lose)
		mlx_destroy_image(game_data->mlx, game_data->images.lose);
	mlx_destroy_window(game_data->mlx, game_data->window);
}

void	ft_init(t_data *game_data)
{
	game_data->mlx = NULL;
	game_data->window = NULL;
	game_data->current_state = NULL;
	game_data->images.collectible = NULL;
	game_data->images.empty = NULL;
	game_data->images.enemy = NULL;
	game_data->images.finish = NULL;
	game_data->images.lose = NULL;
	game_data->images.player2 = NULL;
	game_data->images.player = NULL;
	game_data->images.wall = NULL;
	game_data->images.win = NULL;
}

int	ft_free(t_data *game_data, int return_value)
{
	int	i;

	if (game_data->current_state != NULL)
	{
		i = 0;
		while (game_data->current_state[i] != 0)
			free(game_data->current_state[i++]);
		free(game_data->current_state);
		game_data->current_state = NULL;
	}
	ft_cleanup(game_data);
	return (return_value);
}
