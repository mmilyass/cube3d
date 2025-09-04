/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboussel <oboussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 10:02:40 by oboussel          #+#    #+#             */
/*   Updated: 2025/09/02 15:24:59 by oboussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	check_color(t_game *game, char *line, int i, char *trimmed)
{
	if (ft_strncmp(game->map_informations[i], "EA ", 3) == 0)
	{
		if (game->east_texture != NULL)
			return (perror("Error\nDuplicate east texture\n"), 1);
		game->east_texture = ft_strtrim(line + 3);
	}
	else if (ft_strncmp(game->map_informations[i], "F ", 2) == 0)
	{
		if (game->floor_color != -1)
			return (perror("Error\nDuplicate floor color\n"), 1);
		trimmed = ft_strtrim(line + 2);
		game->floor_color = parse_color(trimmed);
	}
	else if (ft_strncmp(game->map_informations[i], "C ", 2) == 0)
	{
		if (game->ceiling_color != -1)
			return (perror("Error\nDuplicate ceiling color\n"), 1);
		trimmed = ft_strtrim(line + 2);
		game->ceiling_color = parse_color(trimmed);
	}
	else if (ft_strlen(line) > 0)
		return (perror("Error\nInvalid information\n"), 1);
	return (0);
}

int	check_textures(t_game *game, char *line, int i, char *trimmed)
{
	if (ft_strncmp(game->map_informations[i], "NO ", 3) == 0)
	{
		if (game->north_texture != NULL)
			return (perror("Error\nDuplicate north texture\n"), 1);
		game->north_texture = ft_strtrim((line + 3));
	}
	else if (ft_strncmp(game->map_informations[i], "SO ", 3) == 0)
	{
		if (game->south_texture != NULL)
			return (perror("Error\nDuplicate south texture\n"), 1);
		game->south_texture = ft_strtrim(line + 3);
	}
	else if (ft_strncmp(game->map_informations[i], "WE ", 3) == 0)
	{
		if (game->west_texture != NULL)
			return (perror("Error\nDuplicate west texture\n"), 1);
		game->west_texture = ft_strtrim(line + 3);
	}
	else
	{
		if (check_color(game, line, i, trimmed) == 1)
			return (1);
	}
	return (0);
}

int	fill_informations(t_game *game)
{
	int		i;
	char	*line;
	char	*trimmed;
	char	**split;

	i = 0;
	trimmed = NULL;
	while (game->map_informations[i])
	{
		line = game->map_informations[i];
		if (ft_strlen(line) > 0)
		{
			split = ft_split(line, ' ');
			if (split[0] == NULL || split[1] == NULL || split[2] != NULL)
				return (perror("Error\nConfiguration wrong format\n"), 1);
		}
		free_double_ptr(split);
		split = NULL;
		if (check_textures(game, line, i, trimmed) == 1)
			return (1);
		i++;
	}
	if (!game->north_texture || !game->south_texture || !game->west_texture
		|| !game->east_texture || game->floor_color == -1
		|| game->ceiling_color == -1)
		return (perror("Error\nMissing required configuration\n"), 1);
	return (0);
}
