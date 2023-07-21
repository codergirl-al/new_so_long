/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:40:53 by apeposhi          #+#    #+#             */
/*   Updated: 2023/06/17 15:23:33 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	ft_count_moves(t_data *game_data)
{
	static int	count = 0;
	char		*output;
	
	output = ft_itoa(count);
	if (!output)
		exit(ft_free(game_data, ft_print_error("malloc failed", 1)));
	mlx_string_put(game_data->mlx, game_data->window, 52, 15, 0x00000000, output);
	free (output);

	output = ft_itoa(++count);
	if (!output)
		exit(ft_free(game_data, ft_print_error("malloc failed", 1)));
	mlx_string_put(game_data->mlx, game_data->window, 52, 15, 0x00FF0000, output);
	free (output);
	return (0);
}

static int	ft_count_lines(char *map, t_data *game_data)
{
	size_t lines;
	int fd;
	char *current_line;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (ft_print_error("Couldn't open map file.\n", -1));
	lines = 0;
	current_line = get_next_line(fd);
	if (current_line)
		game_data->map.m_length = ft_strlen(current_line) - 1;
	while (current_line)
	{
		lines++;
		free(current_line);
		current_line = get_next_line(fd);
	}
	game_data->map.m_height = lines;
	close(fd);
	return (lines);
}

static char **ft_get_map_data(char *map, int fd, t_data *game_data)
{
	char **map_state;
	int	i;
	int	lines;

	lines = ft_count_lines(map, game_data);
	if (lines == -1)
	{
		ft_print_error("Couldn't open map file.\n", 1);
		return (NULL);
	}
	map_state = malloc(sizeof(char *) * lines + 1);
	if (!map_state)
	{
		ft_print_error("Malloc failed whilst reading map data.\n", 1);
		return (NULL);
	}
	i = 0;
	while (i < lines)
	{
		map_state[i] = get_next_line(fd);
		if (map_state[i][ft_strlen(map_state[i]) - 1] == '\n')
			map_state[i][ft_strlen(map_state[i]) - 1] = '\0';
		i++;
	}
	map_state[i] = NULL;
	return (map_state);
}

int	ft_read_map(t_data *game_data, char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (!fd)
		return (ft_print_error("Couldn't open map file.\n", 1));
	game_data->current_state = ft_get_map_data(map, fd, game_data);

	if (game_data->current_state == NULL)
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}