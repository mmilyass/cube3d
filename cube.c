#include "cube.h"

void put_square(void *mlx, void *win, int yy, int xx)
{
    int y;
    int x;
    int tx;
    int ty;

    y = yy * 32;
    ty = y + 32;
    tx = (xx * 32) + 32;
    while (y < ty)
    {
        x = xx * 32;
        while(x < tx)
        {
            mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
            x++;
        }
        y++;
    }
}

int main()
{
    void *mlx;
    void *win;
    int x;
    int y = 0;
    int map[10][20] = {
        {1,1,1,1,1,1,1,1,},
        {1,0,0,0,0,0,0,1,},
        {1,0,1,0,1,0,0,1,},
        {1,0,1,0,1,0,0,1,},
        {1,0,0,0,0,0,0,1,},
        {1,0,1,1,1,1,0,1,},
        {1,0,0,0,0,0,0,1,},
        {1,0,0,0,0,0,0,1,},
        {1,0,0,0,0,0,0,1,},
        {1,1,1,1,1,1,1,1,}
    };
    mlx = mlx_init();
    win = mlx_new_window(mlx, 20 * 32, 10 * 32, "ilyass");
    while (y < 10)
    {
        x = 0;
        while (x < 20)
        {
            if (map[y][x] == 1)
            {
                printf("%d   %d\n", y, x);
                put_square(mlx, win, y, x);
            }
            x++;
        }
        y++;
    }
    mlx_loop(mlx);
}