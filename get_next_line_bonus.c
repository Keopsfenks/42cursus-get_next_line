/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 02:36:38 by segurbuz          #+#    #+#             */
/*   Updated: 2023/02/07 02:36:39 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char		*buffer[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer[fd]);
		return (NULL);
	}
	buffer[fd] = linex(fd, buffer[fd]);
	if (buffer[fd] == NULL)
		return (NULL);
	print = read_line(buffer[fd]);
	buffer[fd] = get_new_buffer(buffer[fd]);
	return (print);
}
