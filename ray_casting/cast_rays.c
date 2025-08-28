#include "../cube.h"

void wallStripHeight(t_cube *data, double angle)
{
    double pp_dis;
    double correctedDistance;

    find_distance(data, angle);
    correctedDistance = data->WallDis * cos(angle - data->angle);
    pp_dis = ((data->width * TILE) / 2) / tan(data->fov / 2);
    data->WallStripH = (TILE / correctedDistance) * pp_dis;
}
