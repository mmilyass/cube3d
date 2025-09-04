/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 10:12:43 by imeftah-          #+#    #+#             */
/*   Updated: 2025/09/04 10:47:37 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	load_texture_address(t_cube *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data->t_text.addr[i] = mlx_get_data_addr(data->t_text.textures[i],
				&data->t_text.bpp[i], &data->t_text.len[i],
				&data->t_text.endian[i]);
		i++;
	}
}

void	load_textures(t_cube *data)
{
	data->t_text.textures[0] = mlx_xpm_file_to_image(data->mlx,
			data->game->north_texture, &data->t_text.width[0],
			&data->t_text.height[0]);
	data->t_text.textures[1] = mlx_xpm_file_to_image(data->mlx,
			data->game->south_texture, &data->t_text.width[1],
			&data->t_text.height[1]);
	data->t_text.textures[2] = mlx_xpm_file_to_image(data->mlx,
			data->game->east_texture, &data->t_text.width[2],
			&data->t_text.height[2]);
	data->t_text.textures[3] = mlx_xpm_file_to_image(data->mlx,
			data->game->west_texture, &data->t_text.width[3],
			&data->t_text.height[3]);
	if (!data->t_text.textures[0] || !data->t_text.textures[1]
		|| !data->t_text.textures[2] || !data->t_text.textures[3])
		ft_exit(data);
	data->t_text.textures[4] = NULL;
	load_texture_address(data);
}

double	angle_direction(char direction)
{
	if (direction == 'N')
		return (270 * (M_PI / 180));
	if (direction == 'S')
		return (90 * (M_PI / 180));
	if (direction == 'E')
		return (0);
	else
		return (180 * (M_PI / 180));
}

void	initialize(t_cube *data)
{
	int	i;

	i = 0;
	data->map = data->game->map;
	while (data->map[data->height])
		data->height++;
	data->height--;
	data->fov = 60 * (M_PI / 180);
	data->angle = angle_direction(data->game->orientation_character);
	data->px = data->game->player_x * TILE;
	data->py = data->game->player_y * TILE;
	data->r_speed = 0.2 * (M_PI / 180);
	data->dis = ft_malloc(sizeof(t_dis_tools), ALLOC);
	data->mlx = mlx_init();
	load_textures(data);
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
}
