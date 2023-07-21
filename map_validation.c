/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:59:35 by apeposhi          #+#    #+#             */
/*   Updated: 2023/07/21 17:58:05 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

static int	ft_check_middle(char c, t_data *g_d, size_t i, size_t j)
{
	if (j == 0 || j == g_d->map.m_length - 1) 
	{
		if (c != '1')
			return (ft_print_error("Wrong map layout given.\n", 1));
	}
	else
	{
		if (c != '1' && c != '0' && c != 'P' && \
				c != 'E' && c != 'C' && c != 'A')
			return (ft_print_error("Invalid map. Character not allowed!\n", 1));
		if (c == 'P')
		{
			g_d->map.player += 1;
			g_d->map.x_p = j;
			g_d->map.y_p = i;
		}
		if (c == 'E' && g_d->map.finish == 0)
			g_d->map.finish += 1;
		if (c == 'C')
			g_d->map.clls += 1;
	}
	return (0);
}

int	ft_check_map_data(t_map map)
{
	if (map.clls == 0)
		return (ft_print_error("Collectables are missing!\n", 1));
	if (map.finish != 1)
		return (ft_print_error("Exactly one E must be given.\n", 1));
	if (map.player != 1)
		return (ft_print_error("Exactly one P must be given.\n", 1));
	return (0);
}

static int	ft_check_map(char **c_state, t_data *g_d)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (c_state[i] != NULL)
	{
		j = 0;
		while (c_state[i][j] != '\0')
		{
			if (g_d->map.m_length != ft_strlen(c_state[i]))
				return (ft_print_error("Map doesn't have the right size.\n", 1));
			if (i == 0 || i + 1 == g_d->map.m_height)
			{
				if (c_state[i][j] != '1')
					return (ft_print_error("Wrong map layout given.\n", 1));
			}
			else
				if (ft_check_middle(c_state[i][j], g_d, i, j))
					return (1);
			j++;
		}
		i++;
	}
	return (ft_check_map_data(g_d->map));
}

static void	ft_init_map_data(t_map *map)
{
	map->clls = 0;
	map->finish = 0;
	map->player = 0;
}

int	ft_validate_map(t_data *g_d)
{
	ft_init_map_data(&g_d->map);
	if (ft_check_map(g_d->c_state, g_d))
		return (1);
	if (ft_is_map_winnable(&g_d->map, g_d->c_state))
		return (1);
	return (0);
}
