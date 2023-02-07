/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <segurbuz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:43:49 by segurbuz          #+#    #+#             */
/*   Updated: 2023/02/06 13:46:47 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	strlen_plus(const char *buff, int rule)
{
	size_t	i;

	i = 0;
	if (!buff)
		return (0);
	if (rule == 1)
	{
		while (buff[i])
			i++;
	}
	else if (rule == 0)
	{
		while (buff[i] && buff[i] != '\n')
			i++;
	}
	else if (rule == 2)
	{
		while (buff[i++])
			if (buff[i] == '\n')
				return (1);
		i = 0;
	}
	return (i);
}

char	*linex(int fd, char *buffer)
{
	char	*buff;
	int		byte;

	byte = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!strlen_plus(buffer, 2) && byte != 0)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte < 0)
		{
			free(buffer);
			free(buff);
			return (NULL);
		}
		buff[byte] = '\0';
		buffer = copy(buffer, buff);
	}
	free(buff);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char			*print;
	static char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer = linex(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	print = read_line(buffer);
	buffer = get_new_buffer(buffer);
	return (print);
}
