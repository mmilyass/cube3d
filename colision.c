#include "cube.h"

void my_pixel_put(t_cube *d, int x, int y, unsigned int color)
{
    if (x < 0 || x >= d->width * WH || y < 0 || y >= d->height * WH)
        return;

    if (!d->addr)
        return;
    char *dst;

    dst = d->addr + (y * d->line_len + x * (d->bpp / 8));
    *(unsigned int *)dst = color;
}

int check_colisionn(t_cube *data, int x, int y)
{
    int i = 0;
    int j = 0;
    t_map *current;

    current = data->map;
    while (current)
    {
        i = 0;
        while (current->row[i])
        {
            if (current->row[i] == '1')
            {
                if ((x >= i * WH && x <= (i * WH) + WH) &&
                    (y >= j * WH && y <= (j + 1) * WH))
                    return -1;
            }
            i++;
        }
        j++;
        current = current->next;
    }
    return 0;
}

void draw_line(t_cube *data, double angle)
{
    int i = 0;
    int x;
    int y;
    while (1)
    {
        x = data->px + (i * cos(angle));
        y = data->py + (i * sin(angle));
        my_pixel_put(data, x, y, 0xFF0000);
        if (check_colisionn(data, x, y) == -1)
            break;
        i++;
    }

}


void render_all(t_cube *data)
{
    render_map(data);
    casting_rays(data);
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int check_colision(t_cube *data)
{
    int i = 0;
    int j = 0;
    t_map *current;

    current = data->map;
    while (current)
    {
        i = 0;
        while (current->row[i])
        {
            if (current->row[i] == '1')
            {
                if ((data->pxt >= i * WH && data->pxt <= (i * WH) + WH) &&
                    (data->pyt >= j * WH && data->pyt <= (j + 1) * WH))
                    return -1;
            }
            i++;
        }
        j++;
        current = current->next;
    }
    return 0;
}

int rotate_line(int keycode, void *data)
{
    t_cube *dita;
    dita = (t_cube *)data;

    if (keycode == XK_Right)
    {
        dita->angle -= dita->r_speed;
        render_all(data);
    }
    else if (keycode == XK_Left)
    {
        dita->angle += dita->r_speed;
        render_all(data);
    }
    else if (keycode == XK_d)
    {
        dita->pxt = dita->px + MOVE_SPEED;
        dita->pyt = dita->py;
        if (check_colision(data) != -1)
        {
            dita->px = dita->pxt;
            render_all(data);
        }
    }
    else if (keycode == XK_a)
    {
        dita->pxt = dita->px - MOVE_SPEED;
        dita->pyt = dita->py;
        if (check_colision(data) != -1)
        {
            dita->px = dita->pxt;
            render_all(data);
        }
    }
    else if (keycode == XK_w)
    {
        dita->pxt = dita->px + cos(dita->angle) * MOVE_SPEED;
        dita->pyt = dita->py - sin(dita->angle) * MOVE_SPEED;
        if (check_colision(data) != -1)
        {
            dita->px = dita->pxt;
            dita->py = dita->pyt;
            render_all(data);
        }
    }
    else if (keycode == XK_s)
    {
        dita->pxt = dita->px - cos(dita->angle) * MOVE_SPEED;
        dita->pyt = dita->py + sin(dita->angle) * MOVE_SPEED;
        if (check_colision(data) != -1)
        {
            dita->px = dita->pxt;
            dita->py = dita->pyt;
            render_all(data);
        }
    }
    return 0;
}
