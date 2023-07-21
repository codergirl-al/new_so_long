/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:39:26 by apeposhi          #+#    #+#             */
/*   Updated: 2023/06/25 17:33:02 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	ft_hooks_x(t_data *game_data)
{
	ft_free(game_data, 1);
	exit(0);
	return (0);
}

int	ft_hooks(int keycode, t_data *game_data)
{
	if (keycode == 53)
		ft_hooks_x(game_data);
	if (keycode != 13 && keycode != 0 && keycode != 1 && keycode != 2)
		return (0);
	if (keycode == 13)
		ft_move_up(game_data);
	else if (keycode == 0)
		ft_move_left(game_data);
	else if (keycode == 1)
		ft_move_down(game_data);
	else if (keycode == 2)
		ft_move_right(game_data);
	ft_count_moves(game_data);
	return (0);
}
