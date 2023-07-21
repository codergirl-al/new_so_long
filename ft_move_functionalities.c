/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_functionalities.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:27:34 by apeposhi          #+#    #+#             */
/*   Updated: 2023/06/17 16:45:04 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	ft_move_player(t_data *game_data, size_t x, size_t y)
{
	int			*s;
	t_images	*img;

	s = &game_data->image_size;
	img = &game_data->images;
	mlx_put_image_to_window(game_data->mlx, game_data->window, img->empty, game_data->map.x_position * *s, game_data->map.y_position * *s + 20);	
	mlx_put_image_to_window(game_data->mlx, game_data->window, img->player, x * *s, y * *s + 20);
	if (game_data->current_state[y][x] == 'C')
		game_data->map.collectibles = game_data->map.collectibles - 1;
	game_data->current_state[y][x] = 'P';
	game_data->current_state[ game_data->map.y_position][game_data->map.x_position] = '0';
	game_data->map.x_position = x;
	game_data->map.y_position = y;
}

int	ft_move_up(t_data *game_data)
{
	size_t	*x;
	size_t	*y;

	x = &game_data->map.x_position;
	y = &game_data->map.y_position;
	if (game_data->current_state[*y - 1][*x] == '1')
		return (0);
	else if (game_data->current_state[*y - 1][*x] == '0' || game_data->current_state[*y - 1][*x] == 'C')
	{
		ft_move_player(game_data, *x, *y - 1);
	}
	else if (game_data->current_state[*y - 1][*x] == 'A')
	{
		ft_move_player(game_data, *x, *y - 1);
		write(1, "lose\n", 5); // not done
		exit (ft_free(game_data, 0));
	}
	else if (game_data->current_state[*y - 1][*x] == 'E' && game_data->map.collectibles == 0)
	{
		ft_move_player(game_data, *x, *y - 1);
		write(1, "win\n", 4); 
		exit (ft_free(game_data, 0));
	}
	return (0);
}

int	ft_move_left(t_data *game_data)
{
	size_t	*x;
	size_t	*y;

	x = &game_data->map.x_position;
	y = &game_data->map.y_position;
	if (game_data->current_state[*y][*x - 1] == '1')
		return (0);
	else if (game_data->current_state[*y][*x - 1] == '0' || game_data->current_state[*y][*x - 1] == 'C')
	{
		ft_move_player(game_data, *x - 1, *y);
	}
	else if (game_data->current_state[*y][*x - 1] == 'A')
	{
		ft_move_player(game_data, *x - 1, *y);
		write(1, "lose\n", 5); // not done
		exit (ft_free(game_data, 0));
	}
	else if (game_data->current_state[*y][*x - 1] == 'E' && game_data->map.collectibles == 0)
	{
		ft_move_player(game_data, *x - 1, *y);
		write(1, "win\n", 4); 
		exit (ft_free(game_data, 0));
	}
	return (0);
}

int	ft_move_down(t_data *game_data)
{
	size_t	*x;
	size_t	*y;

	x = &game_data->map.x_position;
	y = &game_data->map.y_position;
	if (game_data->current_state[*y + 1][*x] == '1')
		return (0);
	else if (game_data->current_state[*y + 1][*x] == '0' || game_data->current_state[*y + 1][*x] == 'C')
	{
		ft_move_player(game_data, *x, *y + 1);
	}
	else if (game_data->current_state[*y + 1][*x] == 'A')
	{
		ft_move_player(game_data, *x, *y + 1);
		write(1, "lose\n", 5); // not done
		exit (ft_free(game_data, 0));
	}
	else if (game_data->current_state[*y + 1][*x] == 'E' && game_data->map.collectibles == 0)
	{
		ft_move_player(game_data, *x, *y + 1);
		write(1, "win\n", 4);
		exit (ft_free(game_data, 0));
	}
	return (0);
}

int	ft_move_right(t_data *game_data)
{
	size_t	*x;
	size_t	*y;

	x = &game_data->map.x_position;
	y = &game_data->map.y_position;
	if (game_data->current_state[*y][*x + 1] == '1')
		return (0);
	else if (game_data->current_state[*y][*x + 1] == '0' || game_data->current_state[*y][*x + 1] == 'C')
	{
		ft_move_player(game_data, *x + 1, *y);
	}
	else if (game_data->current_state[*y][*x + 1] == 'E' && game_data->map.collectibles == 0)
	{
		ft_move_player(game_data, *x + 1, *y);
		write(1, "win\n", 4); 
		exit (ft_free(game_data, 0));
	}
	else if (game_data->current_state[*y][*x + 1] == 'A')
	{
		ft_move_player(game_data, *x + 1, *y);
		write(1, "lose\n", 5); // not done
		exit (ft_free(game_data, 0));
	}
	return (0);
}
