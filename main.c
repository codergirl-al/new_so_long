/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:07:48 by apeposhi          #+#    #+#             */
/*   Updated: 2023/07/21 21:25:50 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	validate_args(int argc, char **argv)
{
	char	*location;
	int		fd;

	if (argc != 2)
	{
		if (argc == 1)
			write(2, "Error\nNo map entered.\n", 22);
		else
			write(2, "Error\nToo many arguments.\n", 26);
		return (1);
	}
	location = ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]));
	if (location == NULL || location[4] != '\0')
		return (ft_print_error("Type has to be a .ber file.\n", 1));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_print_error("Unable to open map.\n", 1));
	close(fd);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	g_d;

	ft_init(&g_d);
	if (validate_args(argc, argv))
		return (1);
	if (ft_read_map(&g_d, argv[1]))
		return (ft_free(&g_d, 1));
	if (ft_validate_map(&g_d))
		return (ft_free(&g_d, 1));
	if (ft_initialize(&g_d))
		return (ft_free(&g_d, 1));
	printf("%zu\n", g_d.map.clls);
	mlx_hook(g_d.wdw, 2, 1L << 0, ft_hooks, &g_d);
	mlx_hook(g_d.wdw, 17, 1L << 0, ft_hooks_x, &g_d);
	mlx_loop_hook(g_d.mlx, ft_animate, (void *)&g_d);
	mlx_loop(g_d.mlx);
	return (ft_free(&g_d, 0));
}
