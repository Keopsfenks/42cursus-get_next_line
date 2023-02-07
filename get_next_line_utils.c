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

char	*read_line(char	*str)
{
	size_t	i;
	char	*result;

	if (!*str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	result = ft_substr(str, 0, i + 1);
	if (str[i] == '\n')
		result[i++] = '\n';
	result[i] = '\0';
	return (result);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*result;

	if (!s)
		return (0);
	if (strlen_plus(s, 1) < len)
		len = strlen_plus(s, 1);
	result = malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = 0;
	return (result);
}
