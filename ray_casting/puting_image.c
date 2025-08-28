#include "../cube.h"

void my_pixel_put(t_cube *data, int x, int y, unsigned int color)
{
    char *dst;

    if (x < 0 || x >= data->width * TILE || y < 0 || y >= data->height * TILE)
        return;
    dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
    *(unsigned int *)dst = color;
}

void draw_wall(t_cube *data, int x)
{
    int y;
    int i;

    i = 0;
    y = ((data->height * TILE) / 2) - (data->WallStripH / 2);
    while (i < data->WallStripH)
    {
        if (y >= 0 && y < data->height * TILE)
            my_pixel_put(data, x, y, 0xFFFFFF);
        y++;
        i++;
    }
}

void draw_fov(t_cube *data)
{
    double start;
    double angle_step;
    int i = 0;

    start = data->angle - (data->fov / 2);
    angle_step = data->fov / (data->width * TILE);
    while (i < data->width * TILE)
    {
        wallStripHeight(data, start);
        draw_wall(data, i);
        start += angle_step;
        i++;
    }
}


void render_all(t_cube *data)
{
    if (data->img)
        mlx_destroy_image(data->mlx, data->img);
    data->img = mlx_new_image(data->mlx, data->width * TILE, data->height * TILE);
    data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_len, &data->endian);
    draw_fov(data);
    // render_2Dmap(data);                                              // those for the 2D projection demenstration .
    // printf("--> %f    x-->%f   y-->%f \n\n", data->angle, data->px, data->py);  //
    // ray_casting(data);       //
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}