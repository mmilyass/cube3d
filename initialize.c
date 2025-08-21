#include "cube.h"

t_cube *initialize()
{
    t_cube *data;
    data = ft_malloc(sizeof(t_cube), ALLOC);
    if (get_window_size(data) == ERROR)
        exit(errno);
    data->width -= 1;
    data->fov = 60 * (M_PI / 180);
    data->angle = 0 * (M_PI / 180);
    data->px = (data->width / 2) * WH;
    data->py = (data->height / 2) * WH;
    data->r_speed = 2 * (M_PI / 180);
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, data->width * WH, data->height * WH, "cub3D");
    data->img = mlx_new_image(data->mlx, data->width * WH, data->height * WH);
    data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_len, &data->endian);
    return (data);
}