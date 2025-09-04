/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 10:03:32 by oboussel          #+#    #+#             */
/*   Updated: 2025/09/01 18:54:37 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	check_empty_lines_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (game->map[i][0] == '\0')
			return (perror("Error\nEmpty line in the map\n"), 1);
		i++;
	}
	return (0);
}

int	check_holes(t_game *game, int i, int j)
{
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (player_or_zero(game->map[i][j]) == 1)
			{
				if (i == 0 || j >= (int)ft_strlen(game->map[i - 1])
					|| game->map[i - 1][j] == ' ')
					return (perror("Error\nMap is not closed\n"), 1);
				if (game->map[i + 1] == NULL || j >= (int)ft_strlen(game->map[i
							+ 1]) || game->map[i + 1][j] == ' ')
					return (perror("Error\nMap is not closed\n"), 1);
				if (j == 0 || game->map[i][j - 1] == ' ')
					return (perror("Error\nMap is not closed\n"), 1);
				if (game->map[i][j + 1] == '\0' || game->map[i][j + 1] == ' ')
					return (perror("Error\nMap is not closed\n"), 1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_first_last_row(t_game *game, int last_row)
{
	int	i;

	i = 0;
	while (game->map[0][i])
	{
		if (game->map[0][i] != '1' && game->map[0][i] != ' ')
			return (perror("Error\nMap not surrounded by walls\n"), 1);
		i++;
	}
	i = 0;
	while (game->map[last_row][i])
	{
		if (game->map[last_row][i] != '1' && game->map[last_row][i] != ' ')
			return (perror("Error\nMap not surrounded by walls\n"), 1);
		i++;
	}
	return (0);
}

int	check_surrounded_walls(t_game *game)
{
	int	i;
	int	last_row;

	i = 0;
	last_row = 0;
	while (game->map[last_row])
		last_row++;
	last_row--;
	if (check_first_last_row(game, last_row) == 1)
		return (1);
	while (game->map[i])
	{
		if (game->map[i][0] != '1' && game->map[i][0] != ' ')
			return (perror("Error\nMap not surrounded by walls\n"), 1);
		i++;
	}
	i = 0;
	while (game->map[i])
	{
		if (game->map[i][ft_strlen(game->map[i]) - 1] != '1'
			&& game->map[i][ft_strlen(game->map[i]) - 1] != ' ')
			return (perror("Error\nMap not surrounded by walls\n"), 1);
		i++;
	}
	return (0);
}
