#include "cube.h"

void render_cube(t_cube *data, int y, int x)
{
    int start_y;
    int start_x;

    start_y = y;
    while (start_y < y + TILE)
    {
        start_x = x;
        while (start_x < x + TILE)
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
    while (start_y < y + TILE)
    {
        start_x = x;
        while (start_x < x + TILE)
        {
            if (start_y == y || start_x == x || start_x + 1 == x + TILE || start_y + 1 == y + TILE)
                my_pixel_put(data, start_x, start_y, 0xFFFFFF);
            else    
                my_pixel_put(data, start_x, start_y, 0x000000);
            
            start_x++;
        }
        start_y++;
    }
}

int render_2Dmap(t_cube *data)
{
    int x;
    int y;

    y = 0;
    while (data->map[y])
    {
        x = 0;
        while (data->map[y][x])
        {
            if (data->map[y][x] == '1')
                render_cube(data, y * TILE, x * TILE);
            else
                render_black(data, y * TILE, x * TILE);
            x++;
        }
        y++;
    }
    return 0;
}
