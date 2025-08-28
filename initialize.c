#include "cube.h"


int get_window_size(t_cube *data)
{
    int fd;
    char *buffer;
    int tmp;

    tmp = 0;
    fd = open("maps/map.ber", O_RDONLY);
    if (fd < 0)
        return ERROR;
    while (1)
    {
        buffer = get_next_line(fd);
        if (!buffer)
            break;
        tmp = ft_strlen(buffer);
        if (tmp > data->width)
            data->width = tmp;
        data->height++;
        free(buffer);
    }
    close(fd);
    return 0;
}

int store_map(t_cube *data)
{
    int fd;
    char *buffer;
    int i;

    i = 0;
    data->map = ft_malloc((data->height + 1) * sizeof(char *), ALLOC);
    fd = open("maps/map.ber", O_RDONLY);
    if (fd < 0)
        return ERROR;
    while (1)
    {
        buffer = get_next_line(fd);
        if (!buffer)
            break;
        data->map[i++] = buffer;
    }
    data->map[i] = NULL;
    close(fd);
    return 0;
}

t_cube *initialize()
{
    t_cube *data;
    data = ft_malloc(sizeof(t_cube), ALLOC);
    if (get_window_size(data) == ERROR)
        exit(errno);
    if (store_map(data) == ERROR)
        exit(errno);
    data->width -= 1;
    data->fov = 100 * (M_PI / 180);
    data->angle = 90 * (M_PI / 180);
    data->px = (data->width / 2) * TILE;
    data->py = (data->height / 2) * TILE;
    data->r_speed = 2 * (M_PI / 180);
    data->dis = ft_malloc(sizeof(t_dis_tools), ALLOC);
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, data->width * TILE, data->height * TILE, "cub3D");
    return (data);
}
