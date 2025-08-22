#include "cube.h"


void casting_rays(t_cube *data)
{
    double start;
    double i = 0;

    // printf("%d\n", data->width);
    start = data->angle - (data->fov / 2);
    // printf("%f  %f    %f\n", i, data->fov, start);
    while (i < data->width * WH)
    {
        draw_line(data, start +  i * (data->fov / (data->width * WH)));
        i++;
    }
}
