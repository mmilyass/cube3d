/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboussel <oboussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 10:05:03 by oboussel          #+#    #+#             */
/*   Updated: 2025/09/02 15:24:50 by oboussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

static char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	if (!dst || !src)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}


char	*ft_strtrim(char *str)
{
	int		i;
	int		len;
	char	*trimmed;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] && str[i] == ' ')
		i++;
	len = ft_strlen(str + i);
	trimmed = ft_malloc(len + 1, ALLOC);
	if (trimmed == NULL)
		return (NULL);
	ft_strcpy(trimmed, str + i);
	return (trimmed);
}

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	if (!dst || !src)
		return (NULL);
	i = 0;
	while (src[i] && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
