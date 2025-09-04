/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 10:11:54 by imeftah-          #+#    #+#             */
/*   Updated: 2025/09/04 10:28:50 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	parsing(t_game *game, int ac, char **av)
{
	if (ac != 2)
		return (perror("Error\nYou should have the right parameters\n"), 1);
	if (check_file_name(av[1]) == 1)
		return (1);
	initialize_struct(game, av[1]);
	if (pars_map(game) == 1)
		return (1);
	return (0);
}

int	main(int ac, char *av[])
{
	t_cube	*data;
	t_game	*game;

	game = ft_malloc(sizeof(t_game), ALLOC);
	if (parsing(game, ac, av) == 1)
		return (1);
	data = ft_malloc(sizeof(t_cube), ALLOC);
	data->game = game;
	if (parsing(game, ac, av) == 1)
		ft_exit(data);
	initialize(data);
	render_all(data);
	mlx_hook(data->win, 17, 0, ft_exit, data);
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->win, 3, 1L << 1, key_release, data);
	mlx_loop_hook(data->mlx, key_check, data);
	mlx_loop(data->mlx);
}
