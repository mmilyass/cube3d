#include "cube.h"

int key_check(int key, void *ptr)
{
    double x;
    double y;
    t_cube *data = (t_cube *)ptr;
    if (key == XK_Right)
        data->angle -= 0.01;
    if (key == XK_Left)
        data->angle += 0.01;
    if (key == XK_w)
    {
        x = data->px + (MOVE * cos(data->angle));
        y = data->py + (MOVE * sin(data->angle));
    }
    if (key == XK_s)
    {
        x = data->px - (MOVE * cos(data->angle));
        y = data->py - (MOVE * sin(data->angle));
    }
    if (key == XK_d)
    {
        x = data->px + sin(data->angle) * MOVE;
        y = data->py - cos(data->angle) * MOVE;
    }
    if (key == XK_a)
    {
        x = data->px - sin(data->angle) * MOVE;
        y = data->py + cos(data->angle) * MOVE;
    }   
    if (check_colision(data, x, y) != -1)
    {
        data->px = x;
        data->py = y;
    }
    data->angle = normalizeAngle(data->angle);
    render_all(data);
    return 0;
}