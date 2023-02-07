/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 00:52:05 by segurbuz          #+#    #+#             */
/*   Updated: 2023/02/07 00:52:07 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_new_buffer(char *buffer)
{
	char	*new_buffer;
	int		i;
	int		j;

	i = strlen_plus(buffer, 0);
	j = 0;
	if (!buffer[i])
	{
		free (buffer);
		return (NULL);
	}
	new_buffer = malloc (sizeof(char) * (strlen_plus(buffer, 1) - i + 1));
	if (!new_buffer)
		return (NULL);
	i += 1;
	copy_next(&new_buffer[j], &buffer[i]);
	free (buffer);
	return (new_buffer);
}

char	*copy(char *s1, char *s2)
{
	char	*ptr;
	size_t	i;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	ptr = malloc(strlen_plus(s1, 1) + strlen_plus(s2, 1) + 1);
	if (!s1 || !s2 || !ptr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	copy_next(ptr + i, s2);
	free (s1);
	return (ptr);
}

char	*copy_next(char *dst, char *src)
{
	size_t	i;

	i = -1;
	if ((strlen_plus(src, 1) + 1) != 0)
	{
		while (src[++i] && i < ((strlen_plus(src, 1) + 1) - 1))
			dst[i] = src[i];
		dst[i] = '\0';
	}
	return (dst);
}

char	*get_new_line(char *buffer)
{
	char	*line;
	int		i;
	int		nl;

	nl = strlen_plus(buffer, 2);
	i = 0;
	if (!buffer[i])
		return (NULL);
	line = malloc(sizeof(char) * (strlen_plus(buffer, 0) + nl + 1));
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}
