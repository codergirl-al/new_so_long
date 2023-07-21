/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_map_winnable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 09:42:34 by apeposhi          #+#    #+#             */
/*   Updated: 2023/06/25 17:34:17 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

char	**ft_copy_state(t_map *map, char **state_copy)
{
	char	**cp_state_copy;
	size_t	i;

	cp_state_copy = malloc(sizeof(char *) * (map->m_height + 1));
	cp_state_copy[map->m_height] = NULL;
	if (cp_state_copy == NULL)
	{
		ft_print_error("Malloc failed.\n", 1);
		return (NULL);
	}
	i = 0;
	while (i < map->m_height)
	{
		cp_state_copy[i] = malloc(sizeof(char) * (map->m_length + 1));
		if (!cp_state_copy[i])
		{
			while (i > 0 && cp_state_copy[--i])
				free(cp_state_copy[i]);
			free(cp_state_copy);
			ft_print_error("Malloc failed.\n", 1);
			return (NULL);
		}
		ft_strlcpy(cp_state_copy[i], state_copy[i], map->m_length + 1);
		i++;
	}
	return (cp_state_copy);
}

void	ft_check(size_t pl_y, size_t pl_x, t_map_cp *map, char **state_copy)
{
	*(state_copy[pl_y] + pl_x) = '1';
	if ((*(state_copy[pl_y] + pl_x + 1) == 'E')
		|| (*(state_copy[pl_y] + pl_x - 1) == 'E')
		|| (*(state_copy[pl_y + 1] + pl_x) == 'E')
		|| (*(state_copy[pl_y - 1] + pl_x) == 'E'))
		map->exit = 0;
	if (*(state_copy[pl_y] + pl_x + 1) == '0'
		|| (*(state_copy[pl_y] + pl_x + 1) == 'C' && --(map->col) >= 0))
		ft_check(pl_y, pl_x + 1, map, state_copy);
	if (*(state_copy[pl_y] + pl_x - 1) == '0'
		|| (*(state_copy[pl_y] + pl_x - 1) == 'C' && --(map->col) >= 0))
		ft_check(pl_y, pl_x - 1, map, state_copy);
	if (*(state_copy[pl_y + 1] + pl_x) == '0'
		|| (*(state_copy[pl_y + 1] + pl_x) == 'C' && --(map->col) >= 0))
		ft_check(pl_y + 1, pl_x, map, state_copy);
	if (*(state_copy[pl_y - 1] + pl_x) == '0'
		|| (*(state_copy[pl_y - 1] + pl_x) == 'C' && --(map->col) >= 0))
		ft_check(pl_y - 1, pl_x, map, state_copy);
}

int	ft_is_map_winnable(t_map *map, char **current_state)
{
	char		**state_copy;
	t_map_cp	map_cp;
	size_t		i;

	map_cp.exit = map->finish;
	map_cp.col = map->collectibles;
	state_copy = ft_copy_state(map, current_state);
	if (state_copy == NULL)
		return (ft_print_error("Malloc failed.\n", 1));
	ft_check(map->y_position, map->x_position, &map_cp, state_copy);
	i = 0;
	while (state_copy[i] != NULL)
		free(state_copy[i++]);
	free(state_copy);
	if (map_cp.exit != 0 || map_cp.col != 0)
		return (ft_print_error("not winable.\n", 1));
	return (0);
}
