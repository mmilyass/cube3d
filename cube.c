#include "cube.h"

int get_window_size(t_cube *data)
{
    int fd;
    char *buffer;
    int tmp = 0;

    fd = open("map.ber", O_RDONLY);
    if (fd < 0)
        return ERROR;
    while (1)
    {
        buffer = get_next_line(fd);
        if (!buffer)
            break;
        lstaddback(&data->map, buffer);
        tmp = ft_strlen(buffer);
        if (tmp > data->width)
            data->width = tmp;
        data->height++;
    }
    close(fd);
    return 0;
}

void render_cube(t_cube *data, int y, int x)
{
    int start_y;
    int start_x;

    start_y = y;
    while (start_y < y + WH)
    {
        start_x = x;
        while (start_x < x + WH)
        {
            my_pixel_put(data, start_x, start_y, 0xFFFFFF);
            start_x++;
        }
        start_y++;
    }
}

void render_black(t_cube *data, int y, int x)
{
    int start_y;
    int start_x;

    start_y = y;
    while (start_y < y + WH)
    {
        start_x = x;
        while (start_x < x + WH)
        {
            my_pixel_put(data, start_x, start_y, 0x000000);
            start_x++;
        }
        start_y++;
    }
}

int render_map(t_cube *data)
{
    int i;
    int y = 0;
    t_map *current;

    current = data->map;
    while (current)
    {
        i = 0;
        while (current->row[i])
        {
            if (current->row[i] == '1')
                render_cube(data, y*WH, i*WH);
            else
                render_black(data, y*WH, i*WH);
            i++;
        }
        current = current->next;
        y++;
    }
    return 0;
}

int main()
{
    t_cube *data;
    data = initialize();
    render_all(data);
    mlx_hook(data->win, 2, 1L << 0, rotate_line, data);
    mlx_loop(data->mlx);
}
