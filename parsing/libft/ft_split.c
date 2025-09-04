/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboussel <oboussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 10:02:32 by oboussel          #+#    #+#             */
/*   Updated: 2025/09/02 15:28:22 by oboussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

static int	count_word(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (count);
}

static char	*ft_copy(char const *s, char c)
{
	size_t	len;
	char	*array;
	size_t	i;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	array = malloc((len + 1) * sizeof(char));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		array[i] = s[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

void	free_split(char **array, size_t j)
{
	while (j > 0)
	{
		j--;
		free(array[j]);
	}
	free(array);
}

char	**ft_split(char const *s, char c)
{
	size_t	j;
	char	**array;

	if (s == NULL)
		return (NULL);
	j = 0;
	array = malloc((count_word(s, c) + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != c && *s != '\0')
		{
			array[j] = ft_copy(s, c);
			if (array[j++] == NULL)
				return (free_split(array, j - 1), NULL);
			while (*s != c && *s != '\0')
				s++;
		}
	}
	array[j] = NULL;
	return (array);
}

void	free_double_ptr(char **split)
{
	int	i;

	i = 0;
	if (split == NULL)
		return;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
}
