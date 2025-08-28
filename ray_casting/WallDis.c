#include "../cube.h"

void horizontal_gridline(t_cube *data)
{
    data->dis->Ahx = data->px;
    data->dis->Ahy = data->py;
    data->dis->xhstep = INFINITY;
    data->dis->yhstep = INFINITY;
}

void vertical_gridline(t_cube *data)
{
    data->dis->Avx = data->px;
    data->dis->Avy = data->py;
    data->dis->xvstep = INFINITY;
    data->dis->yvstep = INFINITY;
}

void first_hori_intersect(t_cube *data, double angle)
{
    data->dis->Ahy = floor(data->py / TILE) * TILE;
    if (LOOKDOWN(angle))
        data->dis->Ahy += TILE; // we did this if it looking down because the y incrementing downward
    data->dis->Ahx = data->px + ((data->dis->Ahy - data->py) / tan(angle));

    data->dis->xhstep = TILE / tan(angle);
    data->dis->yhstep = TILE;
    if (LOOKUP(angle)) // if looking UP y must be decremented
        data->dis->yhstep = -data->dis->yhstep;
    if (LEFT(angle))
        data->dis->xhstep = -fabs(data->dis->xhstep); // if looking LEFT x must be decremented
    else
        data->dis->xhstep = fabs(data->dis->xhstep); // if looking RIGHT x must be incremented
    data->dis->HwallHitX = data->dis->Ahx;
    data->dis->HwallHitY = data->dis->Ahy;
    if (LOOKUP(angle))
        data->dis->HwallHitY--;
}

void first_vert_intersect(t_cube *data, double angle)
{
    data->dis->Avx = floor(data->px / TILE) * TILE;
    if (RIGHT(angle))
        data->dis->Avx += TILE;
    data->dis->Avy = data->py + (data->dis->Avx - data->px) * tan(angle);

    data->dis->xvstep = TILE;
    data->dis->yvstep = TILE * tan(angle);
    if (LEFT(angle)) // if looking LEFT x must be decremented
        data->dis->xvstep = -data->dis->xvstep;
    if (LOOKUP(angle))
        data->dis->yvstep = -fabs(data->dis->yvstep); // if looking UP y must be decremented
    else
        data->dis->yvstep = fabs(data->dis->yvstep); // if looking DOWN y must be incremeted
    data->dis->VwallHitX = data->dis->Avx;
    data->dis->VwallHitY = data->dis->Avy;
    if (LEFT(angle))
        data->dis->VwallHitX--;
}

void find_distance(t_cube *data, double angle)
{
    angle = normalizeAngle(angle);

    if (fabs(sin(angle)) < 1e-6) // if the grid line vertical
        horizontal_gridline(data);
    else
        first_hori_intersect(data, angle);
    if (fabs(cos(angle)) < 1e-6) // if the grid line horizontal
        vertical_gridline(data);
    else
        first_vert_intersect(data, angle);
    wall_hit_cords(data);
    data->WallDis = distance(data);
}