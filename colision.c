#include "cube.h"

int check_colision(t_cube *data, int px, int py)
{
    int map_x = px / TILE;  // which column
    int map_y = py / TILE;  // which row

    if (map_y < 0 || map_y >= data->height ||
        map_x < 0 || map_x >= data->width)
        return ERROR; // outside map = collision

    if (data->map[map_y][map_x] == '1')
        return ERROR; // collided with wall

    return 0; // no collision
}



