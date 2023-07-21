/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:07:48 by apeposhi          #+#    #+#             */
/*   Updated: 2023/06/26 15:35:57 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"
// #include "../MLX42/include/MLX42/MLX42.h"

int	validate_args(int argc, char **argv)
{
	char	*location;
	int		fd;

	if (argc != 2)
	{
		if (argc == 1)
			write(2, "Error\nNo map entered.\n", 22); // change 
		else
			write(2, "Error\nToo many arguments.\n", 26); // change 
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
	t_data	game_data;

	ft_init(&game_data);
	if (validate_args(argc, argv))
		return (1);
	if (ft_read_map(&game_data, argv[1]))
		return (ft_free(&game_data, 1));
	if (ft_validate_map(&game_data))
		return (ft_free(&game_data, 1)); // map is good now

	if (ft_initialize(&game_data))
		return (ft_free(&game_data, 1));
	
	// function:	run the game

	printf("%zu\n", game_data.map.collectibles);
	mlx_hook(game_data.window, 2, 1L << 0, ft_hooks, &game_data);
	mlx_hook(game_data.window, 17, 1L << 0, ft_hooks_x, &game_data);
	mlx_loop_hook(game_data.mlx, ft_animate, (void *)&game_data);
	mlx_loop(game_data.mlx);
	return (ft_free(&game_data, 0));
}
