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
	else if(rule == 0)
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
	int	byte;

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

	char		*print;
	static char *buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer = linex(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	print = get_new_line(buffer);
	buffer = get_new_buffer(buffer);
	return (print);

}




/*int main()
{
	int fd = open("semih.txt", O_RDONLY);
 	int i = 0;
 	while(i++ < 20)
		printf("%s", get_next_line(fd));
}*/



