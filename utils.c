/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:49:24 by apeposhi          #+#    #+#             */
/*   Updated: 2023/06/25 17:33:33 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	ft_print_error(char *message, int r_value)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	return (r_value);
}
