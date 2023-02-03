/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:19:55 by segurbuz          #+#    #+#             */
/*   Updated: 2023/02/03 13:19:56 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	find_nl(char *s1)
{
	int	i;

	i = 0;
	if (!s1)
		return (0);
	while (s1[i++])
		if (s1[i] == '\n')
			return (1);
	return (0);
}

char	*new_buffer(char *buffer)
{
	char	*new_buffer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free (buffer);
		return (NULL);
	}
	new_buffer = malloc (sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!new_buffer)
		return (NULL);
	i++;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = 0;
	free (buffer);
	return (new_buffer);
}

char	*copy(char *s1, char *s2)
{
	char	*str;
	int i;
	int x;
	int nl;

	nl = find_nl(s2);
	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1 + nl));
	i = -1;
	x = 0;
	while(s1[++i])
		str[i] = s1[i];
	while(s2[x] && s2[x] != '\n')
		str[i++] = s2[x++];
	if (s2[x] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	free (s1);
	return (str);
}
