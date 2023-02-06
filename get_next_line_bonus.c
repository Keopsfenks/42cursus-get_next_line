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

#include "get_next_line_bonus.h"

size_t	strlen_plus(char *buff, int rule)
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
	return (i);
}

int	find_nl(char *buffer)
{
	int	i;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i++])
		if (buffer[i] == '\n')
			return (1);
	return (0);
}

char	*linex(int fd, char *buffer)
{
	char	*buff;
	int		byte;

	byte = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!find_nl(buffer) && byte != 0)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte == -1)
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
	print = get_new_line(buffer[fd]);
	buffer[fd] = get_new_buffer(buffer[fd]);
	return (print);
}

#include <stdio.h>
#include <fcntl.h>
int main()
{
	int fd1 = open("ft_txt", O_RDONLY);
	int fd2 = open("got_txt", O_RDONLY);

	int a = 0;
	char *str;
	char *s;
	while ((str = get_next_line(fd1)) && (s = get_next_line(fd2)))
	{
		printf("%d %s", a, str);
		printf("%d %s", a, s);
		a++;
		free(str);
	}
	return (0);
}
