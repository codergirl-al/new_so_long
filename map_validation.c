/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:59:35 by apeposhi          #+#    #+#             */
/*   Updated: 2023/06/17 11:13:55 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

static int	ft_check_middle(char c, t_data *game_data, size_t i, size_t j)
{
	if (j == 0 || j == game_data->map.m_length - 1) // checks that the 1. and last is a wall
	{
		if (c != '1')
			return(ft_print_error("Wrong map layout given.\n", 1));
	}
	else
	{
		if (c != '1' && c != '0' && c != 'P' && c != 'E' && c != 'C' && c != 'A')
			return(ft_print_error("Invalid map input given. Character not allowed!\n", 1));
		if (c == 'P')
		{
			game_data->map.player += 1;
			game_data->map.x_position = j;
			game_data->map.y_position = i;
		}
		if (c == 'E' && game_data->map.finish == 0)
			game_data->map.finish += 1;
		if (c == 'C')
			game_data->map.collectibles += 1;
	}
	return (0);
}

int	ft_check_map_data(t_map map)
{
	if (map.collectibles == 0)
		return (ft_print_error("Collectables are missing!\n", 1));
	if (map.finish != 1)
		return (ft_print_error("Exactly one E must be given.\n", 1));
	if (map.player != 1)
		return (ft_print_error("Exactly one P must be given.\n", 1));
	return (0);	
}

static int	ft_check_map(char **current_state, t_data *game_data)
{
	size_t i;
	size_t j;

	i = 0;
	while (current_state[i] != NULL)
	{
		j = 0;
		while (current_state[i][j] != '\0')
		{
			if (game_data->map.m_length != ft_strlen(current_state[i]))
				return(ft_print_error("Map doesn't have a rectangular shape.\n", 1));
			if (i == 0 || i + 1 == game_data->map.m_height)
			{
				if (current_state[i][j] != '1')
					return(ft_print_error("Wrong map layout given.\n", 1));
			}
			else
				if (ft_check_middle(current_state[i][j], game_data, i, j))
					return (1);
			j++;
		}
		i++;
	}
	return (ft_check_map_data(game_data->map));
}

static void	ft_init_map_data(t_map *map)
{
	map->collectibles = 0;
	map->finish = 0;
	map->player = 0;
}

int	ft_validate_map(t_data *game_data)
{
	ft_init_map_data(&game_data->map);
	if (ft_check_map(game_data->current_state, game_data))
		return (1);
	if (ft_is_map_winnable(&game_data->map, game_data->current_state))
		return (1);
	return (0);
}