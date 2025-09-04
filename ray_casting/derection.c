/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   derection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:28:20 by imeftah-          #+#    #+#             */
/*   Updated: 2025/09/04 09:35:58 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	lookup(double angle)
{
	return ((angle > M_PI));
}

int	lookdown(double angle)
{
	return (angle < M_PI);
}

int	right(double angle)
{
	return ((angle < 0.5 * M_PI) || (angle > 1.5 * M_PI));
}

int	left(double angle)
{
	return ((angle > 0.5 * M_PI) && (angle < 1.5 * M_PI));
}
