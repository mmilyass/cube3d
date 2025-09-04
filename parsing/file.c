/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 10:03:29 by oboussel          #+#    #+#             */
/*   Updated: 2025/09/04 10:17:53 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	parse_color(char *str)
{
	char	**color_array;
	int		c0;
	int		c1;
	int		c2;
	int		color;

	color_array = ft_split(str, ',');
	if (color_array == NULL)
		return (perror("Error\nInvalid color format\n"), -1);
	if (color_array[0] == NULL || color_array[1] == NULL
		|| color_array[2] == NULL || color_array[3] != NULL)
		return (free_double_ptr(color_array),
			perror("Error\nInvalid color format\n"), -1);
	c0 = ft_atoi(color_array[0]);
	c1 = ft_atoi(color_array[1]);
	c2 = ft_atoi(color_array[2]);
	if (c0 < 0 || c0 > 255 || c1 < 0 || c1 > 255 || c2 < 0 || c2 > 255)
		return (free_double_ptr(color_array),
			perror("Error\nInvalid color value"), -1);
	color = (c0 << 16) | (c1 << 8) | c2;
	free_double_ptr(color_array);
	return (color);
}

int	pars_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (open_file(game) == 1)
		return (1);
	read_map(game);
	if (fill_informations(game) == 1)
		return (1);
	if (check_empty_lines_map(game) == 1)
		return (1);
	if (check_surrounded_walls(game) == 1)
		return (1);
	if (check_holes(game, i, j) == 1)
		return (1);
	if (check_characters(game) == 1)
		return (1);
	return (0);
}

int	check_file_name(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4 || ft_strcmp((filename + len - 4), ".cub") != 0)
	{
		perror("Error\nFile name should end with: .cub\n");
		return (1);
	}
	return (0);
}

void	initialize_struct(t_game *game, char *filename)
{
	ft_bzero(game, sizeof(t_game));
	game->floor_color = -1;
	game->ceiling_color = -1;
	game->map_file_name = filename;
}
