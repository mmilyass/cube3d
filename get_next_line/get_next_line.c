/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:39:19 by imeftah-          #+#    #+#             */
/*   Updated: 2024/11/26 11:47:00 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcpy(str + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (str);
}

static ssize_t	fill_holder(int fd, char **holder)
{
	char	*temp;
	char	*ggg;
	ssize_t	b_read;

	b_read = 1;
	while (b_read > 0)
	{
		temp = malloc(BUFFER_SIZE + 1);
		if (!temp)
			return (-1);
		b_read = read(fd, temp, BUFFER_SIZE);
		if (b_read < 0)
			return (free(temp), -1);
		temp[b_read] = '\0';
		ggg = ft_strjoin(*holder, temp);
		if (!ggg)
			return (free(temp), -1);
		free(*holder);
		*holder = ggg;
		free(temp);
		if (ft_strchr(*holder, '\n') != -1)
			break ;
	}
	return (b_read);
}

static char	*get_line(char *holder)
{
	char	*line;
	int		i;

	i = 0;
	while (holder[i] != '\n' && holder[i])
		i++;
	if (holder[i] == '\n')
		i++;
	line = ft_substr(holder, 0, i);
	return (line);
}

static char	*rest(char *holder)
{
	char	*rest;
	int		i;
	int		len;

	i = 0;
	while (holder[i] != '\n' && holder[i] != '\0')
		i++;
	if (holder[i] == '\n')
		i++;
	len = ft_strlen(holder) - i;
	if (len <= 0)
	{
		free(holder);
		return (NULL);
	}
	rest = ft_substr(holder, i, len);
	free(holder);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*holder;
	char		*line;
	ssize_t		b_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	b_read = fill_holder(fd, &holder);
	if (b_read < 0 || !holder || holder[0] == '\0')
	{
		free(holder);
		return (holder = NULL);
	}
	line = get_line(holder);
	if (!line)
	{
		free(holder);
		return (holder = NULL);
	}
	holder = rest(holder);
	return (line);
}
