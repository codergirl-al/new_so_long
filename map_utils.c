/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:40:53 by apeposhi          #+#    #+#             */
/*   Updated: 2023/07/21 18:28:11 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	ft_count_moves(t_data *g_d)
{
	static int	count = 0;
	char		*output;

	output = ft_itoa(count);
	if (!output)
		exit(ft_free(g_d, ft_print_error("malloc failed", 1)));
	mlx_string_put(g_d->mlx, g_d->window, 52, 15, 0x00000000, output);
	free (output);
	output = ft_itoa(++count);
	if (!output)
		exit(ft_free(g_d, ft_print_error("malloc failed", 1)));
	mlx_string_put(g_d->mlx, g_d->window, 52, 15, 0x00FF0000, output);
	free (output);
	return (0);
}

static int	ft_count_lines(char *map, t_data *g_d)
{
	size_t	lines;
	int		fd;
	char	*current_line;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (ft_print_error("Couldn't open map file.\n", -1));
	lines = 0;
	current_line = get_next_line(fd);
	if (current_line)
		g_d->map.m_length = ft_strlen(current_line) - 1;
	while (current_line)
	{
		lines++;
		free(current_line);
		current_line = get_next_line(fd);
	}
	g_d->map.m_height = lines;
	close(fd);
	return (lines);
}

char	**ft_handle_return(void)
{
	ft_print_error("Couldn't open map file.\n", 1);
	return (NULL);
}

static char	**ft_get_map_data(char *map, int fd, t_data *g_d)
{
	char	**map_state;
	int		i;
	int		lines;

	lines = ft_count_lines(map, g_d);
	if (lines == -1)
	{
		return (ft_handle_return());
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

int	ft_read_map(t_data *g_d, char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (!fd)
		return (ft_print_error("Couldn't open map file.\n", 1));
	g_d->c_state = ft_get_map_data(map, fd, g_d);

	if (g_d->c_state == NULL)
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}
