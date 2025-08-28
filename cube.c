#include "cube.h"

int main()
{
    t_cube *data;
    data = initialize();
    render_all(data);
    mlx_hook(data->win, 2, 1L << 0, key_check, data);
    mlx_loop(data->mlx);
}
