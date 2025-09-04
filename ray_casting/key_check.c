/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 10:13:00 by imeftah-          #+#    #+#             */
/*   Updated: 2025/09/04 09:57:52 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	up_down(t_cube *data, double *x, double *y)
{
	if (data->key.up == TRUE)
	{
		*(x) += (MOVE * cos(data->angle));
		*(y) += (MOVE * sin(data->angle));
	}
	if (data->key.down == TRUE)
	{
		*(x) -= (MOVE * cos(data->angle));
		*(y) -= (MOVE * sin(data->angle));
	}
}

void	left_right(t_cube *data, double *x, double *y)
{
	if (data->key.left == TRUE)
	{
		*(x) += sin(data->angle) * MOVE;
		*(y) -= cos(data->angle) * MOVE;
	}
	if (data->key.right == TRUE)
	{
		*(x) -= sin(data->angle) * MOVE;
		*(y) += cos(data->angle) * MOVE;
	}
}

void	check_keys(t_cube *data, double *x, double *y)
{
	if (data->key.rotate_right == TRUE)
		data->angle += data->r_speed;
	if (data->key.rotate_left == TRUE)
		data->angle -= data->r_speed;
	left_right(data, x, y);
	up_down(data, x, y);
}

int	key_check(void *ptr)
{
	double	x;
	double	y;
	double	angle;
	t_cube	*data;

	data = (t_cube *)ptr;
	x = data->px;
	y = data->py;
	angle = data->angle;
	check_keys(data, &x, &y);
	if (data->px == x && data->py == y && angle == data->angle)
		return (0);
	if (colision(data, x, y) != -1)
	{
		data->px = x;
		data->py = y;
	}
	data->angle = normalizeangle(data->angle);
	render_all(data);
	return (0);
}
