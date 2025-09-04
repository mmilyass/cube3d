/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 10:03:26 by oboussel          #+#    #+#             */
/*   Updated: 2025/09/01 18:56:18 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static int	is_config_line(char *line)
{
	int	j;

	j = 0;
	while (line[j] == ' ')
		j++;
	if (ft_strncmp(line + j, "NO ", 3) == 0 || ft_strncmp(line + j, "SO ",
			3) == 0 || ft_strncmp(line + j, "WE ", 3) == 0 || ft_strncmp(line
			+ j, "EA ", 3) == 0 || ft_strncmp(line + j, "F ", 2) == 0
		|| ft_strncmp(line + j, "C ", 2) == 0)
		return (1);
	return (0);
}

static void	handle_map_line(t_game *game, int *map_found, int i)
{
	if (*map_found == 0)
	{
		*map_found = 1;
		game->line_map = i;
	}
}

static void	exit_with_error(char *msg, char *line)
{
	perror(msg);
	free(line);
	exit(1);
}

static void	process_line(t_game *game, char *line, int *map_found, int i)
{
	if (ft_strlen(line) > 1)
	{
		if (is_config_line(line))
		{
			if (*map_found == 1)
				exit_with_error("Error\nMap should be the last element\n",
					line);
		}
		else
		{
			if (!is_valid_map_line(line))
				exit_with_error("Error\nInvalid character in the file\n", line);
			handle_map_line(game, map_found, i);
		}
	}
}

void	number_of_lines(t_game *game)
{
	char	*line;
	int		i;
	int		map_found;

	i = 0;
	map_found = 0;
	line = get_next_line(game->fd);
	while (line)
	{
		i++;
		game->number_lines++;
		process_line(game, line, &map_found, i);
		free(line);
		line = get_next_line(game->fd);
	}
	if (game->line_map == 0)
	{
		perror("Error\nNo map provided\n");
		exit(0);
	}
	lseek(game->fd, 0, SEEK_SET);
}
