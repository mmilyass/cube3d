/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 10:23:46 by imeftah-          #+#    #+#             */
/*   Updated: 2025/09/02 11:57:04 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	index_tex(t_cube *data, double angle)
{
	if (lookup(angle) && data->hit_check == HORZ)
		return (0);
	else if (lookdown(angle) && data->hit_check == HORZ)
		return (1);
	else if (right(angle) && data->hit_check == VERT)
		return (2);
	else
		return (3);
}

void	get_texture_info(t_cube *data, double angle)
{
	int	index;

	index = index_tex(data, angle);
	if (data->hit_check == HORZ)
		data->t_text.tex_x = (int)data->dis->hwallhitx % TILE
			* (data->t_text.height[index] / TILE);
	if (data->hit_check == VERT)
		data->t_text.tex_x = (int)data->dis->vwallhity % TILE
			* (data->t_text.height[index] / TILE);
	data->t_text.index = index;
}

unsigned int	get_color(t_cube *data, int index, int tex_x, int tex_y)
{
	char	*color;

	if (tex_x < 0 || tex_x > data->t_text.width[index] || tex_y < 0
		|| tex_y > data->t_text.height[index])
		return (0);
	color = data->t_text.addr[index] + (tex_y * data->t_text.len[index]) + tex_x
		* (data->t_text.bpp[index] / 8);
	return (*(unsigned int *)color);
}
