/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:39:26 by apeposhi          #+#    #+#             */
/*   Updated: 2023/07/21 17:40:00 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	ft_hooks_x(t_data *g_d)
{
	ft_free(g_d, 1);
	exit(0);
	return (0);
}

int	ft_hooks(int keycode, t_data *g_d)
{
	if (keycode == 53)
		ft_hooks_x(g_d);
	if (keycode != 13 && keycode != 0 && keycode != 1 && keycode != 2)
		return (0);
	if (keycode == 13)
		ft_move_up(g_d);
	else if (keycode == 0)
		ft_move_left(g_d);
	else if (keycode == 1)
		ft_move_down(g_d);
	else if (keycode == 2)
		ft_move_right(g_d);
	ft_count_moves(g_d);
	return (0);
}
