/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WallDis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 10:14:06 by imeftah-          #+#    #+#             */
/*   Updated: 2025/09/04 10:09:07 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	first_hori_intersect(t_cube *data, double angle)
{
	data->dis->ahy = floor(data->py / TILE) * TILE;
	if (lookdown(angle))
		data->dis->ahy += TILE;
	// we did this if it looking down because the y incrementing downward
	data->dis->ahx = data->px + ((data->dis->ahy - data->py) / tan(angle));
	data->dis->xhstep = TILE / tan(angle);
	data->dis->yhstep = TILE;
	if (lookup(angle)) // if looking UP y must be decremented
		data->dis->yhstep = -data->dis->yhstep;
	if (left(angle))
		data->dis->xhstep = -fabs(data->dis->xhstep);
	// if looking LEFT x must be decremented
	else
		data->dis->xhstep = fabs(data->dis->xhstep);
	// if looking RIGHT x must be incremented
	data->dis->hwallhitx = data->dis->ahx;
	data->dis->hwallhity = data->dis->ahy;
	if (lookup(angle))
		data->dis->hwallhity--;
}

void	first_vert_intersect(t_cube *data, double angle)
{
	data->dis->avx = floor(data->px / TILE) * TILE;
	if (right(angle))
		data->dis->avx += TILE;
	data->dis->avy = data->py + (data->dis->avx - data->px) * tan(angle);
	data->dis->xvstep = TILE;
	data->dis->yvstep = TILE * tan(angle);
	if (left(angle)) // if looking LEFT x must be decremented
		data->dis->xvstep = -data->dis->xvstep;
	if (lookup(angle))
		data->dis->yvstep = -fabs(data->dis->yvstep);
	// if looking UP y must be decremented
	else
		data->dis->yvstep = fabs(data->dis->yvstep);
	// if looking DOWN y must be incremeted
	data->dis->vwallhitx = data->dis->avx;
	data->dis->vwallhity = data->dis->avy;
	if (left(angle))
		data->dis->vwallhitx--;
}

void	find_distance(t_cube *data, double angle)
{
	first_hori_intersect(data, angle);
	first_vert_intersect(data, angle);
	wall_hit_cords(data);
	data->walldis = distance(data);
}

void	wallstripheight(t_cube *data, double angle)
{
	double	pp_dis;
	double	correcteddistance;

	find_distance(data, angle);
	correcteddistance = data->walldis * cos(angle - data->angle);
	pp_dis = ((WIN_WIDTH) / 2) / tan(data->fov / 2);
	data->wallstriph = (TILE / correcteddistance) * pp_dis;
}
