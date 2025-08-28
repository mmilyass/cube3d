#include "../cube.h"

double normalizeAngle(double angle)
{
    angle = fmod(angle, 2 * M_PI); // floating-point remainder
    if (angle < 0)
        angle += 2 * M_PI;
    return angle;
}


double distance(t_cube *data)
{
    double h_dis;
    double v_dis;

    h_dis = sqrt((data->dis->HwallHitX - data->px) * (data->dis->HwallHitX - data->px) + (data->dis->HwallHitY - data->py) * (data->dis->HwallHitY - data->py));
    v_dis = sqrt((data->dis->VwallHitX - data->px) * (data->dis->VwallHitX - data->px) + (data->dis->VwallHitY - data->py) * (data->dis->VwallHitY - data->py));
    if (h_dis < v_dis)
        return (h_dis);
    else
        return (v_dis);
}

void wall_hit_cords(t_cube *data)
{
    while (data->dis->HwallHitX >= 0 &&
           data->dis->HwallHitX <= data->width * TILE &&
           data->dis->HwallHitY >= 0 &&
           data->dis->HwallHitY <= data->height * TILE)
    {
        if (check_colision(data, data->dis->HwallHitX, data->dis->HwallHitY) == -1)
            break;
        data->dis->HwallHitX += data->dis->xhstep;
        data->dis->HwallHitY += data->dis->yhstep;
    }
    while (data->dis->VwallHitX >= 0 &&
           data->dis->VwallHitX <= data->width * TILE &&
           data->dis->VwallHitY >= 0 &&
           data->dis->VwallHitY <= data->height * TILE)
    {
        if (check_colision(data, data->dis->VwallHitX, data->dis->VwallHitY) == -1)
            break;
        data->dis->VwallHitX += data->dis->xvstep;
        data->dis->VwallHitY += data->dis->yvstep;
    }
}
