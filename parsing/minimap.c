#include "../cube.h"

void	draw_rectangle(t_cube *data, int pos_drawing_x, int pos_drawing_y,
		int width, int height, int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < height)
	{
		i = 0;
		while (i < width)
		{
			if (((j == 0 && color == 0x000000) || i == 0) && color != 0xFF0000)
			{
				mlx_pixel_put(data->mlx, data->win, pos_drawing_x + i,
					pos_drawing_y + j, 0xFFFFFF);
			}
			else
				mlx_pixel_put(data->mlx, data->win, pos_drawing_x + i,
					pos_drawing_y + j, color);
			i++;
		}
		j++;
	}
}

void	mini_map(t_cube *data)
{
	int i, j, map_i, map_j, player_x, player_y, tile_size, start_i, start_j,
		draw_x, draw_y, player_draw_x, player_draw_y;
	j = 0;
	tile_size = 12;
	player_x = data->px / TILE;
	player_y = data->py / TILE;
	start_i = player_x - 4;
	start_j = player_y - 4;
	while (j < 9)
	{
		map_j = start_j + j;
		if (map_j < 0 || map_j >= data->height)
		{
			j++;
			continue ;
		}
		i = 0;
		while (i < 9)
		{
			map_i = start_i + i;
			if (map_i < 0 || map_i >= (int)ft_strlen(data->map[0]))
			{
				i++;
				continue ;
			}
			draw_x = i * tile_size;
			draw_y = j * tile_size;
			if (player_or_zero(data->map[map_j][map_i]) == 1)
				draw_rectangle(data, draw_x, draw_y, tile_size, tile_size,
					0xFFFFFF);
			else
				draw_rectangle(data, draw_x, draw_y, tile_size, tile_size,
					0x000000);
			i++;
		}
		j++;
	}
	player_draw_x = (4 * tile_size) + (tile_size / 2);
	player_draw_y = (4 * tile_size) + (tile_size / 2);
	draw_rectangle(data, player_draw_x, player_draw_y, 4, 4, 0xFF0000);
}

// Then add player position
// Finally add player direction (typically as an arrow or cone)