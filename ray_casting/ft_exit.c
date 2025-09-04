/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 10:56:09 by imeftah-          #+#    #+#             */
/*   Updated: 2025/09/04 10:19:12 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	destroy_textures(t_cube *data)
{
	int	i;

	i = 0;
	while (data->t_text.textures[i])
		mlx_destroy_image(data->mlx, data->t_text.textures[i++]);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

int	ft_exit(t_cube *data)
{
	if (data->mlx)
	{
		if (data->img)
			mlx_destroy_image(data->mlx, data->img);
		destroy_textures(data);
		if (data->win)
			mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
	}
	free(data->mlx);
	ft_malloc(0, FREE);
	exit(errno);
	return (0);
}
